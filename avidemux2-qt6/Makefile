PORTNAME=	avidemux2
PKGNAMESUFFIX=	-qt6
PORTVERSION=	${AVIDEMUX_VERSION}
CATEGORIES=	multimedia
MAINTAINER=	multimedia@test
COMMENT=	Simple video editor – Qt6 interface
WWW=		https://avidemux.org/

.include "${.CURDIR}/../avidemux2/Makefile.common"

LIB_DEPENDS=	libADM6avutil.so.59:multimedia/avidemux2

USES+=		qt:6 gl
USE_QT=		base tools:build
USE_GL=		gl opengl

CMAKE_SOURCE_PATH=	${WRKSRC}/avidemux/qt4
CMAKE_ARGS+=	-DENABLE_QT6:BOOL=ON
CMAKE_ARGS+=	-DENABLE_QT5:BOOL=OFF
CMAKE_ARGS+=	-DENABLE_I18N:BOOL=OFF
CMAKE_ARGS+=    -DCMAKE_CXX_FLAGS="-I/usr/ports/multimedia/avidemux2/work/stage/usr/local/include/avidemux/2.8"

# Prevent the core’s post-extract from running
post-extract:
	@${TRUE}
	@if [ ! -f ${WRKSRC}/avidemux/qt4/i18n/CMakeLists.txt ]; then \
		${MKDIR} ${WRKSRC}/avidemux/qt4/i18n ; \
		${ECHO_CMD} "message(STATUS \"Skipping translations\")" > ${WRKSRC}/avidemux/qt4/i18n/CMakeLists.txt ; \
	fi

.include <bsd.port.post.mk>
