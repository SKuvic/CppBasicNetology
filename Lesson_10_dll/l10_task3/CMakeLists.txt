cmake_minimum_required(VERSION 3.15)
project(LeaverSolution)

# Говорим CMake использовать современный стандарт C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ==========================================
# 1. СОЗДАНИЕ ДИНАМИЧЕСКОЙ БИБЛИОТЕКИ (DLL)
# ==========================================
# Ключевое слово SHARED означает, что соберется именно .dll (или .so на Linux)
add_library(LeaverLib SHARED 
    LeaverLib/Leaver.h 
    LeaverLib/Leaver.cpp
)

# ==========================================
# 2. СОЗДАНИЕ ПРОГРАММЫ-КЛИЕНТА (.EXE)
# ==========================================
add_executable(LeaverClient LeaverClient/main.cpp)

# ==========================================
# 3. СВЯЗЫВАНИЕ И НАСТРОЙКА ПУТЕЙ (Автомагия CMake)
# ==========================================

# Указываем клиенту, где искать заголовочный файл Leaver.h (Шаг 2 из Visual Studio)
target_include_directories(LeaverClient PRIVATE LeaverLib)

# Связываем клиента с библиотекой (Шаг 3 из Visual Studio)
# CMake сам подкинет нужный .lib файл и настроит зависимости!
target_link_libraries(LeaverClient PRIVATE LeaverLib)
