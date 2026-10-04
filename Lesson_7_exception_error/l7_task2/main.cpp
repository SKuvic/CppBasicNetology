#include <iostream>
#include <string>

// Подключаем заголовочные файлы фигур и класса исключения
#include "Figure.h"
#include "Triangles.h"
#include "Quadrangles.h"
#include "bad_figure.h"     // Подключение кастомного исключения по заданию

// Вспомогательная функция для вывода фигур через указатель
void print_info_ptr(Figure* fig) {
    fig->print_info();
}

int main() {

    // =================================================================
    // ПОДЗАДАЧА 3: ИЕРАРХИЯ ФИГУР (С ОБРАБОТКОЙ ИСКЛЮЧЕНИЙ)
    // =================================================================
    std::cout << "===== [ЗАДАЧА 2: ИСКЛЮЧЕНИЯ В КОНСТРУКТОРАХ] =====" << std::endl << std::endl;
    
    // 1. Обычный треугольник
    try {
        Triangle tri(10, 20, 30, 50, 60, 70);
        print_info_ptr(&tri);
    } catch (const bad_figure& e) {
        std::cout << "Ошибка создания фигуры. Причина: " << e.get_reason() << std::endl;
    }

    // 2. Прямоугольный треугольник
    try {
        Tri_Rect tri_rect(10, 20, 30, 50, 60);
        print_info_ptr(&tri_rect);
    } catch (const bad_figure& e) {
        std::cout << "Ошибка создания фигуры. Причина: " << e.get_reason() << std::endl;
    }

    // 3. Равнобедренный треугольник
    try {
        Tri_Isos tri_isos(10, 20, 50, 60);
        print_info_ptr(&tri_isos);
    } catch (const bad_figure& e) {
        std::cout << "Ошибка создания фигуры. Причина: " << e.get_reason() << std::endl;
    }

    // 4. Равносторонний треугольник
    try {
        Tri_equila tri_eq(30);
        print_info_ptr(&tri_eq);
    } catch (const bad_figure& e) {
        std::cout << "Ошибка создания фигуры. Причина: " << e.get_reason() << std::endl;
    }

    // 5. Четырёхугольник
    try {
        Quadrangle quad(10, 20, 30, 40, 50, 60, 70, 80);
        print_info_ptr(&quad);
    } catch (const bad_figure& e) {
        std::cout << "Ошибка создания фигуры. Причина: " << e.get_reason() << std::endl;
    }

    // 6. Пнямоугольный четырехугольник (Прямоугольник)
    try {
        Rectangle rect(10, 20);
        print_info_ptr(&rect);
    } catch (const bad_figure& e) {
        std::cout << "Ошибка создания фигуры. Причина: " << e.get_reason() << std::endl;
    }

    // 7. Квадрат
    try {
        Square sq(20);
        print_info_ptr(&sq);
    } catch (const bad_figure& e) {
        std::cout << "Ошибка создания фигуры. Причина: " << e.get_reason() << std::endl;
    }

    // 8. Параллелограмм
    try {
        Parallel par(20, 30, 30, 40);
        print_info_ptr(&par);
    } catch (const bad_figure& e) {
        std::cout << "Ошибка создания фигуры. Причина: " << e.get_reason() << std::endl;
    }

    // 9. Ромб
    try {
        Diamond dia(30, 30, 40);
        print_info_ptr(&dia);
    } catch (const bad_figure& e) {
        std::cout << "Ошибка создания фигуры. Причина: " << e.get_reason() << std::endl;
    }

    return 0;
}
