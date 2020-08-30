cmake_minimum_required(VERSION 3.16.1)
project(argparse)

include_directories(include)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_C_COMPILER /usr/local/opt/llvm/bin/clang)
set(CMAKE_CXX_COMPILER /usr/local/opt/llvm/bin/clang++)

add_executable(${PROJECT_NAME} src/argparse.cpp include/argparse.hpp)

find_package(Catch2 REQUIRED)
add_executable(test_executable test.cpp)
target_link_libraries(test_executable Catch2::Catch2)
