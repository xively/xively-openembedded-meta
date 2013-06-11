DESCRIPTION = "A small demo image with all Xively examples."

IMAGE_INSTALL = "packagegroup-core-boot ${ROOTFS_PKGMANAGE_BOOTSTRAP} ${CORE_IMAGE_EXTRA_INSTALL}"

IMAGE_LINGUAS = " "

LICENSE = "MIT"

inherit core-image

#IMAGE_ROOTFS_SIZE = "8192"

IMAGE_INSTALL += "\
  python-core \
  python-misc \
  python-crypt \
  python-readline \
  xively-python \
  python-pybbio \
  python-resource \
  git \
  strace \
"

IMAGE_FEATURES += "dev-pkgs"

# remove not needed ipkg informations
ROOTFS_POSTPROCESS_COMMAND += "remove_packaging_data_files ; "
