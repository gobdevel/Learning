#cmake_minimum_required(VERSION 3.16)

# Project Name
project(AlgoPatterns VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.cc *.h)
list(FILTER SOURCES EXCLUDE REGEX ".*Tests.*$")
set(INC ${SOURCES})

list(FILTER SOURCES EXCLUDE REGEX ".*\.h$")
#message(STATUS "SOURCES : ${SOURCES}")

list(FILTER INC EXCLUDE REGEX ".*\\.(cc|h)$")
#message(STATUS "INC : ${INC}")

add_library(${PROJECT_NAME} STATIC ${SOURCES})
target_link_libraries(${PROJECT_NAME} PUBLIC DataStructures)
target_include_directories(${PROJECT_NAME} PUBLIC ${INC} "${CMAKE_SOURCE_DIR}/Libs/tools/inc")
add_subdirectory(Tests)
