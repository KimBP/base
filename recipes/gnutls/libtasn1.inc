DESCRIPTION = "Library for ASN.1 and DER manipulation"
HOMEPAGE = "http://www.gnu.org/software/libtasn1/"

require conf/fetch/gnu.conf

SRC_URI = "${GNU_MIRROR}/libtasn1/libtasn1-${PV}.tar.gz"

inherit autotools-autoreconf binconfig package library

inherit auto-package-utils
AUTO_PACKAGE_UTILS = "asn1Coding asn1Decoding asn1Parser"
DEPENDS_${PN} += "libc"
RDEPENDS_${PN} += "libc"
AUTO_PACKAGE_UTILS_DEPENDS = "libc libtasn1"
AUTO_PACKAGE_UTILS_RDEPENDS = "libc libtasn1"
