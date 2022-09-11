/* **********************************************************************
 *									*
 * Source: main.c							*
 * Author: Mark Grant							*
 *									*
 * Purpose:								*
 *	Test program for configfile in libmgesysutils shared library.	*
 *									*
 * Released under the GPLv3 only.					*
 * SPDX-License-Identifier: GPL-3.0-only				*
 *									*
 ************************************************************************
 */

#include <config.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <libmgesysutils.h>
#include <mge-configfile.h>
#include <mge-errno.h>

/*
 * configfile test program.
 */
int main(void)
{
	/*
	 * Odd {} duplication below prevents odd missing braces compiler
	 * 	warnings.
	 */
	struct confsection sections[]
		= { { "General", 0, 0, { { "pollint", 0, 0, "" } } },
		    { "Full",
		      0,
		      0,
		      { { "Server", 0, 0, "" }, { "DayOfWeek", 1, 0, "" } } },
		    { "Incremental",
		      0,
		      0,
		      { { "Server", 0, 0, "" }, { "DayOfWeek", 0, 0, "" } } },
		    { "Output",
		      1,
		      0,
		      { { "Verbose", 1, 0, "" }, { "Bold", 0, 0, "" } } } };
	struct confsection *psections = sections;
	int nsections = (int)(sizeof sections / sizeof sections[0]);

	int i, x;

	int parserror = 0;
	char filename[1000];
	char choice[10] = { '\0' };
	char *pchoice = choice;

	/* Print Params allowed struct pre-parse */
	printf("Params allowed - pre-parse.\n");
	for (i = 0; i < nsections; i++) {
		printf("Section: %s\tMandatory: %d\n", psections->section,
		       psections->mandatory);
		for (x = 0; x < (int)(sizeof psections->keys
				      / sizeof psections->keys[0]);
		     x++) {
			if (psections->keys[x].key)
				printf("\tKey: %s\tMandatory: %d\n",
				       psections->keys[x].key,
				       psections->keys[x].mandatory);
		}
		psections++;
	}

	psections = sections;

	parserror = 0;

	printf("Choose one of :-\n");
	printf("a) No closing ] in section heading test.\n");
	printf("b) No = sign in parameter test.\n");
	printf("c) Missing mandatory section.\n");
	printf("d) Missing manadatory key.\n");
	printf("e) Missing newline at end of parameter line.\n");
	printf("f) Invalid section.\n");
	printf("g) Invalid Key.\n");
	printf("h) Works completely.\n");
	printf("i) Does not start at a section.\n");
	printf("j) No such conf file.\n\n");

	printf("[Choice]: ");
	i = scanf("%1s", choice);

	switch (*pchoice) {
	case 'a':
		strcpy(filename, "noclosingbracket.conf");
		break;
	case 'b':
		strcpy(filename, "noequalssign.conf");
		break;
	case 'c':
		strcpy(filename, "nomandatorysection.conf");
		break;
	case 'd':
		strcpy(filename, "nomandatorykey.conf");
		break;
	case 'e':
		strcpy(filename, "nonewline.conf");
		break;
	case 'f':
		strcpy(filename, "nosuchsection.conf");
		break;
	case 'g':
		strcpy(filename, "nosuchkey.conf");
		break;
	case 'h':
		strcpy(filename, "thisworks.conf");
		break;
	case 'i':
		strcpy(filename, "nostartatsection.conf");
		break;
	case 'j':
		strcpy(filename, "missing-file.conf");
		break;
	default:
		parserror = 1;
		printf("Invalid selection.\n");
		break;
	}

	if (!parserror) {
		printf("Using config file: %s", filename);
		parserror = parsefile(psections, nsections, filename);
	}

	/* Print Params allowed struct post-parse */
	printf("\n\nParams allowed - post-parse.\n");
	for (i = 0; i < nsections; i++) {
		printf("Section: %s\tPresent: %d\n", psections->section,
		       psections->present);
		for (x = 0; x < (int)(sizeof psections->keys
				      / sizeof psections->keys[0]);
		     x++) {
			if (psections->keys[x].key)
				printf("\tKey: %s\tPresent: %d\tValue: %s\n",
				       psections->keys[x].key,
				       psections->keys[x].present,
				       psections->keys[x].value);
		}
		psections++;
	}

	fprintf(stderr, "%s\n", mge_strerror(mge_errno));

	libmgesysutils_print_pkg_version();
	libmgesysutils_print_src_version();

	return (parserror);
}
