/* **********************************************************************
 *									*
 * Source: main.c							*
 * Author: Mark Grant							*
 *									*
 * Purpose:								*
 *	Test program for remsyslog in libmgesysutils shared library.	*
 *									*
 * Released under the GPLv3 only.					*
 * SPDX-License-Identifier: GPL-3.0					*
 *									*
 ************************************************************************
 */

#include <config.h>
#include <stdio.h>
#include <stdlib.h>

#include <mge-errno.h>
#include <remsyslog.h>
#include <libmgesysutils.h>

/*
 * remsyslog test program.
 */
int main(int argc, char** argv)
{
	int prog_error;

	prog_error = sndremsyslogmsg("localhost", argv[0], "Message 100");

	printf("This should work localhost? %s\n", mge_strerror(mge_errno));

	prog_error = sndremsyslogmsg("hermes.mgent.home", argv[0], "Message 200");

	printf("This should work hermes? %s\n", mge_strerror(mge_errno));

	prog_error = sndremsyslogmsg("dummy.mgent.home", argv[0], "Message 300");

	printf("Return value for dummy is %i\n",prog_error);
	printf("This should fail dummy? %s\n", mge_strerror(mge_errno));

	libmgesysutils_print_src_version();
	libmgesysutils_print_pkg_version();

	exit(prog_error);
}
