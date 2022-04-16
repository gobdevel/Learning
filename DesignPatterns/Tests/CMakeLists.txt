set(BINARY ${PROJECT_NAME}_tests)

file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES false *.h *.cpp *.cc)

add_executable(${BINARY} ${TEST_SOURCES})

add_test(NAME ${BINARY} COMMAND ${BINARY})
target_link_libraries(${BINARY} PUBLIC gtest gtest_main design-patterns)
target_include_directories(${BINARY} PUBLIC "${CMAKE_SOURCE_DIR}/Libs/tools/inc")
