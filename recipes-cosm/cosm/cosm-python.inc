DESCRIPTION = "The official pythonic wrapper library for the Cosm V2 API."
HOMEPAGE = "https://cosm.com"
SECTION = "devel/python"
LICENSE = "BSD-3-Clause"

DEPENDS = "python-requests"
RDEPENDS_${PN} = "python-requests"
PR = "r0"

SRC_URI = "git://github.com/gnublade/cosm-python;protocol=git"

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
#do_install_append() {
#  rm -f ${D}${libdir}/python2.7/site-packages/site.py
#  rm -f ${D}${libdir}/python2.7/site-packages/site.pyo
#  rm -f ${D}${libdir}/python2.7/site-packages/site.pyc
#}
