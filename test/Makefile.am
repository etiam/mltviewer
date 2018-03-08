bin_PROGRAMS             += mextract

mextract_SOURCES          =                                             \
                            test/main.cpp
                            
mextract_CPPFLAGS         =                                             \
                            -fPIC                                       \
							-I$(top_builddir)/src                     	\
                            @QTCORE_CFLAGS@                             \
                            @QTWIDGETS_CFLAGS@                          \
                            @QTGUI_CFLAGS@                              \
                            @QTGL_CFLAGS@                               \
                            @MLT_CFLAGS@                                \
                            @MLTPLUSPLUS_CFLAGS@

mextract_LDADD            =                                             \
                            @QTCORE_LIBS@                               \
                            @QTWIDGETS_LIBS@                            \
                            @QTGUI_LIBS@                                \
                            @QTGL_LIBS@                                 \
                            @MLT_LIBS@                                  \
                            @MLTPLUSPLUS_LIBS@                          \
                            -lGL -lGLU

mextract_LDFLAGS          =                                             \
                            -fPIC -rdynamic

if DO_PROFILER
mextract_LDADD           +=                                             \
                            @GPERFPROFILER_LIBS@
endif
