cmake_minimum_required (VERSION 3.10)
project(filter)

file(GLOB filter_headers ./src/filter/*.hpp)

add_library(filter INTERFACE)
add_library(steinwurf::filter ALIAS filter)

target_include_directories(filter INTERFACE src/)

install(FILES ${filter_headers} DESTINATION ${CMAKE_INSTALL_PREFIX}/include/filter)
