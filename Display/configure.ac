dnl Autoconf file for building display codels library.

AC_PREREQ(2.59)

AC_INIT([display-genom3],[1.0],[felix@laas.fr])
AC_CONFIG_MACRO_DIR([autoconf])
AC_CONFIG_AUX_DIR([autoconf])
AC_CONFIG_HEADERS([autoconf/acdisplay.h])
AM_INIT_AUTOMAKE([foreign no-define])

dnl Compilers
dnl
LT_INIT
AC_PROG_CC
AC_PROG_CXX


dnl External packages
PKG_CHECK_MODULES(requires, [
  genom3 >= 2.99.4
])

AC_PATH_PROG(GENOM3, [genom3], AC_MSG_ERROR([genom3 tool not found], 2))


dnl --with-templates option
AG_OPT_TEMPLATES([$GENOM3 ],
    [$srcdir/display.gen])


dnl Output
AC_CONFIG_FILES([
	display-genom3.pc
	display-genom3-uninstalled.pc
	Makefile
	codels/Makefile
])
AC_OUTPUT
AG_OUTPUT_TEMPLATES
