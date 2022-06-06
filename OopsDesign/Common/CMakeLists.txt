cmake_minimum_required(VERSION 3.15)

# Project Name, TODO Make sure to change this
project(OopsCommon VERSION 1.0)

# Add config file, can be used to specify VERSION
#configure_file(version.h.in version.h)

set(PLIB ${PROJECT_NAME})

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB_RECURSE SOURCES src/*.cc)

# Library
add_library(${PLIB} STATIC ${SOURCES})
target_include_directories(${PLIB} PUBLIC inc "${CMAKE_SOURCE_DIR}/lib/tools/inc")

#add_subdirectory(tests)
