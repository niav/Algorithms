cmake_minimum_required(VERSION 3.7)
project(Algorithms)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp algo.h algo.cpp utils.h utils.cpp)
add_executable(algo ${SOURCE_FILES})