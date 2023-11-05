#########################################################################
#									#
# Author: Copyright (C) 2015-2019, 2021-2023  Mark Grant		#
#									#
# Released under the GPLv3 only.					#
# SPDX-License-Identifier: GPL-3.0-only					#
#									#
# Purpose:								#
#	AutoMake script file to generate libmgesysutils pkgconfig from	#
# source.								#
#									#
#########################################################################


libmgesysutils.pc: Makefile
	mkdir -p $(@D)
	rm -f $@
	$(edit) $(srcdir)/$(@F).in > $@

libmgesysutils.pc: $(srcdir)/libmgesysutils.pc.in

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = libmgesysutils.pc

EXTRA_DIST = $(srcdir)/libmgesysutils.pc.in

CLEANFILES = libmgesysutils.pc

