lib_LTLIBRARIES = libcamera_codels.la

libcamera_codels_la_SOURCES=	camera_c_types.h
libcamera_codels_la_SOURCES+=	camera_codels.cc
libcamera_codels_la_SOURCES+=	camera_film_codels.cc

libcamera_codels_la_SOURCES+=  imagerie.cpp
libcamera_codels_la_SOURCES+=  imagerie.hpp

libcamera_codels_la_CPPFLAGS=	$(requires_CFLAGS)
libcamera_codels_la_LDFLAGS=	$(requires_LIBS)
libcamera_codels_la_LDFLAGS+=	-release $(PACKAGE_VERSION)


# idl  mappings
BUILT_SOURCES=	camera_c_types.h
CLEANFILES=	${BUILT_SOURCES}
camera_c_types.h: ${top_srcdir}/camera.gen
	${GENOM3}  mappings \
	  -MD -MF .deps/$@.d -MT $@ --signature -l c $< >$@

-include .deps/camera_c_types.h.d
