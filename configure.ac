AC_INIT([netquery], [0.0], [n54@gmx.com])
AM_INIT_AUTOMAKE([-Wall -Werror])
AC_PROG_CC_C99
AC_CONFIG_HEADERS([config.h])

### libgraphqlparser #########

HAVE_LIBGRAPHQLPARSER=1
AC_CHECK_LIB(graphqlparser, [graphql_parse_string],
             [LIBGRAPHQLPARSER_LIBS="$LIBGRAPHQLPARSER_LIBS -lgraphqlparser"],
             [HAVE_LIBGRAPHQLPARSER=0])

if test $HAVE_LIBGRAPHQLPARSER -eq 1; then
        AC_CHECK_HEADERS([c/GraphQLParser.h],
                         [LIBGRAPHQLPARSER_CFLAGS="$LIBGRAPHQLPARSER_CFLAGS"],
                         [HAVE_LIBGRAPHQLPARSER=0])
fi

AC_MSG_CHECKING([for libgraphqlparser availability])
if test $HAVE_LIBGRAPHQLPARSER -eq 1; then
        AC_MSG_RESULT([yes])
else
        AC_MSG_RESULT([no])
fi

AS_IF([test $HAVE_LIBGRAPHQLPARSER -eq 0],
      [AC_MSG_ERROR([*** libgraphqlparser not found])])

AC_SUBST(LIBGRAPHQLPARSER_CFLAGS)
AC_SUBST(LIBGRAPHQLPARSER_LIBS)

####################

AC_CONFIG_FILES([
	Makefile
	src/Makefile
])
AC_OUTPUT
