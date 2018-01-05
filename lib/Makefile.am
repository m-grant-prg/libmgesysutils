#! /usr/bin/env bash
#########################################################################
#									#
# Script ID: lib/Makefile.am						#
# Author: Copyright (C) 2015-2018  Mark Grant				#
#									#
# Released under the GPLv3 only.					#
# SPDX-License-Identifier: GPL-3.0					#
#									#
# Purpose:								#
#	AutoMake script file to generate libmgesysutils project from	#
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
# 23/04/2017	MG	1.0.3	Add temporary header directory.		#
# 09/06/2017	MG	1.0.4	Add support for temporary libraries.	#
# 01/01/2018	MG	1.0.5	Add SPDX license tags to source files.	#
# 02/01/2018	MG	1.0.6	Move to new source directory structure.	#
# 05/01/2018	MG	1.0.7	Correct use of config.h - remove the	#
#				Makefile.am and processing.		#
#									#
#########################################################################

ACLOCAL_AMFLAGS = -I m4

SUBDIRS = source/progs/c/sysgen/lib
SUBDIRS += source/progs/c/inc-tmp
SUBDIRS += source/progs/c/lib-tmp
SUBDIRS += source/progs/c/src/libmgesysutils
SUBDIRS += source/progs/c/src/test-configfile source/progs/c/src/test-remsyslog

EXTRA_DIST  = m4/gnulib-cache.m4
