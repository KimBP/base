# -*- mode:python; -*-
DESCRIPTION = "A sophisticated network protocol analyzer"
HOMEPAGE = "http://www.tcpdump.org/"
LICENSE = "BSD"

RECIPE_TYPES = "machine"

inherit autotools

SRC_URI = "http://www.tcpdump.org/release/tcpdump-${PV}.tar.gz \
	file://tcpdump_configure_no_-O2.patch \
	file://0001-minimal-IEEE802.15.4-allowed.patch \
	file://ipv6-cross.patch \
	file://configure.patch \
"

DEPENDS = "libpcap"
RDEPENDS_${PN} = "libpcap"

EXTRA_OECONF = "--without-crypto"

RECIPE_FLAGS += "ipv6"
EXTRA_OECONF:>USE_ipv6 = " --enable-ipv6"

do_install_append() {
	# tcpdump 4.0.0 installs a copy to /usr/sbin/tcpdump.4.0.0
	rm -f ${D}${sbindir}/tcpdump.${PV}
}
