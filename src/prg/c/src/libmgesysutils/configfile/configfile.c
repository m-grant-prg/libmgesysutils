/**
 * @file lib/src/prg/c/src/libmgesysutils/configfile/configfile.c
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
 * 04/05/2017	MG	1.0.4	Introduce mge_errno usage.		*
 *				Change to send errors to syslog, not	*
 *				stderr.					*
 *				Update to standards from atclstv	*
 *				template v1.0.0				*
 * 07/11/2017	MG	1.0.5	Add Doxygen comments.			*
 * 10/11/2017	MG	1.0.6	Add SPDX license tag.			*
 * 02/01/2018	MG	1.0.7	Move to new source directory structure.	*
 *									*
 ************************************************************************
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <syslog.h>

#include <mge-errno.h>
#include <configfile.h>

static char line[MAX_LINE_LENGTH];
static char currentsection[MAX_KEYVAL_LENGTH];
static struct confsection *pcursect;

/* Static prototypes. */
static char *getparamline(char *, FILE *);
static int parseline(struct confsection *, int, char *);
static int parsesection(struct confsection *, int, char *);
static int validatesection(struct confsection *, int, char *);
static int parseparam(char *);
static int isolatekey(char *, char *, char *);
static int isolatevalue(char *, char *, char *);
static int validatekeyvalue(char *, char *);
static int chkmandatories(struct confsection *, int);
static int chkkeys(struct confsection *);
static int chkfileerr(FILE *);

/**
 * Parse a configuration file.
 * On error mge_errno is set.
 * @param params Pointer to a struct confsection array of parameters.
 * @param nparams The number of parameters.
 * @param filename The config filename.
 * @return 0 for success, non-zero for failure.
 */
int parsefile(struct confsection *params, int nparams, char *filename)
{
	char *pl = line;
	FILE *fp;
	mge_errno = 0;

	/* open file */
	fp = fopen(filename, "r");
	if (fp == NULL) {
		sav_errno = errno;
		mge_errno = MGE_ERRNO;
		syslog((int) (LOG_USER | LOG_NOTICE), "%m %s", filename);
		return mge_errno;
	}

	/* Process file. */
	while (((pl = getparamline(pl, fp)) != NULL) && !mge_errno) {
		mge_errno = parseline(params, nparams, pl);
	}
	/* Check it was EOF, not a real file error. */
	if (pl == NULL && !mge_errno)
		mge_errno = chkfileerr(fp);
	/* All OK to here, then check mandatory requirements. */
	if (!mge_errno)
		mge_errno = chkmandatories(params, nparams);
	/* Close the file and exit. */
	if (fclose(fp))
		mge_errno = chkfileerr(fp);
	return mge_errno;
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
	mge_errno = 0;

	while (*pline && isspace(*pline))
		pline++;

	if (*pline == '[')
		mge_errno = parsesection(params, nparams, pline);
	else if (!currentsection[0]) {
		mge_errno = MGE_CONFIG_PARSE;
		syslog((int) (LOG_USER | LOG_NOTICE), "First non-blank, "
			"non-empty, non-comment line must be a section.");
	} else
		mge_errno = parseparam(pline);
	return mge_errno;
}

/*
 * Parse a Section line.
 */
static int parsesection(struct confsection *params, int nparams, char *pline)
{
	mge_errno = 0;
	char s[MAX_KEYVAL_LENGTH] = { '\0' };

	if (strchr(pline, ']') != NULL) {
		if ((strchr(pline, ']') - strchr(pline, '[')) > 1) {
			if (strlen(pline) < MAX_KEYVAL_LENGTH) {
				strncpy(s, strchr(pline, '[') + 1,
					(int) (strchr(pline, ']') -
						strchr(pline, '[') - 1));
				mge_errno = validatesection(params, nparams, s);
			} else {
				syslog((int) (LOG_USER | LOG_NOTICE),
					"Section name longer than %d.",
					MAX_KEYVAL_LENGTH);
				mge_errno = MGE_CONFIG_PARSE;
			}
		} else {
			syslog((int) (LOG_USER | LOG_NOTICE), "Section heading "
				"must not be empty.");
			mge_errno = MGE_CONFIG_PARSE;
		}
	} else {
		syslog((int) (LOG_USER | LOG_NOTICE), "Section heading %s has "
			"no closing ].", pline);
		mge_errno = MGE_CONFIG_PARSE;
	}
	return mge_errno;
}

/*
 * Validate Section and update confsection struct.
 */
static int validatesection(struct confsection *params, int nparams,
				char *section)
{
	mge_errno = MGE_CONFIG_PARSE;
	int s = 1;

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
	if (mge_errno)
		syslog((int) (LOG_USER | LOG_NOTICE), "Section %s is "
			"invalid.", section);
	return mge_errno;
}

/*
 * Parse a Key / Value pair line.
 */
static int parseparam(char *pline)
{
	mge_errno = 0;
	/* Initialise to enable use of strncpy. */
	char paramkey[MAX_KEYVAL_LENGTH] = { '\0' };
	char paramvalue[MAX_KEYVAL_LENGTH] = { '\0' };
	char *endkey = strchr(pline, '=');
	char *startval = strchr(pline, '=') + 1;
	char *endval = strchr(pline, '\n');

	if ((endkey != NULL) && (endval != NULL)) {
		if (endkey - pline) {
			if (strlen(pline) < MAX_KEYVAL_LENGTH) {
				mge_errno = isolatekey(pline, endkey, paramkey);
				if (!mge_errno)
					mge_errno = isolatevalue(startval,
							endval, paramvalue);
				if (!mge_errno)
					mge_errno = validatekeyvalue(paramkey,
								paramvalue);
			} else {
				mge_errno = MGE_CONFIG_PARSE;
				syslog((int) (LOG_USER | LOG_NOTICE),
					"Parameter line longer than %d.",
					MAX_KEYVAL_LENGTH);
			}
		} else {
			mge_errno = MGE_CONFIG_PARSE;
			syslog((int) (LOG_USER | LOG_NOTICE), "Key name cannot "
				"be empty.");
		}
	} else {
		mge_errno = MGE_CONFIG_PARSE;
		if (endkey == NULL)
			syslog((int) (LOG_USER | LOG_NOTICE), "Parameter must "
				"contain =.");
		else
			syslog((int) (LOG_USER | LOG_NOTICE), "Parameter line "
				"must be terminated by newline character.");
	}
	return mge_errno;
}

/*
 * Extract Key string.
 */
static int isolatekey(char *pline, char *endkey, char *key)
{
	mge_errno = 0;

	if ((endkey - pline) < MAX_KEYVAL_LENGTH) {
		do {
			endkey--;
		} while (isspace(*endkey) && (endkey - pline));
		strncpy(key, pline, endkey - pline + 1);
	} else {
		mge_errno = MGE_CONFIG_PARSE;
		syslog((int) (LOG_USER | LOG_NOTICE), "Key name longer than "
			"%d.", MAX_KEYVAL_LENGTH);
	}
	return mge_errno;
}

/*
 * Extract Value string.
 */
static int isolatevalue(char *startvalue, char *endvalue, char *value)
{
	mge_errno = 0;

	if ((endvalue - startvalue) < MAX_KEYVAL_LENGTH) {
		while (isspace(*startvalue) && (endvalue - startvalue))
			startvalue++;
		while ((isspace(*endvalue) || *endvalue == '\n')
			&& (endvalue - startvalue))
			endvalue--;
		if (*startvalue != '\n')
			strncpy(value, startvalue, (endvalue - startvalue + 1));
	} else {
		mge_errno = MGE_CONFIG_PARSE;
		syslog((int) (LOG_USER | LOG_NOTICE), "Value longer than %d.",
			MAX_KEYVAL_LENGTH);
	}
	return mge_errno;
}

/*
 * Validate Key and update confsection struct.
 */
static int validatekeyvalue(char *key, char *value)
{
	mge_errno = MGE_CONFIG_PARSE;
	int s = 1;
	int x = 0;

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
	if (mge_errno)
		syslog((int) (LOG_USER | LOG_NOTICE), "Key %s is invalid.",
			key);
	return mge_errno;
}

/*
 * Check Section and Key mandatory requirements.
 */
static int chkmandatories(struct confsection *params, int nparams)
{
	mge_errno = 0;
	int s = 1;

	while (s && !mge_errno) {
		if (params->present) {
			mge_errno = chkkeys(params);
		} else {
			if (params->mandatory) {
				mge_errno = MGE_CONFIG_PARSE;
				s = 0;
				syslog((int) (LOG_USER | LOG_NOTICE), "Section "
					"%s is mandatory.\n", params->section);
			}
		}
		if (!(--nparams))
			s = 0;
		else
			params++;
	}
	return mge_errno;
}

/*
 * Check Key mandatory requirements.
 */
static int chkkeys(struct confsection *section)
{
	mge_errno = 0;
	int s = 1;
	int x = 0;

	while (s && (x < MAX_KEYS_PER_SECTION)) {
		if (section->keys[x].key) {
			if (section->keys[x].mandatory) {
				if (!section->keys[x].present) {
					mge_errno = MGE_CONFIG_PARSE;
					s = 0;
					syslog((int) (LOG_USER | LOG_NOTICE),
						"Key %s in section %s is "
						"mandatory.",
						section->keys[x].key,
						section->section);
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
	return mge_errno;
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
		syslog((int) (LOG_USER | LOG_NOTICE), "%s",
			mge_strerror(mge_errno));
	}
	return mge_errno;
}
