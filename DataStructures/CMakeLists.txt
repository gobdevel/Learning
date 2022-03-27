cmake_minimum_required(VERSION 3.16)

# Project Name
project(DataStructre VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB_RECURSE SOURCES Cache/*.cc Graph/*.cc HashMap/*.cc Tree/*.cc LinkList/*.cc Heap/*.cc)
set(SOURCES ${SOURCES})

add_library(data-structure STATIC ${SOURCES})
target_include_directories(data-structure PUBLIC Cache Graph HashMap Tree LinkList Heap)
add_subdirectory(Tests)
