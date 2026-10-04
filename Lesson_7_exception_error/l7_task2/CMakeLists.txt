cmake_minimum_required(VERSION 3.10)
project(CPP_BasicCource_Lesson7_task2)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Собираем вместе .cpp файлы всех трех заданий
add_executable(task2_program
    main.cpp
    Figure.cpp
    Triangles.cpp
    Quadrangles.cpp
    bad_figure.h
    bad_figure.cpp
)
