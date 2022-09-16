/**
 * @file src/prg/c/inc/libmgesysutils/libmgesysutils.h
 *
 * Header file for libmgesysutils shared library.
 *
 * @author Copyright (C) 2015-2019, 2021, 2022  Mark Grant
 *
 * Released under the GPLv3 only.\n
 * SPDX-License-Identifier: GPL-3.0-only
 *
 * @version _v1.0.8 ==== 15/09/2022_
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
 * 16/05/2019	MG	1.0.5	Collapse AT sub-projects into one.	*
 * 30/10/2019	MG	1.0.6	Apply clang-format.			*
 * 06/12/2021	MG	1.0.7	Tighten SPDX tag.			*
 * 15/09/2022	MG	1.0.8	Rename portability.h			*
 *				Use pkginclude location.		*
 *									*
 ************************************************************************
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
