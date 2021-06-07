dnl config.m4 for extension test

dnl Comments in this file start with the string 'dnl'.
dnl Remove where necessary.

dnl If your extension references something external, use 'with':

dnl PHP_ARG_WITH([test],
dnl   [for test support],
dnl   [AS_HELP_STRING([--with-test],
dnl     [Include test support])])

dnl Otherwise use 'enable':

PHP_ARG_WITH([cairo],
  [for cairo support],
  [AS_HELP_STRING([--with-cairo],
    [Include cairo support])],
  [no])

if test "$PHP_CAIRO" != "no"; then
  dnl Write more examples of tests here...

  dnl Remove this code block if the library does not support pkg-config.
  dnl PKG_CHECK_MODULES([LIBFOO], [foo])
  dnl PHP_EVAL_INCLINE($LIBFOO_CFLAGS)
  dnl PHP_EVAL_LIBLINE($LIBFOO_LIBS, TEST_SHARED_LIBADD)

  dnl If you need to check for a particular library version using PKG_CHECK_MODULES,
  dnl you can use comparison operators. For example:
  PKG_CHECK_MODULES([cairo], [cairo >= 1.0.0])
  dnl PKG_CHECK_MODULES([LIBFOO], [foo < 3.4])
  dnl PKG_CHECK_MODULES([LIBFOO], [foo = 1.2.3])

  dnl Remove this code block if the library supports pkg-config.
  dnl --with-test -> check with-path
  dnl SEARCH_PATH="/usr/local /usr"     # you might want to change this
  dnl SEARCH_FOR="/include/test.h"  # you most likely want to change this
  dnl if test -r $PHP_TEST/$SEARCH_FOR; then # path given as parameter
  dnl   TEST_DIR=$PHP_TEST
  dnl else # search default path list
  dnl   AC_MSG_CHECKING([for test files in default path])
  dnl   for i in $SEARCH_PATH ; do
  dnl     if test -r $i/$SEARCH_FOR; then
  dnl       TEST_DIR=$i
  dnl       AC_MSG_RESULT(found in $i)
  dnl     fi
  dnl   done
  dnl fi
  dnl
  dnl if test -z "$TEST_DIR"; then
  dnl   AC_MSG_RESULT([not found])
  dnl   AC_MSG_ERROR([Please reinstall the test distribution])
  dnl fi

  dnl Remove this code block if the library supports pkg-config.
  dnl --with-test -> add include path
  dnl PHP_ADD_INCLUDE($TEST_DIR/include)

  dnl Remove this code block if the library supports pkg-config.
  dnl --with-test -> check for lib and symbol presence
  dnl LIBNAME=TEST # you may want to change this
  dnl LIBSYMBOL=TEST # you most likely want to change this

  dnl If you need to check for a particular library function (e.g. a conditional
  dnl or version-dependent feature) and you are using pkg-config:
  dnl PHP_CHECK_LIBRARY($LIBNAME, $LIBSYMBOL,
  dnl [
  dnl   AC_DEFINE(HAVE_TEST_FEATURE, 1, [ ])
  dnl ],[
  dnl   AC_MSG_ERROR([FEATURE not supported by your test library.])
  dnl ], [
  dnl   $LIBFOO_LIBS
  dnl ])

  dnl If you need to check for a particular library function (e.g. a conditional
  dnl or version-dependent feature) and you are not using pkg-config:
  dnl PHP_CHECK_LIBRARY($LIBNAME, $LIBSYMBOL,
  dnl [
  dnl   PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $TEST_DIR/$PHP_LIBDIR, TEST_SHARED_LIBADD)
  dnl   AC_DEFINE(HAVE_TEST_FEATURE, 1, [ ])
  dnl ],[
  dnl   AC_MSG_ERROR([FEATURE not supported by your test library.])
  dnl ],[
  dnl   -L$TEST_DIR/$PHP_LIBDIR -lm
  dnl ])
  dnl
  dnl PHP_SUBST(TEST_SHARED_LIBADD)

  dnl In case of no dependencies
  dnl AC_DEFINE(HAVE_CAIRO, 1, [ Have cairo support ])


  cairo_sources="php_cairo/cairo.c \
                 php_cairo/status.c \
                 php_cairo/antialias.c \
                 php_cairo/content.c \
                 php_cairo/device-type.c \
                 php_cairo/extend.c \
                 php_cairo/fill-rule.c \
                 php_cairo/filter.c \
                 php_cairo/font-slant.c \
                 php_cairo/font-type.c \
                 php_cairo/font-weight.c \
                 php_cairo/hint-metrics.c \
                 php_cairo/hint-style.c \
                 php_cairo/line-cap.c \
                 php_cairo/line-join.c \
                 php_cairo/operator.c \
                 php_cairo/pattern-type.c \
                 php_cairo/region-overlap.c \
                 php_cairo/subpixel-order.c \
                 php_cairo/surface-type.c \
                 php_cairo/text-cluster-flags.c \
                 php_cairo/rectangle.c \
                 php_cairo/path-data-type.c \
                 php_cairo/path-data.c \
                 php_cairo/path.c \
                 php_cairo/matrix.c \
                 php_cairo/format.c \
                 php_cairo/surface.c \
                 php_cairo/image-surface.c \
                 php_cairo/png.c "

  PHP_NEW_EXTENSION(cairo, cairo.c $cairo_sources, $ext_shared)
  PHP_ADD_BUILD_DIR($ext_builddir/php_cairo, 1)
fi
