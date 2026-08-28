PORTNAME=	avidemux2
PKGNAMESUFFIX=	-plugins
PORTVERSION=	${AVIDEMUX_VERSION}
CATEGORIES=	multimedia
MAINTAINER=	multimedia@test
COMMENT=	Simple video editor – plugins (Qt6 generation)
WWW=		https://avidemux.org/

.include "${.CURDIR}/../avidemux2/Makefile.common"

LIB_DEPENDS=	libADM6avutil.so.59:multimedia/avidemux2

# Plugins need both the core and the Qt6 UI headers/libraries
BUILD_DEPENDS=	avidemux2-qt6>=${PORTVERSION}:multimedia/avidemux2-qt6
RUN_DEPENDS=	avidemux2-qt6>=${PORTVERSION}:multimedia/avidemux2-qt6

USES+=		qt:6 gl
USE_QT=		base tools:build
USE_GL=		gl opengl

CMAKE_SOURCE_PATH=	${WRKSRC}/avidemux_plugins

# Build plugins for Qt6 + CLI + common
CMAKE_ARGS+=	-DPLUGIN_UI=ALL
CMAKE_ARGS+=	-DENABLE_QT6:BOOL=ON
CMAKE_ARGS+=	-DENABLE_QT5:BOOL=OFF
CMAKE_ARGS+=	-DVAPOURSYNTH:BOOL=OFF
CMAKE_ARGS+=	-DENABLE_VAPOURSYNTH:BOOL=OFF
CMAKE_ARGS+=	-DCMAKE_PREFIX_PATH=${LOCALBASE}
CMAKE_ARGS+=	-DCMAKE_MODULE_PATH="${LOCALBASE}/include/avidemux/2.8/cmake;${WRKSRC}/cmake"
CMAKE_ARGS+=    -DCMAKE_CXX_FLAGS="-I${WRKSRC}/avidemux/qt4 -I${WRKSRC}/avidemux/qt4/ADM_UIs/include -I${WRKSRC}/avidemux/qt4/ADM_jobs/include -I${WRKSRC}/avidemux/qt4/ADM_openGL/include -I${WRKSRC}/avidemux/qt4/ADM_qt/include -I${WRKSRC}/avidemux/qt4/ADM_update/include -I${WRKSRC}/avidemux/common"
CMAKE_ARGS+=    -DCMAKE_INSTALL_PLUGINDIR=lib/ADM_plugins6

post-extract:
	@${TRUE}
	@${MKDIR} ${WRKSRC}/cmake
	@${ECHO_CMD} "macro(checkGtk)" > ${WRKSRC}/cmake/admCheckGtk.cmake
	@${ECHO_CMD} "  message(STATUS \"GTK support disabled\")" >> ${WRKSRC}/cmake/admCheckGtk.cmake
	@${ECHO_CMD} "endmacro()" >> ${WRKSRC}/cmake/admCheckGtk.cmake
	@${CP} -R ${WRKSRC}/avidemux/qt4/cmake/* ${WRKSRC}/cmake/ 2>/dev/null || true
	@${CP} ${WRKSRC}/avidemux/qt4/cmake/admCheckQt*.cmake ${WRKSRC}/cmake/ 2>/dev/null || true

post-patch:
	@${REINPLACE_CMD} -e 's|ADD_SUBDIRECTORY(ADM_demuxers/VapourSynth)|# &|g' \
		${WRKSRC}/avidemux_plugins/CMakeLists.txt
	@${REINPLACE_CMD} -e 's|ADD_SUBDIRECTORY(VapourSynth)|# &|g' \
		${WRKSRC}/avidemux_plugins/ADM_demuxers/CMakeLists.txt

.include <bsd.port.post.mk>
