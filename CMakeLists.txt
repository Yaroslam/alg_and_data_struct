cmake_minimum_required(VERSION 3.21)
project(untitled2)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled2 main.cpp "array_sort/sorting.cpp" "array_sort/array_work.cpp" reverse_polish_notation/const.cpp reverse_polish_notation/algeb_operations.cpp reverse_polish_notation/calculator.cpp reverse_polish_notation/rpn_work.cpp)
