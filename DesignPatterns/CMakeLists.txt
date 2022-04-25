cmake_minimum_required(VERSION 3.16)

# Project Name
project(DesignPatterns VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB_RECURSE SOURCES *[!Tests]/*.cc)
file(GLOB INC LIST_DIRECTORIES true *[!Tests]/*)

set(SOURCES ${SOURCES})

add_library(design-patterns STATIC ${SOURCES})
target_include_directories(design-patterns PUBLIC ${INC})
add_subdirectory(Tests)
