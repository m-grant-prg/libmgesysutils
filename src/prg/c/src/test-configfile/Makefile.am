#########################################################################
#									#
# Script ID: src/prg/c/src/test-configfile/Makefile.am			#
# Author: Copyright (C) 2015-2019  Mark Grant				#
#									#
# Released under the GPLv3 only.					#
# SPDX-License-Identifier: GPL-3.0					#
#									#
# Purpose:								#
#	AutoMake script file to generate configfile test program.	#
#									#
#########################################################################

#########################################################################
#									#
# Changelog								#
#									#
# Date		Author	Version	Description				#
#									#
# 12/07/2015	MG	1.0.1	First release.				#
# 25/10/2015	MG	1.0.2	Restructure and change to conform to	#
#				AutoTools General Template v1.0.6.	#
# 13/01/2017	MG	1.0.3	Set debug or normal compile flags here.	#
# 03/02/2017	MG	1.0.4	Add libmgec LDFLAGS for mge_errno.	#
# 07/02/2017	MG	1.0.5	Add nostartatsection.conf test file.	#
# 18/10/2017	MG	1.0.6	Change to use _LDADD for temporary	#
#				libraries as passing -L and the temp	#
#				directory does not necessarily leave	#
#				LD_LIBRARY_PATH in the correct order.	#
#				Re-order into logical steps.		#
# 01/01/2018	MG	1.0.7	Add SPDX license tags to source files.	#
# 02/01/2018	MG	1.0.8	Move to new source directory structure.	#
# 05/01/2018	MG	1.0.9	Correct use of config.h - add the	#
#				header directory to AM_CPPFLAGS.	#
# 07/07/2018	MG	1.0.10	Improve debug flags used. Use gdb	#
#				orientated level 3 (includes		#
#				pre-processor macros).			#
# 16/05/2019	MG	1.0.11	Collapse AT sub-projects into one.	#
#				Remove shebang.				#
# 30/10/2019	MG	1.0.12	Move under check target.		#
#									#
#########################################################################


AM_CPPFLAGS = -I$(srcdir)/../../inc-tmp -I$(srcdir)/../../inc
AM_CPPFLAGS += -I../../gen/inc -I../../gen/lib


AM_CFLAGS = -Wall

if DEBUG
AM_CFLAGS += -ggdb3 -Og
else
AM_CFLAGS += -O2
endif


check_PROGRAMS = configfiletest
configfiletest_SOURCES = main.c


LDADD = ../libmgesysutils/libmgesysutils.la
LDADD += $(tmplibraries)


noclosingbracket.conf noequalssign.conf nomandatorykey.conf nonewline.conf \
	nosuchkey.conf nosuchsection.conf thisworks.conf \
	nomandatorysection.conf nostartatsection.conf: Makefile
	mkdir -p $(@D)
	rm -f $@ $@.tmp
	test -f ./$@.in || srcdir=$(srcdir)/; \
	$(edit) $${srcdir}$(@F).in >$@.tmp
	mv $@.tmp $@

noclosingbracket.conf: $(srcdir)/noclosingbracket.conf.in
noequalssign.conf: $(srcdir)/noequalssign.conf.in
nomandatorykey.conf: $(srcdir)/nomandatorykey.conf.in
nonewline.conf: $(srcdir)/nonewline.conf.in
nosuchkey.conf: $(srcdir)/nosuchkey.conf.in
nosuchsection.conf: $(srcdir)/nosuchsection.conf.in
thisworks.conf: $(srcdir)/thisworks.conf.in
nomandatorysection.conf: $(srcdir)/nomandatorysection.conf.in
nostartatsection.conf: $(srcdir)/nostartatsection.conf.in

check_DATA = noclosingbracket.conf noequalssign.conf nomandatorykey.conf \
	nonewline.conf nosuchkey.conf nosuchsection.conf thisworks.conf \
	nomandatorysection.conf nostartatsection.conf

EXTRA_DIST = $(srcdir)/noclosingbracket.conf.in $(srcdir)/noequalssign.conf.in \
	$(srcdir)/nomandatorykey.conf.in $(srcdir)/nonewline.conf.in \
	$(srcdir)/nosuchkey.conf.in $(srcdir)/nosuchsection.conf.in \
	$(srcdir)/thisworks.conf.in $(srcdir)/nomandatorysection.conf.in \
	$(srcdir)/nostartatsection.conf.in

CLEANFILES = *.tmp *.conf

