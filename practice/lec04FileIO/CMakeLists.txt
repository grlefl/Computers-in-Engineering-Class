cmake_minimum_required(VERSION 3.14)
project(lec04FileIO)

set(CMAKE_CXX_STANDARD 14)

configure_file(data.txt data.txt COPYONLY)

add_executable(lec04FileIO main.cpp)