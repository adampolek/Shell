cmake_minimum_required(VERSION 3.10)
project(myshell2 C)

set(CMAKE_C_STANDARD 99)

add_executable(myshell2 main.c function.h execute.c divide.c)