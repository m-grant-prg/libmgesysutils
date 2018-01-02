/**
 * @file dev/source/progs/c/inc/libmgesysutils/libmgesysutils.h
 *
 * Header file for libmgesysutils shared library.
 *
 * @author Copyright (C) 2015-2018  Mark Grant
 *
 * Released under the GPLv3 only.\n
 * SPDX-License-Identifier: GPL-3.0
 *
 * @version _v1.0.4 ==== 02/01/2018_
 */

/* **********************************************************************
 *									*
 * Changelog								*
 *									*
 * Date		Author	Version	Description				*
 *									*
 * 12/07/2015	MG	1.0.1	First release.				*
 * 07/11/2017	MG	1.0.2	Add Doxygen comments.			*
 * 10/11/2017	MG	1.0.3	Add SPDX license tag.			*
 * 02/01/2018	MG	1.0.4	Move to new source directory structure.	*
 *									*
 ************************************************************************
 */


#ifndef LIBMGESYSUTILS_H
#define LIBMGESYSUTILS_H


#include <portability.h>

BEGIN_C_DECLS

char *libmgesysutils_get_pkg_version(void);

char *libmgesysutils_get_src_version(void);

void libmgesysutils_print_pkg_version(void);

void libmgesysutils_print_src_version(void);

END_C_DECLS

#endif /* ndef LIBMGESYSUTILS_H */
