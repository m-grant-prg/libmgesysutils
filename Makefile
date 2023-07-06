# Makefile.in generated by automake 1.16.5 from Makefile.am.
# docs/doxygen/Makefile.  Generated from Makefile.in by configure.

# Copyright (C) 1994-2021 Free Software Foundation, Inc.

# This Makefile.in is free software; the Free Software Foundation
# gives unlimited permission to copy and/or distribute it,
# with or without modifications, as long as this notice is preserved.

# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY, to the extent permitted by law; without
# even the implied warranty of MERCHANTABILITY or FITNESS FOR A
# PARTICULAR PURPOSE.



#########################################################################
#									#
# Script ID: docs/doxygen/Makefile.am					#
# Author: Copyright (C) 2017-2022  Mark Grant				#
#									#
# Released under the GPLv3 only.					#
# SPDX-License-Identifier: GPL-3.0-only					#
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
# 08/10/2021	MG	1.0.10	Only register documents if building	#
#				with ATONLY.				#
#				Move main source documents into src to	#
#				enable use of EXTRA_DIST on subdir src.	#
# 06/12/2021	MG	1.0.11	Tighten SPDX tag.			#
# 20/07/2022	MG	1.0.12	Add doxygen target.			#
#				Add dependency on document sources and	#
#				C sources.				#
# 07/09/2022	MG	1.0.13	Remove all doxygen tarballs. Orphaned	#
#				tarballs can be left if git describe	#
#				changes and no make clean has been	#
#				performed.				#
#									#
#########################################################################


am__is_gnu_make = { \
  if test -z '$(MAKELEVEL)'; then \
    false; \
  elif test -n '$(MAKE_HOST)'; then \
    true; \
  elif test -n '$(MAKE_VERSION)' && test -n '$(CURDIR)'; then \
    true; \
  else \
    false; \
  fi; \
}
am__make_running_with_option = \
  case $${target_option-} in \
      ?) ;; \
      *) echo "am__make_running_with_option: internal error: invalid" \
              "target option '$${target_option-}' specified" >&2; \
         exit 1;; \
  esac; \
  has_opt=no; \
  sane_makeflags=$$MAKEFLAGS; \
  if $(am__is_gnu_make); then \
    sane_makeflags=$$MFLAGS; \
  else \
    case $$MAKEFLAGS in \
      *\\[\ \	]*) \
        bs=\\; \
        sane_makeflags=`printf '%s\n' "$$MAKEFLAGS" \
          | sed "s/$$bs$$bs[$$bs $$bs	]*//g"`;; \
    esac; \
  fi; \
  skip_next=no; \
  strip_trailopt () \
  { \
    flg=`printf '%s\n' "$$flg" | sed "s/$$1.*$$//"`; \
  }; \
  for flg in $$sane_makeflags; do \
    test $$skip_next = yes && { skip_next=no; continue; }; \
    case $$flg in \
      *=*|--*) continue;; \
        -*I) strip_trailopt 'I'; skip_next=yes;; \
      -*I?*) strip_trailopt 'I';; \
        -*O) strip_trailopt 'O'; skip_next=yes;; \
      -*O?*) strip_trailopt 'O';; \
        -*l) strip_trailopt 'l'; skip_next=yes;; \
      -*l?*) strip_trailopt 'l';; \
      -[dEDm]) skip_next=yes;; \
      -[JT]) skip_next=yes;; \
    esac; \
    case $$flg in \
      *$$target_option*) has_opt=yes; break;; \
    esac; \
  done; \
  test $$has_opt = yes
