cmake_minimum_required(VERSION 3.7)
project(algo)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main_UF.cpp QuickFind.cpp QuickFind.h QuickUnion.cpp
        QuickUnion.h QuickUnionPathCompr.cpp QuickUnionPathCompr.h
        WeightedQuickUnion.cpp WeightedQuickUnion.h)
add_executable(algo ${SOURCE_FILES})