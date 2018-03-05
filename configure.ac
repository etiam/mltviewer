# Process this file with autoconf to produce a configure script.

## ------------------------ ##
## Autoconf requirements    ##
## ------------------------ ##
AC_PREREQ([2.69])


## ------------------------ ##
## Initialisation           ##
## ------------------------ ##

# Autoconf
AC_INIT([mltviewer],[0.0.1],[rosson@gmail.com])
AC_CONFIG_SRCDIR([src/main.cpp])
AC_CONFIG_AUX_DIR([scripts])
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_HEADERS([config.h])
AC_SUBST(VERSION)

# Automake
AM_INIT_AUTOMAKE([1.11 foreign -Wgnu subdir-objects])
AM_MAINTAINER_MODE
AM_SANITY_CHECK
m4_ifdef([AM_SILENT_RULES], [AM_SILENT_RULES])

# Libtool 
LT_INIT
AC_SUBST(LIBTOOL_DEPS)

## ----------------------- ##
## Checks for programs     ##
## ----------------------- ##
AC_PROG_CC
AC_PROG_CXX
AC_DISABLE_STATIC
LT_INIT(dlopen)
AC_PROG_CPP
AC_PROG_INSTALL
AC_PROG_LN_S
AC_PROG_MAKE_SET
AC_PROG_AWK
AC_PROG_GREP
AC_PROG_SED

PKG_PROG_PKG_CONFIG

## ----------------------- ##
## Checks for typedefs,    ##
## structures, and compiler##
## characteristics.        ##
## ----------------------- ##
AC_HEADER_STDC
AC_C_CONST
AC_C_INLINE
AC_HEADER_STDBOOL

## ----------------------- ##
## Checks for libraries    ##
## ----------------------- ##

# mlt
PKG_CHECK_MODULES(MLT, mlt-framework >= 6.0.0)
PKG_CHECK_MODULES(MLTPLUSPLUS, mlt++ >= 6.0.0)

# qt
PKG_CHECK_MODULES([QTCORE], [Qt5Core >= 5.2.1], [])
PKG_CHECK_MODULES([QTWIDGETS], [Qt5Widgets >= 5.2.1], [])
PKG_CHECK_MODULES([QTGUI], [Qt5Gui  >= 5.2.1], [])
PKG_CHECK_MODULES([QTGL], [Qt5OpenGL >= 5.2.1], [])

## ----------------------- ##
## Compiler flags
## ----------------------- ##

# remove autoconf's "-g -O2" defaults
CFLAGS=`echo $CFLAGS | sed 's/-O.//g'`
CFLAGS=`echo $CFLAGS | sed 's/-g.//g'`
CFLAGS=`echo $CFLAGS | sed 's/-O//g'`
CFLAGS=`echo $CFLAGS | sed 's/-g//g'`
CXXFLAGS=`echo $CXXFLAGS | sed 's/-O.//g'`
CXXFLAGS=`echo $CXXFLAGS | sed 's/-g.//g'`
CXXFLAGS=`echo $CXXFLAGS | sed 's/-O//g'`
CXXFLAGS=`echo $CXXFLAGS | sed 's/-g//g'`

CFLAGS="${CFLAGS} -fno-strict-aliasing -Wall -Werror"
CXXFLAGS="${CXXFLAGS} -fno-strict-aliasing -Wall -Werror -std=c++14"

# until upgrade to qt5.5.1
CXXFLAGS="${CXXFLAGS} -Wno-inconsistent-missing-override"

## ----------------------- ##
## Optional arguments      ##
## ----------------------- ##

# --enable-debug
AC_ARG_ENABLE([debug],
  [  --enable-debug    turn on compiler/opengl debugging],
  [case "${enableval}" in
    yes) debug=true ;;
    no)  debug=false ;;
    *) AC_MSG_ERROR([bad value ${enableval} for --enable-debug]) ;;
  esac],[debug=false])
if test "x$debug" != xfalse; then
      CFLAGS="-g3 -fno-inline ${CFLAGS} -rdynamic"
      CXXFLAGS="-g3 -fno-inline ${CXXFLAGS} -rdynamic"
      AC_DEFINE(DEBUG_ENABLED,1,[turn on compiler/opengl debugging])
fi
AM_CONDITIONAL([DO_DEBUG], [test x$debug = xtrue]) 

# --enable-opt
AC_ARG_ENABLE([opt],
  [  --enable-opt    turn on compiler optging],
  [case "${enableval}" in
    yes) opt=true ;;
    no)  opt=false ;;
    *) AC_MSG_ERROR([bad value ${enableval} for --enable-opt]) ;;
  esac],[opt=false])
if test "x$opt" != xfalse; then
      CFLAGS="-O3 ${CFLAGS}"
      CXXFLAGS="-O3 ${CXXFLAGS}"
fi
if test "x$opt" != xfalse; then
      AC_DEFINE(NDEBUG,1,[strip out asserts])
fi

# --enable-profile
AC_ARG_ENABLE([profile],
  [  --enable-profile    turn on compiler profiling],
  [case "${enableval}" in
    yes) profile=true ;;
    no)  profile=false ;;
    *) AC_MSG_ERROR([bad value ${enableval} for --enable-profile]) ;;
  esac],[profile=false])
if test "x$profile" != xfalse; then
      CFLAGS="-g3 -fno-inline -fno-omit-frame-pointer ${CFLAGS}"
      CXXFLAGS="-g3 -fno-inline -fno-omit-frame-pointer ${CXXFLAGS}"
fi
AM_CONDITIONAL([DO_PROFILER], [test x$profile = xtrue]) 

# Evaluate shell variable equivalents to Makefile directory variables
if test "x$prefix" = xNONE
then
  prefix=$ac_default_prefix
fi
# Let make expand exec_prefix.
if test "x$exec_prefix" = xNONE
then
  exec_prefix='${prefix}'
fi
eval "eval LIB_DIR=$libdir"
AC_SUBST(LIB_DIR)

AC_SUBST(CFLAGS)
AC_SUBST(CXXLAGS)

# since we're using boost signals we need to make qt not use it's keywords which would conflict 
AC_DEFINE(QT_NO_KEYWORDS,,[do not use qt keywords])

# processor type
if test "x$host_cpu" == xx86_64; then
    AC_DEFINE(X86_64,,[64 bit arch])
fi

AC_DEFINE(Q_WS_MAC,1,[stoopid])

# output Makefiles
AC_CONFIG_FILES([
        Makefile
])
AC_OUTPUT
