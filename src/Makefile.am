bin_PROGRAMS             += mltview

mltview_SOURCES           =                                             \
                            src/main.cpp                                \
                            src/mainwindow.cpp                          \
                            src/glwidget.cpp                            \
                            src/mltcontroller.cpp                       \
                            src/qrc_resources.cpp
                            
nodist_mltview_SOURCES    =                                             \
                            src/moc_mainwindow.cpp                      \
                            src/moc_glwidget.cpp                        \
                            src/moc_mltcontroller.cpp

BUILT_SOURCES            +=                                             \
	                        src/ui_mainwindow.h

mltview_CPPFLAGS          =                                             \
                            -fPIC                                       \
							-I$(top_builddir)/src                     	\
                            @QTCORE_CFLAGS@                             \
                            @QTWIDGETS_CFLAGS@                          \
                            @QTGUI_CFLAGS@                              \
                            @QTGL_CFLAGS@                               \
                            @MLT_CFLAGS@                                \
                            @MLTPLUSPLUS_CFLAGS@

mltview_LDADD             =                                             \
                            @QTCORE_LIBS@                               \
                            @QTWIDGETS_LIBS@                            \
                            @QTGUI_LIBS@                                \
                            @QTGL_LIBS@                                 \
                            @MLT_LIBS@                                  \
                            @MLTPLUSPLUS_LIBS@                          \
                            -lGL -lGLU

mltview_LDFLAGS           =                                             \
                            -fPIC -rdynamic

if DO_PROFILER
mltview_LDADD            +=                                             \
                            @GPERFPROFILER_LIBS@
endif
