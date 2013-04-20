DESCRIPTION = "Python library for Arduino-style hardware IO support on the TI Beaglebone."
HOMEPAGE = "https://github.com/alexanderhiam/PyBBIO/wiki"
SECTION = "devel/python"
LICENSE = "Apache-2.0"

RDEPENDS_${PN} = "python"
PR = "r0"

SRC_URI = "git://github.com/alexanderhiam/PyBBIO;protocol=git"

S = "${WORKDIR}/git/"

inherit distutils

# need to export these variables for python-config to work
export BUILD_SYS
export HOST_SYS
export STAGING_INCDIR
export STAGING_LIBDIR

BBCLASSEXTEND = "native"

do_install_append() {
  rm -f ${D}${libdir}/python*/site-packages/site.py*
}