am__make_dryrun = (target_option=n; $(am__make_running_with_option))
am__make_keepgoing = (target_option=k; $(am__make_running_with_option))
pkgdatadir = $(datadir)/libmgesysutils
pkgincludedir = $(includedir)/libmgesysutils
pkglibdir = $(libdir)/libmgesysutils
am__cd = CDPATH="$${ZSH_VERSION+.}$(PATH_SEPARATOR)" && cd
install_sh_DATA = $(install_sh) -c -m 644
install_sh_PROGRAM = $(install_sh) -c
install_sh_SCRIPT = $(install_sh) -c
INSTALL_HEADER = $(INSTALL_DATA)
transform = $(program_transform_name)
NORMAL_INSTALL = :
PRE_INSTALL = :
POST_INSTALL = :
NORMAL_UNINSTALL = :
PRE_UNINSTALL = :
POST_UNINSTALL = :
build_triplet = x86_64-pc-linux-gnu
host_triplet = x86_64-pc-linux-gnu
subdir = docs/doxygen
ACLOCAL_M4 = $(top_srcdir)/aclocal.m4
am__aclocal_m4_deps = $(top_srcdir)/m4extra/c-compiler.m4 \
	$(top_srcdir)/m4extra/linker.m4 $(top_srcdir)/m4/00gnulib.m4 \
	$(top_srcdir)/m4/configmake.m4 \
	$(top_srcdir)/m4/gnulib-common.m4 \
	$(top_srcdir)/m4/gnulib-comp.m4 $(top_srcdir)/m4/libtool.m4 \
	$(top_srcdir)/m4/ltoptions.m4 $(top_srcdir)/m4/ltsugar.m4 \
	$(top_srcdir)/m4/ltversion.m4 $(top_srcdir)/m4/lt~obsolete.m4 \
	$(top_srcdir)/m4/zzgnulib.m4 $(top_srcdir)/configure.ac
am__configure_deps = $(am__aclocal_m4_deps) $(CONFIGURE_DEPENDENCIES) \
	$(ACLOCAL_M4)
DIST_COMMON = $(srcdir)/Makefile.am $(am__DIST_COMMON)
mkinstalldirs = $(install_sh) -d
CONFIG_HEADER = $(top_builddir)/src/prg/c/gen/inc/config.h
CONFIG_CLEAN_FILES = Doxyfile
CONFIG_CLEAN_VPATH_FILES =
AM_V_P = $(am__v_P_$(V))
am__v_P_ = $(am__v_P_$(AM_DEFAULT_VERBOSITY))
am__v_P_0 = false
am__v_P_1 = :
AM_V_GEN = $(am__v_GEN_$(V))
am__v_GEN_ = $(am__v_GEN_$(AM_DEFAULT_VERBOSITY))
am__v_GEN_0 = @echo "  GEN     " $@;
am__v_GEN_1 = 
AM_V_at = $(am__v_at_$(V))
am__v_at_ = $(am__v_at_$(AM_DEFAULT_VERBOSITY))
am__v_at_0 = @
am__v_at_1 = 
SOURCES =
DIST_SOURCES =
am__can_run_installinfo = \
  case $$AM_UPDATE_INFO_DIR in \
    n|no|NO) false;; \
    *) (install-info --version) >/dev/null 2>&1;; \
  esac
am__vpath_adj_setup = srcdirstrip=`echo "$(srcdir)" | sed 's|.|.|g'`;
am__vpath_adj = case $$p in \
    $(srcdir)/*) f=`echo "$$p" | sed "s|^$$srcdirstrip/||"`;; \
    *) f=$$p;; \
  esac;
am__strip_dir = f=`echo $$p | sed -e 's|^.*/||'`;
am__install_max = 40
am__nobase_strip_setup = \
  srcdirstrip=`echo "$(srcdir)" | sed 's/[].[^$$\\*|]/\\\\&/g'`
am__nobase_strip = \
  for p in $$list; do echo "$$p"; done | sed -e "s|$$srcdirstrip/||"
am__nobase_list = $(am__nobase_strip_setup); \
  for p in $$list; do echo "$$p $$p"; done | \
  sed "s| $$srcdirstrip/| |;"' / .*\//!s/ .*/ ./; s,\( .*\)/[^/]*$$,\1,' | \
  $(AWK) 'BEGIN { files["."] = "" } { files[$$2] = files[$$2] " " $$1; \
    if (++n[$$2] == $(am__install_max)) \
      { print $$2, files[$$2]; n[$$2] = 0; files[$$2] = "" } } \
    END { for (dir in files) print dir, files[dir] }'
am__base_list = \
  sed '$$!N;$$!N;$$!N;$$!N;$$!N;$$!N;$$!N;s/\n/ /g' | \
  sed '$$!N;$$!N;$$!N;$$!N;s/\n/ /g'
