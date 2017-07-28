lib_LTLIBRARIES = libloco_codels.la

libloco_codels_la_SOURCES=	loco_c_types.h
libloco_codels_la_SOURCES+=	loco_codels.cc
libloco_codels_la_SOURCES+=	loco_MoveAndBatt_codels.cc

libloco_codels_la_SOURCES+=	serial.cpp
libloco_codels_la_SOURCES+=	serial.hpp

libloco_codels_la_CPPFLAGS=	$(requires_CFLAGS)
libloco_codels_la_LDFLAGS=	$(requires_LIBS)
libloco_codels_la_LDFLAGS+=	-release $(PACKAGE_VERSION)


# idl  mappings
BUILT_SOURCES=	loco_c_types.h
CLEANFILES=	${BUILT_SOURCES}
loco_c_types.h: ${top_srcdir}/loco.gen
	${GENOM3}  mappings \
	  -MD -MF .deps/$@.d -MT $@ --signature -l c $< >$@

-include .deps/loco_c_types.h.d
