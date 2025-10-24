cmake_minimum_required(VERSION 4.0)
project(408_dataStructure)

set(CMAKE_CXX_STANDARD 20)

add_executable(408_dataStructure main.cpp
        src/datastructures/linked_list.cpp
        include/datastructures/linked_list.hpp
        include/datastructures/node.hpp
)
