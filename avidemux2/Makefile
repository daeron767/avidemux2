PORTNAME=	avidemux2
PORTVERSION=	${AVIDEMUX_VERSION}
CATEGORIES=	multimedia
MAINTAINER=	multimedia@test
COMMENT=	Simple video editor – core libraries (Qt6 generation)
WWW=		https://avidemux.org/

DISABLE_VULNERABILITIES=	yes

.include "${.CURDIR}/Makefile.common"

CMAKE_SOURCE_PATH=	${WRKSRC}/avidemux_core

post-configure: post-configure-common

.include <bsd.port.post.mk>
