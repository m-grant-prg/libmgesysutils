#########################################################################
#									#
# Script ID: src/prg/c/src/test-remsyslog/Makefile.am			#
# Author: Copyright (C) 2015-2019, 2021  Mark Grant			#
#									#
# Released under the GPLv3 only.					#
# SPDX-License-Identifier: GPL-3.0-only					#
#									#
# Purpose:								#
#	AutoMake script file to generate remsyslog test program.	#
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
# 18/10/2017	MG	1.0.4	Change to use _LDADD for temporary	#
#				libraries as passing -L and the temp	#
#				directory does not necessarily leave	#
#				LD_LIBRARY_PATH in the correct order.	#
#				Re-order into logical steps.		#
# 01/01/2018	MG	1.0.5	Add SPDX license tags to source files.	#
# 02/01/2018	MG	1.0.6	Move to new source directory structure.	#
# 05/01/2018	MG	1.0.7	Correct use of config.h - add the	#
#				header directory to AM_CPPFLAGS.	#
# 07/07/2018	MG	1.0.8	Improve debug flags used. Use gdb	#
#				orientated level 3 (includes		#
#				pre-processor macros).			#
# 16/05/2019	MG	1.0.9	Collapse AT sub-projects into one.	#
#				Remove shebang.				#
# 30/10/2019	MG	1.0.10	Move under check target.		#
# 08/10/2021	MG	1.0.11	Use CFLAGS from configure.		#
#				Use CPPFLAGS from configure.		#
#				Use LDFLAGS from configure.		#
# 15/10/2021	MG	1.0.12	Change debug optimisation to -O0	#
# 05/11/2021	MG	1.0.13	Use (non-)debug CPPFLAGS from configure	#
#				Use (non-)debug CFLAGS from configure	#
# 06/12/2021	MG	1.0.14	Tighten SPDX tag.			#
#									#
#########################################################################


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


LDADD = ../libmgesysutils/libmgesysutils.la
LDADD += $(tmplibraries)