am__uninstall_files_from_dir = { \
  test -z "$$files" \
    || { test ! -d "$$dir" && test ! -f "$$dir" && test ! -r "$$dir"; } \
    || { echo " ( cd '$$dir' && rm -f" $$files ")"; \
         $(am__cd) "$$dir" && rm -f $$files; }; \
  }
am__installdirs = "$(DESTDIR)$(apidir)" "$(DESTDIR)$(docbasedir)" \
	"$(DESTDIR)$(intdir)"
DATA = $(api_DATA) $(docbase_DATA) $(int_DATA)
am__tagged_files = $(HEADERS) $(SOURCES) $(TAGS_FILES) $(LISP)
am__DIST_COMMON = $(srcdir)/Doxyfile.in $(srcdir)/Makefile.in
DISTFILES = $(DIST_COMMON) $(DIST_SOURCES) $(TEXINFOS) $(EXTRA_DIST)
pkglibexecdir = ${libexecdir}/${PACKAGE}
ACLOCAL = ${SHELL} '/home/runner/work/libmgesysutils/libmgesysutils/build-aux/missing' aclocal-1.16
AMTAR = $${TAR-tar}
AM_DEFAULT_VERBOSITY = 0
AR = ar
ARFLAGS = cr
AUTOCONF = ${SHELL} '/home/runner/work/libmgesysutils/libmgesysutils/build-aux/missing' autoconf
AUTOHEADER = ${SHELL} '/home/runner/work/libmgesysutils/libmgesysutils/build-aux/missing' autoheader
AUTOMAKE = ${SHELL} '/home/runner/work/libmgesysutils/libmgesysutils/build-aux/missing' automake-1.16
AWK = gawk
CC = gcc
CCDEPMODE = depmode=gcc3
CFLAGS = 
CPP = gcc -E
CPPFLAGS = 
CSCOPE = cscope
CTAGS = ctags
CXX = g++
CXXCPP = g++ -E
CXXDEPMODE = depmode=gcc3
CXXFLAGS = -g -O2
CYGPATH_W = echo
DEFS = -DHAVE_CONFIG_H
DEPDIR = .deps
DLLTOOL = false
DOT = yes
DOXYGEN = yes
DSYMUTIL = 
DUMPBIN = 
ECHO_C = 
ECHO_N = -n
ECHO_T = 
EGREP = /usr/bin/grep -E
ETAGS = etags
EXEEXT = 
FGREP = /usr/bin/grep -F
GREP = /usr/bin/grep
INSTALL = /usr/bin/install -c
INSTALL_DATA = ${INSTALL} -m 644
INSTALL_PROGRAM = ${INSTALL}
INSTALL_SCRIPT = ${INSTALL}
INSTALL_STRIP_PROGRAM = $(install_sh) -c -s
IWYU = 
LD = /usr/bin/ld -m elf_x86_64
LDFLAGS = 
LIBGNU_LIBDEPS = 
LIBGNU_LTLIBDEPS = 
LIBMGEC_CFLAGS = -I/usr/include/libmgec
LIBMGEC_LIBS = -lmgec
LIBOBJS = 
LIBS = 
LIBTOOL = $(SHELL) $(top_builddir)/libtool
LIPO = 
LN_S = ln -s
LTLIBOBJS = 
LT_SYS_LIBRARY_PATH = 
MAKEINFO = ${SHELL} '/home/runner/work/libmgesysutils/libmgesysutils/build-aux/missing' makeinfo
MANIFEST_TOOL = :
MG_ANALYZER_CFLAGS =  -fanalyzer
MG_CFLAGS = -g -Wall -Wextra -fstack-protector-strong -grecord-gcc-switches -std=gnu11 -Wbad-function-cast -Wconversion -Wdeclaration-after-statement -Wformat-security -Wmissing-include-dirs -Wmissing-prototypes -Wredundant-decls -Wshadow -Wstrict-prototypes -fasynchronous-unwind-tables -Wduplicated-cond -Wnull-dereference -fstack-clash-protection -Wmultistatement-macros -O2
MG_CPPFLAGS = -DHAVE_WINSOCK2_H=0 -Wdate-time -D_FORTIFY_SOURCE=2
MG_DEBUG_CFLAGS = -g -Wall -Wextra -fstack-protector-strong -grecord-gcc-switches -std=gnu11 -Wbad-function-cast -Wconversion -Wdeclaration-after-statement -Wformat-security -Wmissing-include-dirs -Wmissing-prototypes -Wredundant-decls -Wshadow -Wstrict-prototypes -fasynchronous-unwind-tables -Wduplicated-cond -Wnull-dereference -fstack-clash-protection -Wmultistatement-macros -ggdb3 -O0
MG_DEBUG_CPPFLAGS = -DHAVE_WINSOCK2_H=0 -Wdate-time
MG_LDFLAGS = -Wl,-z,relro
MKDIR_P = /usr/bin/mkdir -p
NM = /usr/bin/nm -B
NMEDIT = 
OBJDUMP = objdump
OBJEXT = o
OTOOL = 
OTOOL64 = 
PACKAGE = libmgesysutils
PACKAGE_BUGREPORT = m.grant.prg@gmail.com
PACKAGE_NAME = MGE system utilities library
PACKAGE_STRING = MGE system utilities library 1.5.1
PACKAGE_TARNAME = libmgesysutils
PACKAGE_URL = 
PACKAGE_VERSION = 1.5.1
PATH_SEPARATOR = :
PKGCONFIG = yes
RANLIB = ranlib
SCAN_BUILD = 
SED = /usr/bin/sed
SET_MAKE = 
SHELL = /bin/bash
STRIP = strip
TAR = yes
TXT2MAN = yes
TXT2MANWRAP = yes
VERSION = 1.5.1
abs_builddir = /home/runner/work/libmgesysutils/libmgesysutils/docs/doxygen
abs_srcdir = /home/runner/work/libmgesysutils/libmgesysutils/docs/doxygen
abs_top_builddir = /home/runner/work/libmgesysutils/libmgesysutils
abs_top_srcdir = /home/runner/work/libmgesysutils/libmgesysutils
ac_ct_AR = ar
ac_ct_CC = gcc
ac_ct_CXX = g++
ac_ct_DUMPBIN = 
am__include = include
am__leading_dot = .
am__quote = 
am__tar = tar --format=posix -chf - "$$tardir"
am__untar = tar -xf -
bindir = ${exec_prefix}/bin
build = x86_64-pc-linux-gnu
build_alias = 
build_cpu = x86_64
build_os = linux-gnu
build_vendor = pc
builddir = .
datadir = ${datarootdir}
datarootdir = ${prefix}/share
docbaseloc = ${prefix}/share/doc-base
docdir = ${datarootdir}/doc/${PACKAGE_TARNAME}
dvidir = ${docdir}
edit = sed 		-e 's|@pc_requires@|$(pc_requires)|g' 		-e 's|@pc_requires_private@|$(pc_requires_private)|g' 		-e 's|@pkgversion@|$(pkgversion)|g' 		-e 's|@docbaseloc@|$(docbaseloc)|g' 		-e 's|@CC@|$(CC)|g' 		-e 's|@prefix@|$(prefix)|g' 		-e 's|@exec_prefix@|$(exec_prefix)|g' 		-e 's|@bindir@|$(bindir)|g' 		-e 's|@sbindir@|$(sbindir)|g' 		-e 's|@libexecdir@|$(libexecdir)|g' 		-e 's|@libdir@|$(libdir)|g' 		-e 's|@sysconfdir@|$(sysconfdir)|g' 		-e 's|@sharedstatedir@|$(sharedstatedir)|g' 		-e 's|@localstatedir@|$(localstatedir)|g' 		-e 's|@runstatedir@|$(runstatedir)|g' 		-e 's|@includedir@|$(includedir)|g' 		-e 's|@oldincludedir@|$(oldincludedir)|g' 		-e 's|@datarootdir@|$(datarootdir)|g' 		-e 's|@localedir@|$(localedir)|g' 		-e 's|@datadir@|$(datadir)|g' 		-e 's|@mandir@|$(mandir)|g' 		-e 's|@infodir@|$(infodir)|g' 		-e 's|@docdir@|$(docdir)|g' 		-e 's|@htmldir@|$(htmldir)|g' 		-e 's|@dvidir@|$(dvidir)|g' 		-e 's|@pdfdir@|$(pdfdir)|g' 		-e 's|@psdir@|$(psdir)|g' 		-e 's|@lispdir@|$(lispdir)|g' 		-e 's|@pkgdatadir@|$(pkgdatadir)|g' 		-e 's|@pkgincludedir@|$(pkgincludedir)|g' 		-e 's|@pkglibdir@|$(pkglibdir)|g' 		-e 's|@pkglibexecdir@|$(pkglibexecdir)|g'
exec_prefix = ${prefix}
gl_LIBOBJS = 
gl_LTLIBOBJS = 
gltests_LIBOBJS = 
gltests_LTLIBOBJS = 
gltests_WITNESS = IN_LIBMGESYSUTILS_GNULIB_TESTS
host = x86_64-pc-linux-gnu
host_alias = 
host_cpu = x86_64
host_os = linux-gnu
host_vendor = pc
htmldir = ${docdir}
includedir = ${prefix}/include
infodir = ${datarootdir}/info
install_sh = ${SHELL} /home/runner/work/libmgesysutils/libmgesysutils/build-aux/install-sh
lib_version_info = 2:0:0
libdir = ${exec_prefix}/lib
libexecdir = ${exec_prefix}/libexec
lispdir = ${datarootdir}/emacs/site-lisp
localedir = ${datarootdir}/locale
localstatedir = ${prefix}/var
mandir = ${datarootdir}/man
mkdir_p = $(MKDIR_P)
oldincludedir = /usr/include
pc_requires = libmgec
pc_requires_private = 
pdfdir = ${docdir}
pkgversion = 1.5.1
prefix = /usr/local
program_transform_name = s,x,x,
psdir = ${docdir}
runstatedir = ${localstatedir}/run
sbindir = ${exec_prefix}/sbin
sharedstatedir = ${prefix}/com
srcdir = .
sysconfdir = ${prefix}/etc
target_alias = 
tmpheaders = 
tmplibraries = 
top_build_prefix = ../../
top_builddir = ../..
top_srcdir = ../..
srcdepends := $(shell find $(srcdir)/src -type f -printf "%p ") \
	$(shell find $(top_srcdir) -type f -name *.c -printf "%p " \
		-o -name *.h -printf "%p ")


