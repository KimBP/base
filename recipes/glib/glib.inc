# -*- mode:python; -*-
require glib-common.inc

RECIPE_TYPES = "machine sdk"

inherit autotools pkgconfig

SRC_URI += "file://config.site"
SRC_HOST_SITEFILES = "${SRCDIR}/config.site"

EXTRA_OECONF += "${EXTRA_OECONF_STATIC}"
EXTRA_OECONF_STATIC = "--enable-static"
EXTRA_OECONF_STATIC:HOST_LIBC_mingw = ""

RECIPE_FLAGS += "ipv6"
EXTRA_OECONF += "${EXTRA_OECONF_IPV6}"
EXTRA_OECONF_IPV6 = "--disable-ipv6"
EXTRA_OECONF_IPV6:USE_ipv6 = ""

RECIPE_FLAGS += "glib_largefile"
EXTRA_OECONF += "${EXTRA_OECONF_LARGEFILE}"
EXTRA_OECONF_LARGEFILE = "--disable-largefile"
EXTRA_OECONF_LARGEFILE:USE_glib_largefile = ""

RECIPE_FLAGS += "glib_iconv"
EXTRA_OECONF += "${EXTRA_OECONF_ICONV}"
EXTRA_OECONF_ICONV = "--with-libiconv=no"
EXTRA_OECONF_ICONV:USE_glib_iconv = "--with-libiconv=gnu"
DEPENDS += "${DEPENDS_ICONV}"
DEPENDS_ICONV:USE_glib_iconv = "libiconv"

RECIPE_FLAGS += "glib_threads"
DEFAULT_USE_glib_threads = "1"
EXTRA_OECONF += "${EXTRA_OECONF_THREADS}"
EXTRA_OECONF_THREADS = "--disable-threads"
EXTRA_OECONF_THREADS_TYPE = "posix"
EXTRA_OECONF_THREADS_TYPE:HOST_OS_mingw32 = "win32"
EXTRA_OECONF_THREADS:USE_glib_threads = "--with-threads=${EXTRA_OECONF_THREADS_TYPE}"

DEPENDS += "${DEPENDS_THREADS}"
DEPENDS_THREADS_TYPE = "libpthread"
DEPENDS_THREADS_TYPE:HOST_OS_mingw32 = ""
DEPENDS_THREADS:USE_glib_threads = "${DEPENDS_THREADS_TYPE}"

RECIPE_FLAGS += "glib_fam"
EXTRA_OECONF += "${EXTRA_OECONF_FAM}"
EXTRA_OECONF_FAM = "--disable-fam"
EXTRA_OECONF_FAM:USE_glib_fam = ""
DEPENDS += "${DEPENDS_FAM}"
DEPENDS_FAM:USE_glib_fam = "libfam"

EXTRA_OECONF += "--with-pcre=system"
DEPENDS += "${DEPENDS_PCRE}"
DEPENDS_PCRE = "libpcre"
