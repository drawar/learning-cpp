cmake_minimum_required(VERSION 3.6)
project(linked_list)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -v -stdlib=libstdc++")


set(SOURCE_FILES main.cpp LinkedList.h)
add_executable(linked_list ${SOURCE_FILES})
