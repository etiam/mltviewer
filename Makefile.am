ACLOCAL_AMFLAGS           = -I m4 -I /usr/local/share/aclocal

bin_PROGRAMS              =
EXTRA_PROGRAMS            =
BUILT_SOURCES             =
noinst_LIBRARIES          =
pkglib_LTLIBRARIES        =
PHONY                     =

include $(top_srcdir)/src/Makefile.am
include $(top_srcdir)/test/Makefile.am

EXTRA_DIST                = $(nodist_ov_SOURCES:moc_%.cpp=%.h)
CLEANFILES                = $(filter moc_%.cpp,$(nodist_ov_SOURCES))

include $(top_srcdir)/extra.am
include $(top_srcdir)/qt.am

# cleanup plugins
install-exec-hook:
	rm -f $(DESTDIR)$(pkglibdir)/*.la
	rm -f $(DESTDIR)$(pkglibdir)/*.a

.PHONY : $(PHONY)
