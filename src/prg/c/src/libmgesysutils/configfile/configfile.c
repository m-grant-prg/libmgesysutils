/**
 * @file src/prg/c/src/libmgesysutils/configfile/configfile.c
 *
 * Configuration file processing.
 *
 * configfile library source to process configuration files consisting of
 * sections and parameters of key / value pairs.
 *
 * Whitespace lines and empty lines are ignored.
 *
 * Lines with a '#' as the first non-whitespace character are ignored as comment
 * lines.
 *
 * The first parameter line must be a section header.
 *
 * Section headers are enclosed in [], [ must be the first non-whitespace
 * character on the line and anything after the first ] is ignored.
 *
 * All other lines are assumed to be parameter lines and after any initial
 * whitespace characters they must have a parameter name, optional whitespace, a
 * mandatory '=', optional whitespace and finishing with an optional word of
 * characters and / or numbers.\n
 * e.g.
 *
 * > \# Section General\n
 * > [General]\n
 * > \# pollint is the polling interval in seconds.\n
 * > pollint=5		<== This is legal.\n
 * > large pollint=5	<== This is legal.\n
 * > pollint =		<== This is legal.\n
 * > pollint		<== This is illegal.\n
 *
 * If a parameter is repeated then the last occurrence prevails.
 *
 * An array of struct confsection's is provided by the library user to specify
 * valid parameters and whether they are mandatory. A mandatory	Key / Value pair
 * for an optional Section is only enforced if the Section does appear, (is
 * defined), in the config file.
 *
 * @author Copyright (C) 2015-2019  Mark Grant
 *
 * Released under the GPLv3 only.\n
 * SPDX-License-Identifier: GPL-3.0
 *
 * @version _v1.0.12 ==== 30/10/2019_
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
 * 04/05/2017	MG	1.0.4	Introduce mge_errno usage.		*
 *				Change to send errors to syslog, not	*
 *				stderr.					*
 *				Update to standards from atclstv	*
 *				template v1.0.0				*
 * 07/11/2017	MG	1.0.5	Add Doxygen comments.			*
 * 10/11/2017	MG	1.0.6	Add SPDX license tag.			*
 * 02/01/2018	MG	1.0.7	Move to new source directory structure.	*
 * 27/03/2018	MG	1.0.8	Ensure variable declarations preceed	*
 *				code, (fixes sparse warnings).		*
 * 13/05/2018	MG	1.0.9	Extract prototype declarations to	*
 *				internal.h				*
 *				Return -ve error number on failure.	*
 * 16/05/2019	MG	1.0.10	Collapse AT sub-projects into one.	*
 * 31/05/2019	MG	1.0.11	Add or correct casts of size argument	*
 *				to strncpy.				*
 * 30/10/2019	MG	1.0.12	Apply clang-format.			*
 *									*
 ************************************************************************
 */

#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <syslog.h>

#include <configfile.h>

#include "internal.h"
#include <mge-errno.h>

static char line[MAX_LINE_LENGTH];
static char currentsection[MAX_KEYVAL_LENGTH];
static struct confsection *pcursect;

/**
 * Parse a configuration file.
 * On error mge_errno is set.
 * @param params Pointer to a struct confsection array of parameters.
 * @param nparams The number of parameters.
 * @param filename The config filename.
 * @return 0 for success, -mge_errno on failure.
 */
int parsefile(struct confsection *params, int nparams, char *filename)
{
	char *pl = line;
	FILE *fp;
	int ret = 0;
	mge_errno = 0;

	/* open file */
	fp = fopen(filename, "r");
	if (fp == NULL) {
		sav_errno = errno;
		mge_errno = MGE_ERRNO;
		syslog((int)(LOG_USER | LOG_NOTICE), "%m %s", filename);
		return -mge_errno;
	}

	/* Process file. */
	while (((pl = getparamline(pl, fp)) != NULL) && !ret) {
		ret = parseline(params, nparams, pl);
	}
	/* Check it was EOF, not a real file error. */
	if (pl == NULL && !ret)
		ret = chkfileerr(fp);
	/* All OK to here, then check mandatory requirements. */
	if (!ret)
		ret = chkmandatories(params, nparams);
	/* Close the file and exit. */
	if (fclose(fp))
		ret = chkfileerr(fp);
	return ret;
}

/*
 * Get next non-blank line, (ignoring any leading whitespace),
 * which is not a comment.
 */
