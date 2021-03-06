SUMMARY = "curl is a command line tool for transferring data with URL syntax"
DESCRIPTION = """
curl is a command line tool for transferring data with URL syntax, supporting DICT,
 FILE, FTP, FTPS, Gopher, HTTP, HTTPS, IMAP, IMAPS, LDAP, LDAPS, POP3, POP3S, RTMP,
 RTSP, SCP, SFTP, SMTP, SMTPS, Telnet and TFTP. curl supports SSL certificates,
 HTTP POST, HTTP PUT, FTP uploading, HTTP form based upload, proxies, cookies,
 user+password authentication (Basic, Digest, NTLM, Negotiate, kerberos...),
 file transfer resume, proxy tunneling and a busload of other useful tricks.
"""
HOMEPAGE = "http://curl.haxx.se/"

SRC_URI = "http://curl.haxx.se/download/${PN}-${PV}.tar.gz"

RECIPE_TYPES = "machine native"

inherit autotools library pkgconfig auto-package-utils

AUTO_PACKAGE_UTILS = "curl curl-config"

DEPENDS_${PN} = "libc libgcc"
RDEPENDS_${PN} = "libc libgcc"
DEPENDS_${PN}-curl = "libc libcurl"
RDEPENDS_${PN}-curl = "libc libcurl"
