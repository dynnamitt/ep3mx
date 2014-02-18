AC_PREREQ([2.68])
AC_INIT([ep3mx], [0.0.1], [kjetil@flovild-midtlie.name])
AM_INIT_AUTOMAKE
AC_CONFIG_SRCDIR([src/parser.c])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CC_C99
AC_PROG_RANLIB

# Checks for libraries.
AC_SEARCH_LIBS([XML_ParserCreateNS],[expat])

# Checks for header files.
AC_CHECK_HEADERS([expat.h stdlib.h string.h wchar.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_SIZE_T
AC_CONFIG_FILES([Makefile src/Makefile test/Makefile])
# Checks for library functions.

AC_OUTPUT
