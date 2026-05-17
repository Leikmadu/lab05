cmake_minimum_required(VERSION 3.14)
project(lab05)

option(BUILD_TESTS "Build tests" OFF)
option(COVERAGE "Enable coverage reporting" OFF)

add_subdirectory(banking)

if(COVERAGE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage -O0 -g")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} --coverage -O0 -g")
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
    
    add_executable(banking_tests
        banking/tests/test_account.cpp
        banking/tests/test_transaction.cpp
    )
    
    target_link_libraries(banking_tests banking gtest_main gmock_main)
    target_include_directories(banking_tests PRIVATE banking)
    
    add_test(NAME banking_tests COMMAND banking_tests)
endif()
