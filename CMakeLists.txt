cmake_minimum_required(VERSION 3.28)
project(cppAssembly)

set(CMAKE_CXX_STANDARD 26)

add_executable(cppAssembly main.cpp
        commons.cpp
        header/commons.h
        multithreading.cpp
        header/multithreading.h
        header/assembly.h
        assembly.cpp
)
