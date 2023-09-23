cmake_minimum_required(VERSION 3.24)
project(lab3_sda)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(lab3_sda
        App.cpp
        ExtendedTest.cpp
        ExtendedTest.h
        Set.cpp
        Set.h
        SetIterator.cpp
        SetIterator.h
        ShortTest.cpp
        ShortTest.h)
