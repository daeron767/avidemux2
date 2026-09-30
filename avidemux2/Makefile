PORTNAME=	avidemux2
DISTVERSION=	2.8.2.g20260825
CATEGORIES=	multimedia

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Frame-accurate video editor (core libraries)
WWW=		https://avidemux.org/

USE_LDCONFIG=	yes

MASTERDIR?=	${.CURDIR}
.include "${MASTERDIR}/Makefile.common"

CMAKE_SOURCE_PATH=	${WRKSRC}/avidemux_core

pre-configure:
	@${CP} ${_DISTDIR}/ffmpeg-7.0.2.tar.bz2 \
		${WRKSRC}/avidemux_core/ffmpeg_package/ffmpeg-7.0.2.tar.bz2

post-patch:
	@${MKDIR} ${CONFIGURE_WRKSRC}/config
	@${LN} -s ${LOCALBASE}/include/iconv.h ${CONFIGURE_WRKSRC}/config

.include <bsd.port.mk>
