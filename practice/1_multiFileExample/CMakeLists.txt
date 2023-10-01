cmake_minimum_required(VERSION 3.23)
project(1_multiFileExample)

set(CMAKE_CXX_STANDARD 14)

add_executable(1_multiFileExample main.cpp ComplexNumber.cpp ComplexNumber.h)
