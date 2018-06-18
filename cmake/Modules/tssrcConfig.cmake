INCLUDE(FindPkgConfig)
PKG_CHECK_MODULES(PC_TSSRC tssrc)

FIND_PATH(
    TSSRC_INCLUDE_DIRS
    NAMES tssrc/api.h
    HINTS $ENV{TSSRC_DIR}/include
        ${PC_TSSRC_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    TSSRC_LIBRARIES
    NAMES gnuradio-tssrc
    HINTS $ENV{TSSRC_DIR}/lib
        ${PC_TSSRC_LIBDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/lib
          ${CMAKE_INSTALL_PREFIX}/lib64
          /usr/local/lib
          /usr/local/lib64
          /usr/lib
          /usr/lib64
)

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(TSSRC DEFAULT_MSG TSSRC_LIBRARIES TSSRC_INCLUDE_DIRS)
MARK_AS_ADVANCED(TSSRC_LIBRARIES TSSRC_INCLUDE_DIRS)

