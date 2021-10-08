#########################################################################
#									#
# Script ID: src/prg/c/src/libmgesysutils/Makefile.am			#
# Author: Copyright (C) 2015-2019, 2021  Mark Grant			#
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
# 26/03/2018	MG	1.0.12	Add support for sparse.			#
# 21/06/2018	MG	1.0.13	Disable sparse variable length array	#
#				warnings.				#
#				Use lib_version_info AC_SUBST variable	#
#				passed via AC_CONFIG_FILES to enable	#
#				all top level versioning to be done in	#
#				configure.ac				#
# 07/07/2018	MG	1.0.14	Improve debug flags used. Use gdb	#
#				orientated level 3 (includes		#
#				pre-processor macros).			#
# 11/08/2018	MG	1.0.15	Support configure time otion to add -H	#
#				compiler flag to show included files	#
#				and their depth in the include stack.	#
#				Use compiler version dependent CFLAGS	#
#				assembled in configure.			#
# 16/05/2019	MG	1.0.16	Collapse AT subprojects into one.	#
#				Remove shebang.				#
# 08/10/2021	MG	1.0.17	Use MG_CFLAGS variable.			#
#				Use CPPFLAGS prepared by configure.	#
#				Use LDFLAGS prepared by configure.	#
#									#
#########################################################################


AM_CPPFLAGS = $(MG_CPPFLAGS)
AM_CPPFLAGS += -I$(srcdir)/../../inc-tmp -I$(srcdir)/../../inc
AM_CPPFLAGS += -I../../gen/inc -I../../gen/lib


AM_CFLAGS = $(MG_CFLAGS)
AM_CFLAGS += $(LIBMGEC_CFLAGS)
if DEBUG
AM_CFLAGS += -ggdb3 -Og
else
AM_CFLAGS += -O2
endif
if HEADERCHECK
AM_CFLAGS += -H
endif
if SPARSE
AM_CFLAGS += -Wsparse-all -Wno-vla
endif


noinst_HEADERS = configfile/internal.h


lib_LTLIBRARIES = libmgesysutils.la


libmgesysutils_la_SOURCES = configfile/configfile.c remsyslog/remsyslog.c
libmgesysutils_la_SOURCES += version.c


AM_LDFLAGS = $(MG_LDFLAGS)
AM_LDFLAGS += -version-info @lib_version_info@ $(LIBMGEC_LIBS)


libmgesysutils_la_LIBADD = $(tmplibraries)

