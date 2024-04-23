#########################################################################
#									#
# Author: Copyright (C) 2015-2019, 2021-2024  Mark Grant		#
#									#
# Released under the GPLv3 only.					#
# SPDX-License-Identifier: GPL-3.0-only					#
#									#
# Purpose:								#
#	AutoMake script file to generate remsyslog test program.	#
#									#
#########################################################################


fix-remsyslogtest.sh: Makefile
	mkdir -p $(@D)
	rm -f $@ $@.tmp
	test -f ./$@.in || srcdir=$(srcdir)/; \
	$(edit) $${srcdir}$(@F).in > $@.tmp
	mv $@.tmp $@
	chmod a+x $@
fix-remsyslogtest.sh: $(srcdir)/fix-remsyslogtest.sh.in

check_SCRIPTS = fix-remsyslogtest.sh


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


check_PROGRAMS = remsyslogtest
remsyslogtest_SOURCES = main.c


AM_LDFLAGS = $(MG_LDFLAGS)
AM_LDFLAGS += $(LIBMGEC_LIBS)


LDADD = $(tmplibraries)
LDADD += ../libmgesysutils/libmgesysutils.la


EXTRA_DIST = $(srcdir)/fix-remsyslogtest.sh.in

CLEANFILES = *.tmp fix-remsyslogtest.sh