# Build API documentation.
docpkg = $(PACKAGE_TARNAME)-doxy-$(PACKAGE_VERSION).tar.gz

# Build full internal documentation.
intdocpkg = $(PACKAGE_TARNAME)-int-doxy-$(PACKAGE_VERSION).tar.gz
apidir = $(htmldir)/api
intdir = $(htmldir)/int
api_DATA = $(docpkg)
int_DATA = $(intdocpkg)

# If doc-base is installed register the documents then update dochelp if it is
# installed. Registering is dependent on ATONLY.
docbasedir = ${prefix}/share/doc-base
docbase_DATA = libmgesysutils libmgesysutils-int
EXTRA_DIST = $(docpkg) $(intdocpkg) $(srcdir)/src $(srcdir)/libmgesysutils.in \
	$(srcdir)/libmgesysutils-int.in

CLEANFILES = doxywarn.txt doxygen.stamp doxygen1.stamp libmgesysutils \
	     libmgesysutils-int

all: all-am

.SUFFIXES:
$(srcdir)/Makefile.in:  $(srcdir)/Makefile.am  $(am__configure_deps)
	@for dep in $?; do \
	  case '$(am__configure_deps)' in \
	    *$$dep*) \
	      ( cd $(top_builddir) && $(MAKE) $(AM_MAKEFLAGS) am--refresh ) \
	        && { if test -f $@; then exit 0; else break; fi; }; \
	      exit 1;; \
	  esac; \
	done; \
	echo ' cd $(top_srcdir) && $(AUTOMAKE) --gnu docs/doxygen/Makefile'; \
	$(am__cd) $(top_srcdir) && \
	  $(AUTOMAKE) --gnu docs/doxygen/Makefile
