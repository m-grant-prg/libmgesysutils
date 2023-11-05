#########################################################################
#									#
# Author: Copyright (C) 2015-2019, 2021, 2023  Mark Grant		#
#									#
# Released under the GPLv3 only.					#
# SPDX-License-Identifier: GPL-3.0-only					#
#									#
# Purpose:								#
#	AutoMake script file to generate libmgesysutils manual pages	#
# from source.								#
#									#
#########################################################################


parsefile.3 sndremsyslogmsg.3: Makefile
	mkdir -p $(@D)
	rm -f $@ $@.tmp
	$(edit) $(srcdir)/$(@F).man.in > $@.tmp
	targfile=$(@F);	\
	if [[ $$targfile == *"."* ]]; then \
		if [[ $${targfile##*.} == "" ]]; then \
			echo "Source file suffix used as section but empty."; \
			exit 1; \
		else \
			section=$${targfile##*.}; \
		fi; \
	else \
		echo "Source file suffix used as section but no dot & empty."; \
		exit 1; \
	fi; \
	txt2manwrap $(@F) $$section "MGE System Utilities Library Manual" \
		$@.tmp $@
	rm -f $@.tmp

parsefile.3: $(srcdir)/parsefile.3.man.in
sndremsyslogmsg.3: $(srcdir)/sndremsyslogmsg.3.man.in

man_MANS = parsefile.3 sndremsyslogmsg.3

EXTRA_DIST = $(srcdir)/parsefile.3.man.in $(srcdir)/sndremsyslogmsg.3.man.in

CLEANFILES = *.tmp parsefile.3 sndremsyslogmsg.3

