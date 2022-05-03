set(BINARY ${PROJECT_NAME}_tests)

file(GLOB_RECURSE SOURCES LIST_DIRECTORIES false *.h *.cpp *.cc)

add_executable(${BINARY} ${SOURCES})

#add_test(NAME ${BINARY} COMMAND ${BINARY})
target_link_libraries(${BINARY} PUBLIC gtest gtest_main ${PROJECT_NAME})
