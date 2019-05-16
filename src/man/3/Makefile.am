#! /usr/bin/env bash
#########################################################################
#									#
# Script ID: src/man/3/Makefile.am					#
# Author: Copyright (C) 2015-2019  Mark Grant				#
#									#
# Released under the GPLv3 only.					#
# SPDX-License-Identifier: GPL-3.0					#
#									#
# Purpose:								#
#	AutoMake script file to generate libmgesysutils manual pages	#
# from source.								#
#									#
#########################################################################

#########################################################################
#									#
# Changelog								#
#									#
# Date		Author	Version	Description				#
#									#
# 12/07/2015	MG	1.0.1	Started versioning of this script.	#
# 22/09/2015	MG	1.0.2	Convert to use txt2manwrap.		#
# 25/10/2015	MG	1.0.3	Restructure and change to conform to	#
#				AutoTools General Template v1.0.6.	#
# 23/04/2017	MG	1.0.4	Correct $(edit) output was being	#
#				ignored.				#
#				Rename source file extensions .man.in	#
# 01/01/2018	MG	1.0.5	Add SPDX license tags to source files.	#
#				Determine the manual section from the	#
#				target suffix. If the suffix is blank	#
#				(foo.) or if there is no suffix (foo)	#
#				then error out.				#
# 02/01/2018	MG	1.0.6	Move to new source directory structure.	#
# 23/05/2018	MG	1.0.7	Consolidated into this dir, 1 level up.	#
# 16/05/2019	MG	1.0.8	Collapse AT sub-projects into one.	#
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

