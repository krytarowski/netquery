bin_PROGRAMS = netquery
netquery_SOURCES =	\
	main.c		\
	#

netquery_CFLAGS=	$(AM_CFLAGS)
netquery_LDADD=		$(AM_LDADD)

# libgraphqlparser
netquery_CFLAGS+=	$(LIBGRAPHQLPARSER_CFLAGS)
netquery_LDADD+=	$(LIBGRAPHQLPARSER_LIBS)
