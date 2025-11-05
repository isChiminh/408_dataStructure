cmake_minimum_required(VERSION 4.0)
project(408_dataStructure)

set(CMAKE_CXX_STANDARD 20)

add_executable(408_dataStructure main.cpp
        src/datastructures/linked_list.cpp
        include/datastructures/linked_list.hpp
        include/datastructures/node.hpp
        src/datastructures/array_stack.cpp
        include/datastructures/array_stack.hpp
        src/datastructures/linked_stack.cpp
        include/datastructures/linked_stack.hpp
        src/datastructures/array_queue.cpp
        include/datastructures/array_queue.hpp
        src/datastructures/linked_queue.cpp
        include/datastructures/linked_queue.hpp
        include/algorithms/bracket_matching.hpp
        src/algorithms/bracket_matching.cpp
        src/algorithms/expression_utils.cpp
        include/algorithms/expression_utils.hpp

)
