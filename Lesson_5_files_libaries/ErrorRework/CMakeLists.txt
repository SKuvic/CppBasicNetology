cmake_minimum_required(VERSION 3.10)
project(Netology_Lesson_5_Final)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Собираем вместе .cpp файлы всех трех заданий
add_executable(final_program
    main.cpp
    FuncDescribe.cpp
    Counter.cpp
    Figure.cpp
    Triangles.cpp
    Quadrangles.cpp
)
