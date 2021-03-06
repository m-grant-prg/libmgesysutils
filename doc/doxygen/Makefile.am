#########################################################################
#									#
# Script ID: doc/doxygen/Makefile.am					#
# Author: Copyright (C) 2017-2020  Mark Grant				#
#									#
# Released under the GPLv3 only.					#
# SPDX-License-Identifier: GPL-3.0					#
#									#
# Purpose:								#
#	AutoMake script file to produce doxygen html documentation.	#
#									#
#########################################################################

#########################################################################
#									#
# Changelog								#
#									#
# Date		Author	Version	Description				#
#									#
# 28/12/2017	MG	1.0.0	First release.				#
# 02/01/2018	MG	1.0.2	Move to new source directory structure.	#
# 18/01/2018	MG	1.0.3	Update changed source location.		#
# 11/02/2018	MG	1.0.4	Make tar use the Posix format for	#
#				longer filenames.			#
# 21/06/2018	MG	1.0.5	Remove make, (leave install), of	#
#				libmgec doc-base file as it is now	#
#				built using AC_CONFIG_FILES.		#
# 25/06/2018	MG	1.0.6	Reverse 1.0.5 as AC_CONFIG_FILES cannot	#
#				be used for the substitution of		#
#				Installation Directory Variables.	#
# 16/05/2019	MG	1.0.7	Collapse AT sub-projects into one.	#
#				Remove shebang.				#
# 30/10/2019	MG	1.0.8	Do not register with doc-base or	#
#				dochelp when running make distcheck.	#
#				Reduce Doxygen out put when silent	#
#				rules are enabled.			#
# 26/06/2020	MG	1.0.9	Split into API and full internal	#
#				documentation.				#
#									#
#########################################################################


# Build API documentation.

docpkg = $(PACKAGE_TARNAME)-doxy-$(PACKAGE_VERSION).tar.gz

# The dependencies below start with Doxyfile which is produced by configure, so
# thereafter no updates to these documents will happen by make alone. Re-run
# configure and make, or, delete the stamp file and run make to force an update.

$(docpkg): doxygen.stamp
	tar -chz --format=posix -f $@ html

doxygen.stamp: Doxyfile
	if $(AM_V_P); then \
		DOXYGEN_QUIET=NO \
			DOXYGEN_PROJECT_NAME="MGE System Utility Library - API Documentation" \
			DOXYGEN_HTML_OUTPUT=html \
			DOXYGEN_ENABLED_SECTIONS= \
			DOXYGEN_EXCLUDE_PATTERNS="*internal*" \
			doxygen $< ; \
	else \
		DOXYGEN_QUIET=YES \
			DOXYGEN_PROJECT_NAME="MGE System Utility Library - API Documentation" \
			DOXYGEN_HTML_OUTPUT=html \
			DOXYGEN_ENABLED_SECTIONS= \
			DOXYGEN_EXCLUDE_PATTERNS="*internal*" \
			doxygen $< ; \
	fi
	echo Timestamp > $@


# Build full internal documentation.

intdocpkg = $(PACKAGE_TARNAME)-int-doxy-$(PACKAGE_VERSION).tar.gz

$(intdocpkg): doxygen1.stamp
	tar -chz --format=posix -f $@ html-int

doxygen1.stamp: Doxyfile
	if $(AM_V_P); then \
		DOXYGEN_QUIET=NO \
			DOXYGEN_PROJECT_NAME="MGE System Utility Library - Full Internal Documentation" \
			DOXYGEN_HTML_OUTPUT=html-int \
			DOXYGEN_ENABLED_SECTIONS=INTERNAL \
			DOXYGEN_EXCLUDE_PATTERNS= \
			doxygen $< ; \
	else \
		DOXYGEN_QUIET=YES \
			DOXYGEN_PROJECT_NAME="MGE System Utility Library - Full Internal Documentation" \
			DOXYGEN_HTML_OUTPUT=html-int \
			DOXYGEN_ENABLED_SECTIONS=INTERNAL \
			DOXYGEN_EXCLUDE_PATTERNS= \
			doxygen $< ; \
	fi
	echo Timestamp > $@


apidir = $(htmldir)/api
intdir = $(htmldir)/int

api_DATA = $(docpkg)
int_DATA = $(intdocpkg)


libmgesysutils libmgesysutils-int: Makefile
	mkdir -p $(@D)
	rm -f $@ $@.tmp
	$(edit) $(srcdir)/$(@F).in > $@
libmgesysutils: $(srcdir)/libmgesysutils.in
libmgesysutils-int: $(srcdir)/libmgesysutils-int.in


# If doc-base is installed register the documents then update dochelp if it is
# installed.

docbasedir = $(datarootdir)/doc-base

docbase_DATA = libmgesysutils libmgesysutils-int

install-data-hook:
if !DISTCHECKFAKE
	cd $(DESTDIR)$(apidir) && tar xf $(docpkg)
	cd $(DESTDIR)$(intdir) && tar xf $(intdocpkg)
	if command -v install-docs >/dev/null 2>&1; then \
		install-docs -vi $(docbasedir)/libmgesysutils; \
		install-docs -vi $(docbasedir)/libmgesysutils-int; \
	fi
	if command -v dochelp >/dev/null 2>&1; then \
		dochelp update; \
	fi
endif

uninstall-hook:
if !DISTCHECKFAKE
	cd $(DESTDIR)$(apidir) && rm -rf html
	cd $(DESTDIR)$(intdir) && rm -rf html-int
	if command -v install-docs >/dev/null 2>&1; then \
		install-docs -vr libmgesysutils; \
		install-docs -vr libmgesysutils-int; \
	fi
	if command -v dochelp >/dev/null 2>&1; then \
		dochelp update; \
	fi
endif


EXTRA_DIST = $(docpkg) $(intdocpkg) $(srcdir)/libmgesysutils.in \
	$(srcdir)/libmgesysutils-int.in


CLEANFILES = doxywarn.txt doxygen.stamp doxygen1.stamp $(docpkg) $(intdocpkg) \
	libmgesysutils libmgesysutils-int

clean-local:
	rm -rf html html-int

