/**
 * @file src/prg/c/src/libmgesysutils/remsyslog/remsyslog.c
 *
 * To send a message to a remote syslog server using UDP.
 *
 * @author Copyright (C) 2015-2019  Mark Grant
 *
 * Released under the GPLv3 only.\n
 * SPDX-License-Identifier: GPL-3.0
 *
 * @version _v1.0.11 ==== 31/05/2019_
 */

/* **********************************************************************
 *									*
 * Changelog								*
 *									*
 * Date		Author	Version	Description				*
 *									*
 * 12/07/2015	MG	1.0.1	First release.				*
 * 16/07/2016	MG	1.0.2	Move towards kernel coding style.	*
 * 17/07/2016	MG	1.0.3	Further coding style changes.		*
 * 04/05/2017	MG	1.0.4	Migrate sendremsyslog to use mge_errno.	*
 *				Improve getaddrinfo processing.		*
 *				Change to send errors to syslog, not	*
 *				stderr.					*
 *				Update to standards from atclstv	*
 *				template v1.0.0				*
 * 07/11/2017	MG	1.0.5	Add Doxygen comments.			*
 * 10/11/2017	MG	1.0.6	Add SPDX license tag.			*
 * 02/01/2018	MG	1.0.7	Move to new source directory structure.	*
 * 27/03/2018	MG	1.0.8	Initialise NULL pointer with NULL, not	*
 *				zero, (fixes a sparse warning).		*
 * 13/05/2018	MG	1.0.9	On error return -ve mge_errno.		*
 * 16/05/2019	MG	1.0.10	Collapse AT sub-projects into one.	*
 * 31/05/2019	MG	1.0.11	Correct variable type for return	*
 *				assignment from sendto.			*
 *									*
 ************************************************************************
 */


#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <syslog.h>

#include <mge-errno.h>
#include <remsyslog.h>


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
	char fullmessage[strlen(message) + 1 + strlen(clientid) + 1
				+ strlen(prog_name) + 1];
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
		syslog((int) (LOG_USER | LOG_NOTICE),
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
	hints.ai_family = PF_UNSPEC;		/* Allow IPv4 or IPv6 */
	hints.ai_socktype = SOCK_DGRAM;		/* Constrains to UDP */
	hints.ai_protocol = IPPROTO_UDP;	/* Only UDP protocol */
	hints.ai_canonname = NULL;
	hints.ai_flags = AI_ADDRCONFIG;
	hints.ai_addr = NULL;
	hints.ai_next = NULL;

	mge_errno = getaddrinfo(hostname, portname, &hints, &res);
	if (mge_errno) {
		sav_errno = mge_errno;
		mge_errno = MGE_GAI;
		syslog((int) (LOG_USER | LOG_NOTICE), "%s",
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

