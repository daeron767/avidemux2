PORTNAME=	avidemux2
PKGNAMESUFFIX=	-cli

COMMENT=	Avidemux CLI interface for frame-accurate video editing
DESCR=		${MASTERDIR}/pkg-descr
PKGDIR=		${.CURDIR}
PLIST=		${.CURDIR}/pkg-plist
MASTERDIR=	${.CURDIR}/../avidemux2
OPTIONS_NAME=	multimedia_avidemux2

LIB_DEPENDS=	libADM_core6.so:multimedia/avidemux2

USES=		pkgconfig

CXXFLAGS+=	-I${LOCALBASE}/include/avidemux/2.8

CMAKE_ARGS+=	-DADM_NO_CORE_INSTALL:BOOL=ON \
		-DAVIDEMUX_TOP_SOURCE_DIR:PATH=${WRKSRC} \
		-DADM_CORE_INCLUDE_DIR:PATH=${LOCALBASE}/include/avidemux/2.8 \
		-DENABLE_CLI=ON \
		-DUI_DEV=CLI \
		-DAVIDEMUX_INSTALL_PREFIX:PATH=${PREFIX} \
		-DADM_INSTALL_HEADERS=OFF

.include "${MASTERDIR}/Makefile"

# Working build parameters for the CLI component
CMAKE_SOURCE_PATH=	${WRKSRC}/avidemux/cli
BUILD_WRKSRC=		${WRKDIR}/.build
CONFIGURE_WRKSRC=	${WRKDIR}/.build

EXTRA_PATCHES=	${.CURDIR}/files/patch-avidemux_cli_ADM__UIs_src_CMakeLists.txt \
		${.CURDIR}/files/patch-avidemux_cli_ADM__render__cli_CMakeLists.txt

