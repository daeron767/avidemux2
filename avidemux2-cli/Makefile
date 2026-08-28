PORTNAME=	avidemux2
PKGNAMESUFFIX=	-cli
PORTVERSION=	${AVIDEMUX_VERSION}
CATEGORIES=	multimedia
MAINTAINER=	multimedia@test
COMMENT=	Simple video editor – command line interface (Qt6 generation)
WWW=		https://avidemux.org/

.include "${.CURDIR}/../avidemux2/Makefile.common"

# LIB_DEPENDS=	libADM6avutil.so.${DISTVERSION:C/.*\.//:S/g/./}:multimedia/avidemux2
LIB_DEPENDS=	libADM6avutil.so.59:multimedia/avidemux2

CMAKE_SOURCE_PATH=	${WRKSRC}/avidemux/cli
CMAKE_ARGS+=	-DADM_CORE_INCLUDE_DIR=${LOCALBASE}/include/avidemux/2.8

# Point CMake at the core headers that live in the source tree
CMAKE_ARGS+=	-DCMAKE_INSTALL_PREFIX=${LOCALBASE}
CMAKE_ARGS+=	-DADM_INSTALL_DIR=${LOCALBASE}
CMAKE_ARGS+=	-DAVIDEMUX_INCLUDE_DIR=${WRKSRC}/../avidemux2/work/avidemux2-c7fd884/avidemux_core
# or more robustly (preferred):
CMAKE_ARGS+=	-DCMAKE_PREFIX_PATH=${WRKSRC}/../avidemux2/work/avidemux2-c7fd884

.include <bsd.port.post.mk>
