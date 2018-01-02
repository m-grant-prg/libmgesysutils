/**
 * @file dev/source/progs/c/inc/remsyslog/remsyslog.h
 *
 * Send message to remote syslog header file.
 *
 * Header file for sending a message to a remote syslog server in the
 * libmgesysutils shared library.
 *
 * @author Copyright (C) 2015-2018  Mark Grant
 *
 * Released under the GPLv3 only.\n
 * SPDX-License-Identifier: GPL-3.0
 *
 * @version _v1.0.6 ==== 02/01/2018_
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
 * 07/11/2017	MG	1.0.4	Add Doxygen comments.			*
 * 10/11/2017	MG	1.0.5	Add SPDX license tag.			*
 * 02/01/2018	MG	1.0.6	Move to new source directory structure.	*
 *									*
 ************************************************************************
 */


#ifndef REMSYSLOG_H
#define REMSYSLOG_H


#include <portability.h>

BEGIN_C_DECLS

int sndremsyslogmsg(const char *hostname, const char *prog_name,
			const char *message);

END_C_DECLS

#endif /* ndef REMSYSLOG_H */
