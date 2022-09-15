/**
 * @file src/prg/c/src/libmgesysutils/version.c
 *
 * Standard versioning.
 *
 * Standard library-wide software versioning functions and information.
 *
 * @author Copyright (C) 2015-2019, 2021, 2022  Mark Grant
 *
 * Released under the GPLv3 only.\n
 * SPDX-License-Identifier: GPL-3.0-only
 *
 * @version _v1.0.12 ==== 15/09/2022_
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
 * 10/11/2017	MG	1.0.5	Add SPDX license tags.			*
 * 02/01/2018	MG	1.0.6	Move to new source directory structure.	*
 * 04/06/2018	MG	1.0.7	Make this ChangeLog for this file only.	*
 * 21/06/2018	MG	1.0.8	Remove SOURCE_CODE define, now uses the	*
 *				AC_DEFINE'd value in config.h		*
 * 16/05/2019	MG	1.0.9	Collapse AT sub-projects into one.	*
 * 30/10/2019	MG	1.0.10	Apply clang-format.			*
 * 06/12/2021	MG	1.0.11	Tighten SPDX tag.			*
 * 15/09/2022	MG	1.0.12	Remove unnecessary include of stdlib.h	*
 *									*
 ************************************************************************
 */

#include <config.h>
#include <stdio.h>

#include <libmgesysutils.h>

/**
 * Get the git-describe based package version.
 * @return The package version string.
 */
char *libmgesysutils_get_pkg_version(void)
{
	return PACKAGE_VERSION;
}

/**
 * Get the source version.
 * @return The source version string.
 */
char *libmgesysutils_get_src_version(void)
{
	return SOURCE_VERSION;
}

/**
 * Print the package version string to stdout.
 */
void libmgesysutils_print_pkg_version(void)
{
	printf("%s %s %s", "libmgesysutils Package version -", PACKAGE_VERSION,
	       "\n");
}

/**
 * Print the source version string to stdout.
 */
void libmgesysutils_print_src_version(void)
{
	printf("%s %s %s", "libmgesysutils Source version -", SOURCE_VERSION,
	       "\n");
}