static char *getparamline(char *pline, FILE *stream)
{
	char *c;

	pline = fgets(pline, MAX_LINE_LENGTH, stream);
	c = pline;

	if (c != NULL) {
		while (*c && isspace(*c))
			c++;

		if (!*c || (*c == '#'))
			pline = getparamline(pline, stream);
	}
	return pline;
}

/*
 * Determine line type. First processible line must be a section.
 */
static int parseline(struct confsection *params, int nparams, char *pline)
{
	int ret = 0;
	mge_errno = 0;

	while (*pline && isspace(*pline))
		pline++;

	if (*pline == '[') {
		ret = parsesection(params, nparams, pline);
	} else {
		if (!currentsection[0]) {
			mge_errno = MGE_CONFIG_PARSE;
			ret = -mge_errno;
			syslog((int)(LOG_USER | LOG_NOTICE),
			       "First non-blank,"
			       " non-empty, non-comment line must be a "
			       "section.");
		} else {
			ret = parseparam(pline);
		}
	}
	return ret;
}

/*
 * Parse a Section line.
 */
static int parsesection(struct confsection *params, int nparams, char *pline)
{
	char s[MAX_KEYVAL_LENGTH] = { '\0' };
	int ret;

	mge_errno = 0;

	if (strchr(pline, ']') != NULL) {
		if ((strchr(pline, ']') - strchr(pline, '[')) > 1) {
			if (strlen(pline) < MAX_KEYVAL_LENGTH) {
				strncpy(s, strchr(pline, '[') + 1,
					(size_t)(strchr(pline, ']')
						 - strchr(pline, '[') - 1));
				ret = validatesection(params, nparams, s);
			} else {
				syslog((int)(LOG_USER | LOG_NOTICE),
				       "Section name longer than %d.",
				       MAX_KEYVAL_LENGTH);
				mge_errno = MGE_CONFIG_PARSE;
				ret = -mge_errno;
			}
		} else {
			syslog((int)(LOG_USER | LOG_NOTICE),
			       "Section heading "
			       "must not be empty.");
			mge_errno = MGE_CONFIG_PARSE;
			ret = -mge_errno;
		}
	} else {
		syslog((int)(LOG_USER | LOG_NOTICE),
		       "Section heading %s has "
		       "no closing ].",
		       pline);
		mge_errno = MGE_CONFIG_PARSE;
		ret = -mge_errno;
	}
	return ret;
}

/*
 * Validate Section and update confsection struct.
 */
static int validatesection(struct confsection *params, int nparams,
			   char *section)
{
	int ret = 0;
	int s = 1;

	mge_errno = MGE_CONFIG_PARSE;

	while (s) {
		if (!strcmp(params->section, section)) {
			mge_errno = s = 0;
			params->present = 1;
			strcpy(currentsection, section);
			pcursect = params;
		}
		if (!(--nparams))
			s = 0;
		else
			params++;
	}
	if (mge_errno) {
		syslog((int)(LOG_USER | LOG_NOTICE),
		       "Section %s is "
		       "invalid.",
		       section);
		ret = -mge_errno;
	}
	return ret;
}

/*
 * Parse a Key / Value pair line.
 */
static int parseparam(char *pline)
{
	/* Initialise to enable use of strncpy. */
	char paramkey[MAX_KEYVAL_LENGTH] = { '\0' };
	char paramvalue[MAX_KEYVAL_LENGTH] = { '\0' };
	char *endkey = strchr(pline, '=');
	char *startval = strchr(pline, '=') + 1;
	char *endval = strchr(pline, '\n');
	int ret = 0;

	mge_errno = 0;

	if ((endkey != NULL) && (endval != NULL)) {
		if (endkey - pline) {
			if (strlen(pline) < MAX_KEYVAL_LENGTH) {
				ret = isolatekey(pline, endkey, paramkey);
				if (!ret)
					ret = isolatevalue(startval, endval,
							   paramvalue);
				if (!ret)
					ret = validatekeyvalue(paramkey,
							       paramvalue);
			} else {
				mge_errno = MGE_CONFIG_PARSE;
				syslog((int)(LOG_USER | LOG_NOTICE),
				       "Parameter line longer than %d.",
				       MAX_KEYVAL_LENGTH);
				ret = -mge_errno;
			}
		} else {
			mge_errno = MGE_CONFIG_PARSE;
			syslog((int)(LOG_USER | LOG_NOTICE), "Key name cannot "
							     "be empty.");
			ret = -mge_errno;
		}
	} else {
		mge_errno = MGE_CONFIG_PARSE;
		if (endkey == NULL)
			syslog((int)(LOG_USER | LOG_NOTICE), "Parameter must "
							     "contain =.");
		else
			syslog((int)(LOG_USER | LOG_NOTICE),
			       "Parameter line "
			       "must be terminated by newline character.");
		ret = -mge_errno;
	}
	return ret;
}

