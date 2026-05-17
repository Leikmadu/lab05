cmake_minimum_required(VERSION 3.14)
project(print)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(BUILD_EXAMPLES "Build examples" OFF)
option(BUILD_TESTS "Build tests" OFF)

add_library(print STATIC ${CMAKE_CURRENT_SOURCE_DIR}/sources/print.cpp)
target_include_directories(print PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

if(BUILD_EXAMPLES)
  add_executable(example1 ${CMAKE_CURRENT_SOURCE_DIR}/examples/example1.cpp)
  add_executable(example2 ${CMAKE_CURRENT_SOURCE_DIR}/examples/example2.cpp)
  target_link_libraries(example1 print)
  target_link_libraries(example2 print)
endif()

if(BUILD_TESTS)
  enable_testing()
  
  include(FetchContent)
  FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.12.1
  )
  FetchContent_MakeAvailable(googletest)
  
  file(GLOB TEST_SOURCES tests/*.cpp)
  add_executable(check ${TEST_SOURCES})
  
  # Правильная линковка с GTest
  target_link_libraries(check print GTest::gtest_main)
  
  add_test(NAME check COMMAND check)
endif()
