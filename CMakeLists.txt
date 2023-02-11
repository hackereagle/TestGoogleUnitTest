cmake_minimum_required(VERSION 3.11)
set(PROJECT_NAME TestGoogleUnitTest)
project(${PROJECT_NAME})

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-lstdc++ ${CMAKE_CXX_FLAGS}")

enable_testing()
find_package(GTest CONFIG REQUIRED)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} GTest::gtest)
#target_link_libraries(${PROJECT_NAME} GTest::gtest GTest::gtest_main GTest::gmock GTest::gmock_main)

#gtest_discover_tests(${PROJECT_NAME})

set(CMAKE_VERBOSE_MAKEFILE ON)