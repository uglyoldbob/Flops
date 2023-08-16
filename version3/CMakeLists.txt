cmake_minimum_required(VERSION 3.9)
project(cpuload VERSION 1.0.1 DESCRIPTION "cpu load library")
include(GNUInstallDirs)
SET( CMAKE_CXX_EXTENSIONS OFF )
add_library(cpuload STATIC Source/load.cpp Source/Benchmark.cpp)
set_property(TARGET cpuload PROPERTY CXX_STANDARD 11)
set_property(TARGET cpuload PROPERTY CXX_STANDARD_REQUIRED ON)
set_target_properties(cpuload PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION 1
    PUBLIC_HEADER api/cpuload.h)
configure_file(cpuload.pc.in cpuload.pc @ONLY)
target_include_directories(cpuload PRIVATE .)
install(TARGETS cpuload
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(FILES ${CMAKE_BINARY_DIR}/cpuload.pc
    DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/pkgconfig)
