#! /usr/bin/env bash
#########################################################################
#									#
# Script ID: lib/source/progs/c/src/libmgesysutils/Makefile.am		#
# Author: Copyright (C) 2015-2018  Mark Grant				#
#									#
# Released under the GPLv3 only.					#
# SPDX-License-Identifier: GPL-3.0					#
#									#
# Purpose:								#
#	AutoMake script file to generate libmgesysutils library from	#
# source.								#
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
# 03/02/2017	MG	1.0.4	Add libmgec linking for mge_errno.	#
# 23/04/2017	MG	1.0.5	Add temporary header directory.		#
# 09/06/2017	MG	1.0.6	Add temporary library support.		#
# 18/10/2017	MG	1.0.7	Change to use _LIBADD for temporary	#
#				libraries as passing -L and the temp	#
#				directory does not necessarily leave	#
#				LD_LIBRARY_PATH in the correct order.	#
#				Re-order into logical steps.		#
# 01/01/2018	MG	1.0.8	Add SPDX license tags to source files.	#
# 02/01/2018	MG	1.0.9	Add include directory from dev pacakge.	#
# 02/01/2018	MG	1.0.10	Move to new source directory structure.	#
# 05/01/2018	MG	1.0.11	Correct use of config.h - add the	#
#				header directory to AM_CPPFLAGS.	#
#									#
#########################################################################


AM_CPPFLAGS = -I$(srcdir)/../../inc-tmp -I$(srcdir)/../../inc
AM_CPPFLAGS += -I$(top_srcdir)/../dev/source/progs/c/inc
AM_CPPFLAGS += -I../../sysgen/inc -I../../sysgen/lib


AM_CFLAGS = -Wall
AM_CFLAGS += $(LIBMGEC_CFLAGS)

if DEBUG
AM_CFLAGS += -g -Og
else
AM_CFLAGS += -O2
endif


lib_LTLIBRARIES = libmgesysutils.la

libmgesysutils_la_SOURCES = configfile/configfile.c remsyslog/remsyslog.c
libmgesysutils_la_SOURCES += version.c

AM_LDFLAGS = -version-info 0:0:0 $(LIBMGEC_LIBS)
libmgesysutils_la_LIBADD = $(tmplibraries)
