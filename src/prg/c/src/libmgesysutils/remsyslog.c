/**
 * @file src/prg/c/src/libmgesysutils/remsyslog.c
 *
 * To send a message to a remote syslog server using UDP.
 *
 * @author Copyright (C) 2015-2019, 2021-2023  Mark Grant
 *
 * Released under the GPLv3 only.\n
 * SPDX-License-Identifier: GPL-3.0-only
 *
 * @version _v1.1.0 ==== 04/11/2023_
 */

#include <errno.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <syslog.h>
#include <unistd.h>

#include <libmgec/libmgec.h>
#include <libmgec/mge-errno.h>
#include <libmgesysutils/mge-remsyslog.h>

/**
 * Send message to remote syslog server.
 * On error mge_errno will be set.
 * @param hostname Destination machine.
 * @param prog_name Source program name.
 * @param message The message to send.
 * @return 0 on success, -ve mge_errno on error.
 */
int sndremsyslogmsg(const char *hostname, const char *prog_name,
		    const char *message)
{
	char clientid[100] = { '\0' };
	int c;
	char fullmessage[ARRAY_SIZE(clientid) + strlen(" ") + strlen(prog_name)
			 + strlen(": ") + strlen(message) + 1];
	const char *portname = "syslog";
	struct addrinfo hints;
	struct addrinfo *res = NULL;
	struct addrinfo *rai;
	int fd = 0;
	ssize_t s;

	/* Get hostname. */
	mge_errno = gethostname(clientid, sizeof(clientid));
	if (mge_errno) {
		sav_errno = errno;
		mge_errno = MGE_ERRNO;
		syslog((int)(LOG_USER | LOG_NOTICE),
		       "Error retrieving hostname. %m");
		return -mge_errno;
	}
	/* Prepend client & program names to message to build full message. */
	strcpy(fullmessage, clientid);
	strcat(fullmessage, " ");
	strcat(fullmessage, prog_name);
	strcat(fullmessage, ": ");
	strcat(fullmessage, message);

	/* PF_ prefix described as "TCP/IP", AF_ prefix as "Internet". */
	memset(&hints, 0, sizeof(struct addrinfo));
	hints.ai_family = PF_UNSPEC;	 /* Allow IPv4 or IPv6 */
	hints.ai_socktype = SOCK_DGRAM;	 /* Constrains to UDP */
	hints.ai_protocol = IPPROTO_UDP; /* Only UDP protocol */
	hints.ai_canonname = NULL;
	hints.ai_flags = AI_ADDRCONFIG;
	hints.ai_addr = NULL;
	hints.ai_next = NULL;

	mge_errno = getaddrinfo(hostname, portname, &hints, &res);
	if (mge_errno) {
		sav_errno = mge_errno;
		mge_errno = MGE_GAI;
		syslog((int)(LOG_USER | LOG_NOTICE), "%s",
		       mge_strerror(mge_errno));
		return -mge_errno;
	}

	for (rai = res; res != NULL; res = res->ai_next) {
		fd = socket(rai->ai_family, rai->ai_socktype, rai->ai_protocol);
		if (fd > 0)
			break;
	}

	if (rai == NULL)
		goto err_exit;

	/* Send the datagram. */
	s = sendto(fd, fullmessage, strlen(fullmessage), 0, res->ai_addr,
		   res->ai_addrlen);
	if (s == -1)
		goto err_exit;

	/* Close socket file descriptor. */
	c = close(fd);
	if (c == -1)
		goto err_exit;

	freeaddrinfo(res);
	return 0;

err_exit:
	sav_errno = errno;
	mge_errno = MGE_ERRNO;
	perror("");
	freeaddrinfo(res);
	return -mge_errno;
}
