cmake_minimum_required(VERSION 3.16)

# Project Name
project(Algorithms VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories( BackTracking BinarySearch DivideAndConquer Recursion SlidingWindow TwoPointers Strings Sorting Subset)
add_subdirectory(Tests)
