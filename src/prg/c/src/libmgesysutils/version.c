/**
 * @file src/prg/c/src/libmgesysutils/version.c
 *
 * Standard versioning.
 *
 * Standard library-wide software versioning functions and information.
 *
 * @author Copyright (C) 2015-2019, 2021-2023  Mark Grant
 *
 * Released under the GPLv3 only.\n
 * SPDX-License-Identifier: GPL-3.0-only
 *
 * @version _v1.1.1 ==== 24/11/2023_
 */

#include <config.h>
#include <stdio.h>

#include <libmgesysutils/libmgesysutils.h>

/**
 * Get the git-describe based package version.
 * @return The package version string.
 */
__attribute__((const)) const char *libmgesysutils_get_pkg_version(void)
{
	return PACKAGE_VERSION;
}

/**
 * Get the source version.
 * @return The source version string.
 */
__attribute__((const)) const char *libmgesysutils_get_src_version(void)
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
