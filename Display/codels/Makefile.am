lib_LTLIBRARIES = libdisplay_codels.la

libdisplay_codels_la_SOURCES=	display_c_types.h
libdisplay_codels_la_SOURCES+=	display_codels.c
libdisplay_codels_la_SOURCES+=	display_orders_codels.c
libdisplay_codels_la_SOURCES+=	display_monitor_codels.c

libdisplay_codels_la_CPPFLAGS=	$(requires_CFLAGS)
libdisplay_codels_la_LDFLAGS=	$(requires_LIBS)
libdisplay_codels_la_LDFLAGS+=	-release $(PACKAGE_VERSION)


# idl  mappings
BUILT_SOURCES=	display_c_types.h
CLEANFILES=	${BUILT_SOURCES}
display_c_types.h: ${top_srcdir}/display.gen
	${GENOM3}  mappings \
	  -MD -MF .deps/$@.d -MT $@ --signature -l c $< >$@

-include .deps/display_c_types.h.d