Makefile: $(srcdir)/Makefile.in $(top_builddir)/config.status
	@case '$?' in \
	  *config.status*) \
	    cd $(top_builddir) && $(MAKE) $(AM_MAKEFLAGS) am--refresh;; \
	  *) \
	    echo ' cd $(top_builddir) && $(SHELL) ./config.status $(subdir)/$@ $(am__maybe_remake_depfiles)'; \
	    cd $(top_builddir) && $(SHELL) ./config.status $(subdir)/$@ $(am__maybe_remake_depfiles);; \
	esac;

$(top_builddir)/config.status: $(top_srcdir)/configure $(CONFIG_STATUS_DEPENDENCIES)
	cd $(top_builddir) && $(MAKE) $(AM_MAKEFLAGS) am--refresh

$(top_srcdir)/configure:  $(am__configure_deps)
	cd $(top_builddir) && $(MAKE) $(AM_MAKEFLAGS) am--refresh
$(ACLOCAL_M4):  $(am__aclocal_m4_deps)
	cd $(top_builddir) && $(MAKE) $(AM_MAKEFLAGS) am--refresh
$(am__aclocal_m4_deps):
Doxyfile: $(top_builddir)/config.status $(srcdir)/Doxyfile.in
	cd $(top_builddir) && $(SHELL) ./config.status $(subdir)/$@

