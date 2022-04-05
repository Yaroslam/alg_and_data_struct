cmake_minimum_required(VERSION 3.21)
project(untitled2)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled2 main.cpp "array_sort/sorting.cpp" "array_sort/array_work.cpp" data_struct/stack/Stack.cpp data_struct/list/singly_linked_list.cpp data_struct/list/twoside_linked_list.cpp data_struct/list/double_linked_list.cpp data_struct/tree/tree_bin.cpp data_struct/tree/black_red_tree.cpp data_struct/heap/heap.cpp)

