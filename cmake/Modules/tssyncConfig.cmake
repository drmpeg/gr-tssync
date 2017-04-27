INCLUDE(FindPkgConfig)
PKG_CHECK_MODULES(PC_TSSYNC tssync)

FIND_PATH(
    TSSYNC_INCLUDE_DIRS
    NAMES tssync/api.h
    HINTS $ENV{TSSYNC_DIR}/include
        ${PC_TSSYNC_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    TSSYNC_LIBRARIES
    NAMES gnuradio-tssync
    HINTS $ENV{TSSYNC_DIR}/lib
        ${PC_TSSYNC_LIBDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/lib
          ${CMAKE_INSTALL_PREFIX}/lib64
          /usr/local/lib
          /usr/local/lib64
          /usr/lib
          /usr/lib64
)

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(TSSYNC DEFAULT_MSG TSSYNC_LIBRARIES TSSYNC_INCLUDE_DIRS)
MARK_AS_ADVANCED(TSSYNC_LIBRARIES TSSYNC_INCLUDE_DIRS)

