/**
 * @file dev/src/prg/c/inc/configfile.h
 *
 * Config file processing header file.
 *
 * Header file for config file processing in the libmgesysutils shared library.
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


#ifndef CONFIGFILE_H
#define CONFIGFILE_H


#include <portability.h>

BEGIN_C_DECLS

/** Max length of Key and value. */
#define MAX_KEYVAL_LENGTH 1000

/** Max number of keys per section. */
#define MAX_KEYS_PER_SECTION 1000

/** Max length of line. */
#define MAX_LINE_LENGTH 1000

/** Configuration Key / Value Pair */
struct confkey {
	char *key;			/**< Key part of pair. */
	int mandatory;			/**< Mandatory, 1 = true, 0 = false. */
	int present;			/**< Pair present, 1 = true, 0 =false.*/
	char value[MAX_KEYVAL_LENGTH];	/**< Value part of pair. */
};

/** Configuration section definition. */
struct confsection {
	char *section;			/**< Section name. */
	int mandatory;			/**< Mandatory, 1 = true, 0 = false. */
	int present;			/**< Pair present, 1 = true, 0 =false.*/
	struct confkey keys[MAX_KEYS_PER_SECTION];	/**< Array of KV Pairs*/
};

int parsefile(struct confsection *params, int nparams, char *filename);

END_C_DECLS

#endif /* ndef CONFIGFILE_H */
