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

## This files is being found under in directory `PyBBIO-0.6-py2.7-linux-x86_64.egg`,
## there is probably a bug somewhere as it's not a `linux-x86_64` binary, it's
## still an ARM 32-bit one. May be it also needs to be move to make it usable...
FILES_${PN}-dbg += "${D}${libdir}/python*/site-packages/PyBBIO-*.egg/bbio/platform/beaglebone/.debug/driver.so"

do_install_append() {
  rm -f ${D}${libdir}/python*/site-packages/site.py*
}
