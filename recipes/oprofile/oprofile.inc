SUMMARY = "System-Wide Profiler"
DESCRIPTION = "OProfile is a system-wide profiler for Linux systems, capable \
of profiling all running code at low overhead."
HOMEPAGE = "http://oprofile.sourceforge.net/news/"
BUGTRACKER = "http://sourceforge.net/tracker/?group_id=16191&atid=116191"

LICENSE = "LGPL-2.1+ & GPL-2.0"

inherit autotools pkgconfig c++

DEPENDS = "libpopt binutils-dev kernel-dev"

FILES_${PN} = "${bindir} ${libdir}/${PN}/lib*${SOLIBS} ${datadir}/${PN}"
FILES_${PN}-dev += "${libdir}/${PN}/lib*${SOLIBSDEV} ${libdir}/${PN}/lib*.la"
FILES_${PN}-staticdev += "${libdir}/${PN}/lib*.a"

SRC_URI += "file://opstart.patch"

EXTRA_OECONF = "--with-kernel=${HOST_SYSROOT}${kernelsrcdir} --without-x"

inherit auto-package-utils
AUTO_PACKAGE_UTILS = "opannotate oparchive op-check-perfevents \
	opcontrol opgprof ophelp opimport opjitconv opreport oprofiled"
AUTO_PACKAGE_UTILS_DEPENDS = "libc"
AUTO_PACKAGE_UTILS_RDEPENDS = "${PN} libc"
DEPENDS_${PN}-opannotate += "libbfd libgcc-s libm libpopt libstdc++"
RDEPENDS_${PN}-opannotate += "libbfd libgcc-s libm libpopt libstdc++"
DEPENDS_${PN}-oparchive += "libbfd libgcc-s libm libpopt libstdc++"
RDEPENDS_${PN}-oparchive += "libbfd libgcc-s libm libpopt libstdc++"
DEPENDS_${PN}-op-check-perfevents += "libpopt"
RDEPENDS_${PN}-op-check-perfevents += "libpopt"
DEPENDS_${PN}-opgprof += "libbfd libgcc-s libm libpopt libstdc++"
RDEPENDS_${PN}-opgprof += "libbfd libgcc-s libm libpopt libstdc++"
DEPENDS_${PN}-ophelp += "libpopt"
RDEPENDS_${PN}-ophelp += "libpopt"
DEPENDS_${PN}-opimport += "libgcc-s libm libpopt libstdc++"
RDEPENDS_${PN}-opimport += "libgcc-s libm libpopt libstdc++"
DEPENDS_${PN}-opjitconv += "libbfd"
RDEPENDS_${PN}-opjitconv += "libbfd"
DEPENDS_${PN}-opreport += "libbfd libgcc-s libm libpopt libstdc++"
RDEPENDS_${PN}-opreport += "libbfd libgcc-s libm libpopt libstdc++"
DEPENDS_${PN}-oprofiled += "libpopt"
RDEPENDS_${PN}-oprofiled += "libpopt"

inherit auto-package-libs
AUTO_PACKAGE_LIBS = "opagent"
AUTO_PACKAGE_LIBS_LIBDIR = "${libdir}/oprofile:lib::.so.*:.so,.la,.a"
DEPENDS_${PN}-libopagent += "libbfd libc"
RDEPENDS_${PN}-libopagent += "libbfd libc"
FILES_${PN}-libopagent-dev += "${includedir}/opagent.h"
