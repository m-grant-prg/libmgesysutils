#! /usr/bin/env bash
#########################################################################
#									#
# Script ID: dev/Makefile.am						#
# Author: Copyright (C) 2015-2018  Mark Grant				#
#									#
# Released under the GPLv3 only.					#
# SPDX-License-Identifier: GPL-3.0					#
#									#
# Purpose:								#
#	AutoMake script file to generate libmgesysutils-dev project	#
# from source.								#
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
# 01/01/2018	MG	1.0.3	Add SPDX license tags to source files.	#
# 02/01/2018	MG	1.0.4	Move to new source directory structure.	#
# 14/04/2018	MG	1.0.5	Add srctarball target to build a source	#
#				tarball in the build directory. Uses	#
#				git archive to archive HEAD.		#
# 23/05/2018	MG	1.0.6	Simplify man directory structure.	#
# 07/06/2018	MG	1.0.7	Add info messages to srctarball target.	#
# 23/10/2018	MG	1.0.8	Change srctarball target to build with	#
#				src between package name and version in	#
#				filename.				#
#									#
#########################################################################


ACLOCAL_AMFLAGS = -I m4


SUBDIRS = src/man/3
SUBDIRS += src/prg/c/inc src/prg/c/src


srctarball:
	@cwd="$${PWD}" && \
	targ="$${cwd}/@PACKAGE_TARNAME@-src-@PACKAGE_VERSION@.tar.gz" && \
	cd @srcdir@ && \
	echo "making srctarball from @srcdir@" && \
	echo "GA	$${targ}" && \
	git archive --format=tar.gz \
		--prefix=@PACKAGE_TARNAME@-@PACKAGE_VERSION@/ \
		--output=$${targ} \
		HEAD && \
	cd -

