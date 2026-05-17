cmake_minimum_required(VERSION 3.14)
project(banking)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(banking STATIC
    Account.cpp
    Transaction.cpp
)

target_include_directories(banking PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
