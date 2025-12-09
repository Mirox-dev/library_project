cmake_minimum_required(VERSION 4.0)
project(library_project)

set(CMAKE_CXX_STANDARD 17)

include_directories(src)

add_executable(library_project
        src/Book.cpp
        src/Library.cpp
        src/main.cpp
        src/User.cpp)