mostlyclean-libtool:
	-rm -f *.lo

clean-libtool:
	-rm -rf .libs _libs
install-apiDATA: $(api_DATA)
	@$(NORMAL_INSTALL)
	@list='$(api_DATA)'; test -n "$(apidir)" || list=; \
	if test -n "$$list"; then \
	  echo " $(MKDIR_P) '$(DESTDIR)$(apidir)'"; \
	  $(MKDIR_P) "$(DESTDIR)$(apidir)" || exit 1; \
	fi; \
	for p in $$list; do \
	  if test -f "$$p"; then d=; else d="$(srcdir)/"; fi; \
	  echo "$$d$$p"; \
	done | $(am__base_list) | \
	while read files; do \
	  echo " $(INSTALL_DATA) $$files '$(DESTDIR)$(apidir)'"; \
	  $(INSTALL_DATA) $$files "$(DESTDIR)$(apidir)" || exit $$?; \
	done

uninstall-apiDATA:
	@$(NORMAL_UNINSTALL)
	@list='$(api_DATA)'; test -n "$(apidir)" || list=; \
	files=`for p in $$list; do echo $$p; done | sed -e 's|^.*/||'`; \
	dir='$(DESTDIR)$(apidir)'; $(am__uninstall_files_from_dir)
install-docbaseDATA: $(docbase_DATA)
	@$(NORMAL_INSTALL)
	@list='$(docbase_DATA)'; test -n "$(docbasedir)" || list=; \
	if test -n "$$list"; then \
	  echo " $(MKDIR_P) '$(DESTDIR)$(docbasedir)'"; \
	  $(MKDIR_P) "$(DESTDIR)$(docbasedir)" || exit 1; \
	fi; \
	for p in $$list; do \
	  if test -f "$$p"; then d=; else d="$(srcdir)/"; fi; \
	  echo "$$d$$p"; \
	done | $(am__base_list) | \
	while read files; do \
	  echo " $(INSTALL_DATA) $$files '$(DESTDIR)$(docbasedir)'"; \
	  $(INSTALL_DATA) $$files "$(DESTDIR)$(docbasedir)" || exit $$?; \
	done

uninstall-docbaseDATA:
	@$(NORMAL_UNINSTALL)
	@list='$(docbase_DATA)'; test -n "$(docbasedir)" || list=; \
	files=`for p in $$list; do echo $$p; done | sed -e 's|^.*/||'`; \
	dir='$(DESTDIR)$(docbasedir)'; $(am__uninstall_files_from_dir)
install-intDATA: $(int_DATA)
	@$(NORMAL_INSTALL)
	@list='$(int_DATA)'; test -n "$(intdir)" || list=; \
	if test -n "$$list"; then \
	  echo " $(MKDIR_P) '$(DESTDIR)$(intdir)'"; \
	  $(MKDIR_P) "$(DESTDIR)$(intdir)" || exit 1; \
	fi; \
	for p in $$list; do \
	  if test -f "$$p"; then d=; else d="$(srcdir)/"; fi; \
	  echo "$$d$$p"; \
	done | $(am__base_list) | \
	while read files; do \
	  echo " $(INSTALL_DATA) $$files '$(DESTDIR)$(intdir)'"; \
	  $(INSTALL_DATA) $$files "$(DESTDIR)$(intdir)" || exit $$?; \
	done

