/**
 * @file src/prg/c/inc/libmgesysutils/mge-configfile.h
 *
 * Config file processing header file.
 *
 * Header file for config file processing in the libmgesysutils shared library.
 *
 * @author Copyright (C) 2015-2019, 2021-2023  Mark Grant
 *
 * Released under the GPLv3 only.\n
 * SPDX-License-Identifier: GPL-3.0-only
 *
 * @version _v1.2.1 ==== 25/11/2023_
 */

#ifndef MGE_CONFIGFILE_H
#define MGE_CONFIGFILE_H

#include <libmgec/mge-portability.h>

BEGIN_C_DECLS

/** Max length of Key and value. */
#define MAX_KEYVAL_LENGTH 1000

/** Max number of keys per section. */
#define MAX_KEYS_PER_SECTION 1000

/** Max length of line. */
#define MAX_LINE_LENGTH 1000

/** Configuration Key / Value Pair */
struct confkey {
	const char *key;	       /**< Key part of pair. */
	int mandatory;		       /**< Mandatory, 1 = true, 0 = false. */
	int present;		       /**< Pair present, 1 = true, 0 =false.*/
	char value[MAX_KEYVAL_LENGTH]; /**< Value part of pair. */
};

/** Configuration section definition. */
struct confsection {
	const char *section; /**< Section name. */
	int mandatory;	     /**< Mandatory, 1 = true, 0 = false. */
	int present;	     /**< Pair present, 1 = true, 0 =false.*/
	struct confkey keys[MAX_KEYS_PER_SECTION]; /**< Array of KV Pairs*/
};

int parsefile(struct confsection *params, int nparams, char *filename);

END_C_DECLS

#endif /* ndef MGE_CONFIGFILE_H */