/*
 * Extract Key string.
 */
static int isolatekey(char *pline, char *endkey, char *key)
{
	int ret = 0;
	mge_errno = 0;

	if ((endkey - pline) < MAX_KEYVAL_LENGTH) {
		do {
			endkey--;
		} while (isspace(*endkey) && (endkey - pline));
		strncpy(key, pline, (size_t)(endkey - pline + 1));
	} else {
		mge_errno = MGE_CONFIG_PARSE;
		syslog((int)(LOG_USER | LOG_NOTICE),
		       "Key name longer than "
		       "%d.",
		       MAX_KEYVAL_LENGTH);
		ret = -mge_errno;
	}
	return ret;
}

/*
 * Extract Value string.
 */
static int isolatevalue(char *startvalue, char *endvalue, char *value)
{
	int ret = 0;
	mge_errno = 0;

	if ((endvalue - startvalue) < MAX_KEYVAL_LENGTH) {
		while (isspace(*startvalue) && (endvalue - startvalue))
			startvalue++;
		while ((isspace(*endvalue) || *endvalue == '\n')
		       && (endvalue - startvalue))
			endvalue--;
		if (*startvalue != '\n')
			strncpy(value, startvalue,
				(size_t)(endvalue - startvalue + 1));
	} else {
		mge_errno = MGE_CONFIG_PARSE;
		syslog((int)(LOG_USER | LOG_NOTICE), "Value longer than %d.",
		       MAX_KEYVAL_LENGTH);
		ret = -mge_errno;
	}
	return ret;
}

/*
 * Validate Key and update confsection struct.
 */
static int validatekeyvalue(char *key, char *value)
{
	int ret = 0;
	int s = 1;
	int x = 0;

	mge_errno = MGE_CONFIG_PARSE;

	while (s && (x < MAX_KEYS_PER_SECTION)) {
		if (pcursect->keys[x].key) {
			if (!strcmp(pcursect->keys[x].key, key)) {
				mge_errno = s = 0;
				pcursect->keys[x].present = 1;
				strcpy(pcursect->keys[x].value, value);
			} else {
				x++;
			}
		} else {
			s = 0;
		}
	}
	if (mge_errno) {
		syslog((int)(LOG_USER | LOG_NOTICE), "Key %s is invalid.", key);
		ret = -mge_errno;
	}
	return ret;
}

/*
 * Check Section and Key mandatory requirements.
 */
static int chkmandatories(struct confsection *params, int nparams)
{
	int ret = 0;
	int s = 1;

	mge_errno = 0;

	while (s && !mge_errno) {
		if (params->present) {
			ret = chkkeys(params);
		} else {
			if (params->mandatory) {
				mge_errno = MGE_CONFIG_PARSE;
				s = 0;
				syslog((int)(LOG_USER | LOG_NOTICE),
				       "Section "
				       "%s is mandatory.\n",
				       params->section);
				ret = -mge_errno;
			}
		}
		if (!(--nparams))
			s = 0;
		else
			params++;
	}
	return ret;
}

/*
 * Check Key mandatory requirements.
 */
static int chkkeys(struct confsection *section)
{
	int ret = 0;
	int s = 1;
	int x = 0;

	mge_errno = 0;

	while (s && (x < MAX_KEYS_PER_SECTION)) {
		if (section->keys[x].key) {
			if (section->keys[x].mandatory) {
				if (!section->keys[x].present) {
					mge_errno = MGE_CONFIG_PARSE;
					s = 0;
					syslog((int)(LOG_USER | LOG_NOTICE),
					       "Key %s in section %s is "
					       "mandatory.",
					       section->keys[x].key,
					       section->section);
					ret = -mge_errno;
				} else {
					x++;
				}
			} else {
				x++;
			}
		} else {
			s = 0;
		}
	}
	return ret;
}

/*
 * Check for file errors.
 */
static int chkfileerr(FILE *fp)
{
	mge_errno = ferror(fp);
	if (mge_errno) {
		sav_errno = mge_errno;
		mge_errno = MGE_ERRNO;
		syslog((int)(LOG_USER | LOG_NOTICE), "%s",
		       mge_strerror(mge_errno));
	}
	return -mge_errno;
}

