/**
 * @file src/prg/c/inc/libmgesysutils/mge-remsyslog.h
 *
 * Send message to remote syslog header file.
 *
 * Header file for sending a message to a remote syslog server in the
 * libmgesysutils shared library.
 *
 * @author Copyright (C) 2015-2019, 2021-2023  Mark Grant
 *
 * Released under the GPLv3 only.\n
 * SPDX-License-Identifier: GPL-3.0-only
 *
 * @version _v1.1.0 ==== 04/11/2023_
 */

#ifndef MGE_REMSYSLOG_H
#define MGE_REMSYSLOG_H

#include <libmgec/mge-portability.h>

BEGIN_C_DECLS

int sndremsyslogmsg(const char *hostname, const char *prog_name,
		    const char *message);

END_C_DECLS

#endif /* ndef MGE_REMSYSLOG_H */
