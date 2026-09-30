PORTNAME=	avidemux2
PKGNAMESUFFIX=	-plugins

COMMENT=	Avidemux plugins for decode, encode, filters, and sundry
DESCR=		${MASTERDIR}/pkg-descr
PKGDIR=		${.CURDIR}
PLIST=		${.CURDIR}/pkg-plist
MASTERDIR=	${.CURDIR}/../avidemux2
OPTIONS_NAME=	multimedia_avidemux2

LIB_DEPENDS=	libADM_core6.so:multimedia/avidemux2 \
		libADM_UI_Cli6.so:multimedia/avidemux2-cli \
		libADM_render6_cli.so:multimedia/avidemux2-cli \
		libADM_UIQT66.so:multimedia/avidemux2-qt6 \
		libADM_render6_QT6.so:multimedia/avidemux2-qt6 \
		libADM_openGLQT66.so:multimedia/avidemux2-qt6 \
		libxkbcommon.so:x11/libxkbcommon

USES=		gl qt:6
USE_GL=		gl glu opengl
USE_QT=		base tools:build

PLUGIN_UI=	COMMON SETTINGS CLI QT4

CMAKE_ARGS+=	-DAVIDEMUX_SOURCE_DIR=${WRKSRC} \
		-DPLUGIN_UI="${PLUGIN_UI}" \
		-DENABLE_QT6=ON \
		-DENABLE_QT5=OFF \
		-DVAPOURSYNTH:BOOL=OFF \
		-DADM_INSTALL_HEADERS:BOOL=OFF

post-extract:
	@${MKDIR} ${WRKSRC}/cmake
	@${ECHO_CMD} "macro(checkGtk)" > ${WRKSRC}/cmake/admCheckGtk.cmake
	@${ECHO_CMD} "  message(STATUS \"GTK support disabled\")" >> ${WRKSRC}/cmake/admCheckGtk.cmake
	@${ECHO_CMD} "endmacro()" >> ${WRKSRC}/cmake/admCheckGtk.cmake
	@${CP} -R ${WRKSRC}/avidemux/qt4/cmake/* ${WRKSRC}/cmake/ 2>/dev/null || ${TRUE}
	@${CP} ${WRKSRC}/avidemux/qt4/cmake/admCheckQt*.cmake ${WRKSRC}/cmake/ 2>/dev/null || ${TRUE}

post-patch-VAPOURSYNTH-off:
	@${REINPLACE_CMD} -e 's|ADD_SUBDIRECTORY(ADM_demuxers/VapourSynth)|# &|g' \
		${WRKSRC}/avidemux_plugins/CMakeLists.txt
	@${REINPLACE_CMD} -e 's|ADD_SUBDIRECTORY(VapourSynth)|# &|g' \
		${WRKSRC}/avidemux_plugins/ADM_demuxers/CMakeLists.txt

post-install:
	@${RM} -r ${STAGEDIR}${PREFIX}/include/avidemux

.include "${MASTERDIR}/Makefile"

# --- OVERRIDE MASTER CMAKE PATHS AFTER INCLUDE ---
CMAKE_SOURCE_PATH:=	${WRKSRC}/avidemux_plugins
BUILD_WRKSRC:=		${WRKDIR}/.build
CONFIGURE_WRKSRC:=	${WRKDIR}/.build
