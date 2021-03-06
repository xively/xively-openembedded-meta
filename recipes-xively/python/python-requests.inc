DESCRIPTION = "Requests: HTTP for Humans"
HOMEPAGE = "http://docs.python-requests.org/en/latest/"
SECTION = "devel/python"
LICENSE = "Apache-2.0"

#DEPENDS = "python-core"
RDEPENDS_${PN} = "python"
PR = "r0"

SRC_URI = "git://github.com/kennethreitz/requests;protocol=git"

S = "${WORKDIR}/git/"

inherit setuptools

# need to export these variables for python-config to work
export BUILD_SYS
export HOST_SYS
export STAGING_INCDIR
export STAGING_LIBDIR

BBCLASSEXTEND = "native"

do_install_append() {
  rm -f ${D}${libdir}/python*/site-packages/site.py*
}
