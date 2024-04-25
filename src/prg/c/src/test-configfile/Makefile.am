#########################################################################
#									#
# Author: Copyright (C) 2015-2019, 2021-2024  Mark Grant		#
#									#
# Released under the GPLv3 only.					#
# SPDX-License-Identifier: GPL-3.0-only					#
#									#
# Purpose:								#
#	AutoMake script file to generate configfile test program.	#
#									#
#########################################################################


fix-configfiletest.sh: Makefile
	mkdir -p $(@D)
	rm -f $@ $@.tmp
	test -f ./$@.in || srcdir=$(srcdir)/; \
	$(edit) $${srcdir}$(@F).in > $@.tmp
	mv $@.tmp $@
	chmod a+x $@
fix-configfiletest.sh: $(srcdir)/fix-configfiletest.sh.in

check_SCRIPTS = fix-configfiletest.sh


if DEBUG
AM_CPPFLAGS = $(MG_DEBUG_CPPFLAGS)
else
AM_CPPFLAGS = $(MG_CPPFLAGS)
endif
AM_CPPFLAGS += -I$(srcdir)/../../inc-tmp -I$(srcdir)/../../inc
AM_CPPFLAGS += -I../../gen/inc -I../../gen/lib


if DEBUG
AM_CFLAGS = $(MG_DEBUG_CFLAGS)
else
AM_CFLAGS = $(MG_CFLAGS)
endif


check_PROGRAMS = configfiletest
configfiletest_SOURCES = main.c


AM_LDFLAGS = $(MG_LDFLAGS)
AM_LDFLAGS += $(LIBMGEC_LIBS)


LDADD = $(tmplibraries)
LDADD += ../libmgesysutils/libmgesysutils.la


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
	$(srcdir)/nostartatsection.conf.in \
	$(srcdir)/fix-configfiletest.sh.in

CLEANFILES = *.tmp *.conf fix-configfiletest.sh

