cmake_minimum_required (VERSION 3.10)
project(filter)

add_library(filter INTERFACE)
add_library(steinwurf::filter ALIAS filter)

target_include_directories(filter INTERFACE src/)
