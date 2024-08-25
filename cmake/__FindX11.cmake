if(CMAKE_CROSSCOMPILING) # TODO: allow for other architectures
    message(STATUS "FindX11.cmake: Cross-compiling for aarch64")
    if(DEFINED CMAKE_SYSROOT)
        message(STATUS "FindX11.cmake: Using SYSROOT: ${CMAKE_SYSROOT}")
        set(X11_SEARCH_PATHS
            "${CMAKE_SYSROOT}/usr"
            "${CMAKE_SYSROOT}/usr/local"
            "${CMAKE_SYSROOT}/opt"
        )
    else()
        set(X11_SEARCH_PATHS
            "/usr/aarch64-linux-gnu"
            "/usr/local/aarch64-linux-gnu"
            "/opt/aarch64-linux-gnu"
        )
    endif()
else()
    message(STATUS "FindX11.cmake: Compiling for native architecture")
endif()

find_library(X11_LIBRARY
    NAMES X11
    PATHS ${X11_SEARCH_PATHS}
    PATH_SUFFIXES lib
)
message(STATUS "FindX11.cmake: X11_LIBRARY: ${X11_LIBRARY}")


find_path(X11_INCLUDE_DIR
    NAMES Xlib.h
    PATHS ${X11_SEARCH_PATHS})
    PATH_SUFFIXES include/X11