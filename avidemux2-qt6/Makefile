PORTNAME=	avidemux2
PKGNAMESUFFIX=	-qt6

COMMENT=	Avidemux Qt6 interface for frame-accurate video editing
DESCR=		${MASTERDIR}/pkg-descr
PKGDIR=		${.CURDIR}
PLIST=		${.CURDIR}/pkg-plist
MASTERDIR=	${.CURDIR}/../avidemux2
OPTIONS_NAME=	multimedia_avidemux2

LIB_DEPENDS=	libADM_core6.so:multimedia/avidemux2 \
		libxkbcommon.so:x11/libxkbcommon

USES=		desktop-file-utils gl qt:6 sdl xorg
USE_GL=		gl glu opengl
USE_QT=		base tools:build
USE_SDL=	sdl2
USE_XORG=	xext xv
USE_LDCONFIG=	yes

CXXFLAGS+=	-I${LOCALBASE}/include/avidemux/2.8

CMAKE_ARGS+=	-DADM_SUBDIR:STRING=qt4 \
		-DENABLE_QT6:BOOL=ON \
		-DENABLE_QT5:BOOL=OFF \
		-DUI_DEV=QT6 \
		-DADM_CORE_INCLUDE_DIR:PATH=${LOCALBASE}/include/avidemux/2.8 \
		-DADM_CORE_LIB_DIR:PATH=${LOCALBASE}/lib \
		-DAVIDEMUX_INSTALL_PREFIX:PATH=${PREFIX} \
		-DADM_INSTALL_HEADERS:BOOL=OFF

OPTIONS_EXCLUDE=	NLS

post-extract:
	@${MKDIR} ${WRKSRC}/avidemux/qt4/i18n
	@${ECHO_CMD} "message(STATUS \"Skipping translations\")" > ${WRKSRC}/avidemux/qt4/i18n/CMakeLists.txt

post-install:
	${RMDIR} ${STAGEDIR}${PREFIX}/include/avidemux/2.8/cmake/osx 2>/dev/null || ${TRUE}

.include "${MASTERDIR}/Makefile"

# --- OVERRIDE MASTER CMAKE PATHS AFTER INCLUDE ---
CMAKE_SOURCE_PATH:=	${WRKSRC}/avidemux/qt4
BUILD_WRKSRC:=		${WRKDIR}/.build
CONFIGURE_WRKSRC:=	${WRKDIR}/.build

.if defined(PORT_OPTIONS) && (${PORT_OPTIONS:MOSS} || ${PORT_OPTIONS:MTINYPY})
.endif
