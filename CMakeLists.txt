cmake_minimum_required(VERSION 3.8)
project(BinaryTree)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp BinaryTree.cpp Heap.cpp AVLTree.h AVLTree.cpp)
add_executable(BinaryTree ${SOURCE_FILES})