uninstall-intDATA:
	@$(NORMAL_UNINSTALL)
	@list='$(int_DATA)'; test -n "$(intdir)" || list=; \
	files=`for p in $$list; do echo $$p; done | sed -e 's|^.*/||'`; \
	dir='$(DESTDIR)$(intdir)'; $(am__uninstall_files_from_dir)
tags TAGS:

ctags CTAGS:

cscope cscopelist:

distdir: $(BUILT_SOURCES)
	$(MAKE) $(AM_MAKEFLAGS) distdir-am

distdir-am: $(DISTFILES)
	@srcdirstrip=`echo "$(srcdir)" | sed 's/[].[^$$\\*]/\\\\&/g'`; \
	topsrcdirstrip=`echo "$(top_srcdir)" | sed 's/[].[^$$\\*]/\\\\&/g'`; \
	list='$(DISTFILES)'; \
	  dist_files=`for file in $$list; do echo $$file; done | \
	  sed -e "s|^$$srcdirstrip/||;t" \
	      -e "s|^$$topsrcdirstrip/|$(top_builddir)/|;t"`; \
	case $$dist_files in \
	  */*) $(MKDIR_P) `echo "$$dist_files" | \
			   sed '/\//!d;s|^|$(distdir)/|;s,/[^/]*$$,,' | \
			   sort -u` ;; \
	esac; \
	for file in $$dist_files; do \
	  if test -f $$file || test -d $$file; then d=.; else d=$(srcdir); fi; \
	  if test -d $$d/$$file; then \
	    dir=`echo "/$$file" | sed -e 's,/[^/]*$$,,'`; \
	    if test -d "$(distdir)/$$file"; then \
	      find "$(distdir)/$$file" -type d ! -perm -700 -exec chmod u+rwx {} \;; \
	    fi; \
	    if test -d $(srcdir)/$$file && test $$d != $(srcdir); then \
	      cp -fpR $(srcdir)/$$file "$(distdir)$$dir" || exit 1; \
	      find "$(distdir)/$$file" -type d ! -perm -700 -exec chmod u+rwx {} \;; \
	    fi; \
	    cp -fpR $$d/$$file "$(distdir)$$dir" || exit 1; \
	  else \
	    test -f "$(distdir)/$$file" \
	    || cp -p $$d/$$file "$(distdir)/$$file" \
	    || exit 1; \
	  fi; \
	done
check-am: all-am
check: check-am
all-am: Makefile $(DATA)
installdirs:
	for dir in "$(DESTDIR)$(apidir)" "$(DESTDIR)$(docbasedir)" "$(DESTDIR)$(intdir)"; do \
	  test -z "$$dir" || $(MKDIR_P) "$$dir"; \
	done
install: install-am
install-exec: install-exec-am
install-data: install-data-am
uninstall: uninstall-am

install-am: all-am
	@$(MAKE) $(AM_MAKEFLAGS) install-exec-am install-data-am

installcheck: installcheck-am
install-strip:
	if test -z '$(STRIP)'; then \
	  $(MAKE) $(AM_MAKEFLAGS) INSTALL_PROGRAM="$(INSTALL_STRIP_PROGRAM)" \
	    install_sh_PROGRAM="$(INSTALL_STRIP_PROGRAM)" INSTALL_STRIP_FLAG=-s \
	      install; \
	else \
	  $(MAKE) $(AM_MAKEFLAGS) INSTALL_PROGRAM="$(INSTALL_STRIP_PROGRAM)" \
	    install_sh_PROGRAM="$(INSTALL_STRIP_PROGRAM)" INSTALL_STRIP_FLAG=-s \
	    "INSTALL_PROGRAM_ENV=STRIPPROG='$(STRIP)'" install; \
	fi
mostlyclean-generic:

clean-generic:
	-test -z "$(CLEANFILES)" || rm -f $(CLEANFILES)

distclean-generic:
	-test -z "$(CONFIG_CLEAN_FILES)" || rm -f $(CONFIG_CLEAN_FILES)
	-test . = "$(srcdir)" || test -z "$(CONFIG_CLEAN_VPATH_FILES)" || rm -f $(CONFIG_CLEAN_VPATH_FILES)

maintainer-clean-generic:
	@echo "This command is intended for maintainers to use"
	@echo "it deletes files that may require special tools to rebuild."
clean: clean-am

clean-am: clean-generic clean-libtool clean-local mostlyclean-am

distclean: distclean-am
	-rm -f Makefile
distclean-am: clean-am distclean-generic

dvi: dvi-am

dvi-am:

html: html-am

html-am:

info: info-am

info-am:

install-data-am: install-apiDATA install-docbaseDATA install-intDATA
	@$(NORMAL_INSTALL)
	$(MAKE) $(AM_MAKEFLAGS) install-data-hook
install-dvi: install-dvi-am

install-dvi-am:

install-exec-am:

install-html: install-html-am

install-html-am:

install-info: install-info-am

install-info-am:

install-man:

install-pdf: install-pdf-am

install-pdf-am:

install-ps: install-ps-am

install-ps-am:

installcheck-am:

maintainer-clean: maintainer-clean-am
	-rm -f Makefile
maintainer-clean-am: distclean-am maintainer-clean-generic

mostlyclean: mostlyclean-am

mostlyclean-am: mostlyclean-generic mostlyclean-libtool

pdf: pdf-am

pdf-am:

ps: ps-am

ps-am:

uninstall-am: uninstall-apiDATA uninstall-docbaseDATA \
	uninstall-intDATA uninstall-local

.MAKE: install-am install-data-am install-strip

.PHONY: all all-am check check-am clean clean-generic clean-libtool \
	clean-local cscopelist-am ctags-am distclean distclean-generic \
	distclean-libtool distdir dvi dvi-am html html-am info info-am \
	install install-am install-apiDATA install-data \
	install-data-am install-data-hook install-docbaseDATA \
	install-dvi install-dvi-am install-exec install-exec-am \
	install-html install-html-am install-info install-info-am \
	install-intDATA install-man install-pdf install-pdf-am \
	install-ps install-ps-am install-strip installcheck \
	installcheck-am installdirs maintainer-clean \
	maintainer-clean-generic mostlyclean mostlyclean-generic \
	mostlyclean-libtool pdf pdf-am ps ps-am tags-am uninstall \
	uninstall-am uninstall-apiDATA uninstall-docbaseDATA \
	uninstall-intDATA uninstall-local

.PRECIOUS: Makefile


$(docpkg): doxygen.stamp
	tar -chz --format=posix -f $@ html

doxygen.stamp: Doxyfile $(srcdepends)
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

$(intdocpkg): doxygen1.stamp
	tar -chz --format=posix -f $@ html-int

doxygen1.stamp: Doxyfile $(srcdepends)
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

# Create a target to facilitate make doxygen
doxygen: $(docpkg) $(intdocpkg) libmgesysutils libmgesysutils-int

.PHONY: doxygen

libmgesysutils libmgesysutils-int: Makefile
	mkdir -p $(@D)
	rm -f $@ $@.tmp
	$(edit) $(srcdir)/$(@F).in > $@
libmgesysutils: $(srcdir)/libmgesysutils.in
libmgesysutils-int: $(srcdir)/libmgesysutils-int.in

install-data-hook:
	cd $(DESTDIR)$(apidir) && tar xf $(docpkg)
	cd $(DESTDIR)$(intdir) && tar xf $(intdocpkg)
#	if command -v install-docs >/dev/null 2>&1; then \
#		install-docs -vi $(docbasedir)/libmgesysutils; \
#		install-docs -vi $(docbasedir)/libmgesysutils-int; \
#	fi
#	if command -v dochelp >/dev/null 2>&1; then \
#		dochelp update; \
#	fi

uninstall-local:
#	if command -v install-docs >/dev/null 2>&1; then \
#		install-docs -vr libmgesysutils; \
#		install-docs -vr libmgesysutils-int; \
#	fi
#	if command -v dochelp >/dev/null 2>&1; then \
#		dochelp update; \
#	fi
	cd $(DESTDIR)$(apidir) && rm -rf html
	cd $(DESTDIR)$(intdir) && rm -rf html-int

clean-local:
	rm -rf html html-int libmgesysutils*doxy*.tar.gz

# Tell versions [3.59,3.63) of GNU make to not export all variables.
# Otherwise a system limit (for SysV at least) may be exceeded.
.NOEXPORT:
