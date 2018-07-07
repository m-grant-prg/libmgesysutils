/**
 * @file lib/src/prg/c/src/libmgesysutils/configfile/internal.h
 *
 * Externally non-visible prototypes etc..
 *
 * No distribution required.
 *
 * @author Copyright (C) 2018  Mark Grant
 *
 * Released under the GPLv3 only.\n
 * SPDX-License-Identifier: GPL-3.0
 *
 * @version _v1.0.1 ==== 13/05/2018_
 */

/* **********************************************************************
 *									*
 * Changelog								*
 *									*
 * Date		Author	Version	Description				*
 *									*
 * 13/05/2018	MG	1.0.1	Started ChangeLog.			*
 *									*
 ************************************************************************
 */


#include <portability.h>


BEGIN_C_DECLS


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


END_C_DECLS