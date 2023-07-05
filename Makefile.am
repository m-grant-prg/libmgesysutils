#########################################################################
#									#
# Script ID: ./Makefile.am						#
# Author: Copyright (C) 2015-2019, 2021-2023  Mark Grant		#
#									#
# Released under the GPLv3 only.					#
# SPDX-License-Identifier: GPL-3.0-only					#
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
# 20/04/2018	MG	1.0.8	Add srctarball target to build a source	#
#				tarball in the build directory. Uses	#
#				git archive to archive HEAD.		#
# 07/06/2018	MG	1.0.9	Add info messages to srctarball target.	#
# 23/10/2018	MG	1.0.10	Change srctarball target to build with	#
#				src between package name and version in	#
#				filename.				#
# 16/05/2019	MG	1.0.11	Collapse AT sub-projects into one.	#
#				Remove shebang.				#
#				Make source tarball name == GitHub.	#
#				Add install of standard GNU files such	#
#				as AUTHORS etc.				#
#				Add m4extra macro directory.		#
# 29/10/2019	MG	1.0.12	To enable make distcheck to work, any	#
#				hard-coded paths requiring permissions	#
#				such as /etc or fixed locations such as	#
#				/usr/share/java must be accommodated,	#
#				so set the configure flags to be used	#
#				by make distcheck.			#
# 08/10/2021	MG	1.0.13	Add misc and doc/misc to Dist.		#
# 06/12/2021	MG	1.0.14	Tighten SPOX tag.			#
# 20/07/2022	MG	1.0.15	Add doxygen target.			#
# 26/07/2022	MG	1.1.1	Change doc directory to docs to support	#
#				using GitHub Pages to host Doxygen	#
#				documentation.				#
# 09/09/2022	MG	1.1.2	Add test-headers build.			#
#				Add run-tests for make check.		#
# 05/07/2023	MG	1.1.3	Enable use of v1.1.1~rc1 type vesrion	#
#				numbers for source tarballs.		#
#									#
#########################################################################

ACLOCAL_AMFLAGS = -I m4 -I m4extra


AM_DISTCHECK_CONFIGURE_FLAGS = --enable-distcheckfake=yes


SUBDIRS = src/man/3
SUBDIRS += src/prg/c/gen/lib
SUBDIRS += src/prg/c/inc/libmgesysutils
SUBDIRS += src/prg/c/inc-tmp
SUBDIRS += src/prg/c/lib-tmp
SUBDIRS += src/prg/c/pkg-config
SUBDIRS += src/prg/c/src/libmgesysutils
SUBDIRS += src/prg/c/src/test-configfile src/prg/c/src/test-remsyslog
SUBDIRS += src/prg/c/src/test-headers
SUBDIRS += src/prg/c/src/run-tests
SUBDIRS += docs/doxygen


doc_DATA = AUTHORS ChangeLog COPYING NEWS README


EXTRA_DIST = $(srcdir)/AUTHORS $(srcdir)/ChangeLog $(srcdir)/COPYING \
		$(srcdir)/NEWS $(srcdir)/README
EXTRA_DIST += m4/gnulib-cache.m4
EXTRA_DIST += docs/misc misc


srctarball:
	@cwd="$${PWD}" && \
	varg="$$(echo @PACKAGE_VERSION@ | sed -e s/\-rc/\~rc/ )" && \
	targ="$${cwd}/@PACKAGE_TARNAME@-$${varg}.tar.gz" && \
	cd @srcdir@ && \
	echo "making srctarball from @srcdir@" && \
	echo "GA	$${targ}" && \
	git archive --format=tar.gz \
		--prefix=@PACKAGE_TARNAME@-$${varg}/ \
		--output=$${targ} \
		HEAD && \
	cd -


doxygen:
	(cd docs/doxygen && rm -f *.stamp && $(MAKE) $(AM_MAKEFLAGS) $@) \
		|| exit 1

.PHONY: doxygen

