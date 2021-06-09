dnl config.m4 for extension cairo

dnl Comments in this file start with the string 'dnl'.
dnl Remove where necessary.

dnl If your extension references something external, use 'with':

dnl PHP_ARG_WITH([cairo],
dnl   [for cairo support],
dnl   [AS_HELP_STRING([--with-cairo],
dnl     [Include cairo support])])

dnl Otherwise use 'enable':

PHP_ARG_WITH([cairo],
  [for cairo support],
  [AS_HELP_STRING([--with-cairo],
    [Include cairo support])],
  [no])

if test "$PHP_CAIRO" != "no"; then
  dnl Write more examples of tests here...

  if test -z "$PKG_CONFIG"; then
    AC_PATH_PROG(PKG_CONFIG, pkg-config, no)
  fi

  if test -x "$PKG_CONFIG"; then
    AC_MSG_CHECKING("for cairo.pc")
    CAIRO_LIBS=`$PKG_CONFIG --libs   cairo`
    CAIRO_INCL=`$PKG_CONFIG --cflags cairo`
  fi


  PHP_EVAL_LIBLINE($CAIRO_LIBS, CAIRO_SHARED_LIBADD)
  PHP_EVAL_INCLINE($CAIRO_INCL, CAIRO_SHARED_LIBADD)




  PHP_SUBST(CAIRO_SHARED_LIBADD)

  dnl In case of no dependencies
  dnl AC_DEFINE(HAVE_CAIRO, 1, [ Have cairo support ])

  PHP_NEW_EXTENSION(cairo, cairo.c php_cairo/rectangle.c, $ext_shared)
  PHP_ADD_BUILD_DIR($ext_builddir/php_cairo, 1)
fi
