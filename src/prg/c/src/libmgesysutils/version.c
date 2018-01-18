/**
 * @file lib/src/prg/c/src/libmgesysutils/version.c
 *
 * Standard versioning.
 *
 * Standard library-wide software versioning functions and information.
 *
 * @author Copyright (C) 2015-2018  Mark Grant
 *
 * Released under the GPLv3 only.\n
 * SPDX-License-Identifier: GPL-3.0
 *
 * @version _v1.0.7 ==== 02/01/2018_
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
 * 04/05/2017	MG	1.0.4	Migrate to use mge_errno.		*
 *				Improve getaddrinfo processing.		*
 *				Change to send errors to syslog, not	*
 *				stderr.					*
 *				Update to standards from atclstv	*
 *				template v1.0.0				*
 * 07/11/2017	MG	1.0.5	Add Doxygen comments.			*
 * 10/11/2017	MG	1.0.6	Add SPDX license tags.			*
 * 02/01/2018	MG	1.0.7	Move to new source directory structure.	*
 *									*
 ************************************************************************
 */


#include <stdio.h>
#include <stdlib.h>
#include <libmgesysutils.h>
#include <config.h>

/** The source code version. */
#define SOURCE_VERSION "1.0.7"

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

