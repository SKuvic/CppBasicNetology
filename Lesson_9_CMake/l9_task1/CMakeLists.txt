cmake_minimum_required(VERSION 3.10)
project(my_first_cmake_project LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Используем имя файла из вашей вкладки: my_first_cmake_program.cpp вместо main.cpp
add_executable(my_first_cmake_program 
    my_first_cmake_program.cpp 
    Person.h 
    Person.cpp
)
