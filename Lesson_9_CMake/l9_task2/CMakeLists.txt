cmake_minimum_required(VERSION 3.10)
project(Lesson_9_CMake_task2)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Собираем вместе .cpp файлы всех трех заданий
add_executable(l9_task2
    main.cpp
    Figure.cpp
    Triangles.cpp
    Quadrangles.cpp
)
