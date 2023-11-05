/**
 * @file src/prg/c/inc/libmgesysutils/libmgesysutils.h
 *
 * Header file for libmgesysutils shared library.
 *
 * @author Copyright (C) 2015-2019, 2021-2023  Mark Grant
 *
 * Released under the GPLv3 only.\n
 * SPDX-License-Identifier: GPL-3.0-only
 *
 * @version _v1.1.0 ==== 04/11/2023_
 */

#ifndef LIBMGESYSUTILS_H
#define LIBMGESYSUTILS_H

#include <libmgec/mge-portability.h>

BEGIN_C_DECLS

char *libmgesysutils_get_pkg_version(void);

char *libmgesysutils_get_src_version(void);

void libmgesysutils_print_pkg_version(void);

void libmgesysutils_print_src_version(void);

END_C_DECLS

#endif /* ndef LIBMGESYSUTILS_H */
