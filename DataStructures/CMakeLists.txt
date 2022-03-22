cmake_minimum_required(VERSION 3.16)

# Project Name
project(DataStructre VERSION 1.0)

#file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.cpp *.cc)
#set(SOURCES ${SOURCES})

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories( Cache Graph HashMap Tree LinkList)
add_subdirectory(Tests)

#add_library(${BINARY} STATIC ${SOURCES})
