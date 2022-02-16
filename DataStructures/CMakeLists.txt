cmake_minimum_required(VERSION 3.20)

# Project Name
project(DataStructre VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories( Cache Graph HashMap Tree )
add_subdirectory(Tests)
