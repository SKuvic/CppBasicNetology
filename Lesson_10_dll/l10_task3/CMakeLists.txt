cmake_minimum_required(VERSION 3.15)
project(LeaverSolution)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 1. СОЗДАНИЕ ДИНАМИЧЕСКОЙ БИБЛИОТЕКИ (DLL)
add_library(LeaverLib SHARED 
    LeaverLib/Leaver.h 
    LeaverLib/Leaver.cpp
)

# 2. СОЗДАНИЕ ПРОГРАММЫ-КЛИЕНТА (.EXE)
add_executable(LeaverClient LeaverClient/main.cpp)

# 3. СВЯЗЫВАНИЕ И НАСТРОЙКА ПУТЕЙ
target_include_directories(LeaverClient PRIVATE LeaverLib)
target_link_libraries(LeaverClient PRIVATE LeaverLib)
