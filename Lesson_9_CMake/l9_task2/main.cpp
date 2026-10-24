#include <iostream>
#include <string>

// Подключаем заголовочные файлы ВСЕХ трех подзадач
#include "Figure.h"
#include "Triangles.h"
#include "Quadrangles.h"

// Вспомогательная функция для вывода фигур через указатель
void print_info_ptr(Figure* fig) {
    fig->print_info();
}

int main() {

    // =================================================================
    // ПОДЗАДАЧА 3: ИЕРАРХИЯ ФИГУР
    // =================================================================
    std::cout << "===== [ПОДЗАДАЧА 3: ФИГУРЫ] =====" << std::endl;
    
    Triangle tri(10, 20, 30, 50, 60, 70);
    Tri_Rect tri_rect(10, 20, 30, 50, 60);
    Tri_Isos tri_isos(10, 20, 50, 60);
    Tri_equila tri_eq(30);

    Quadrangle quad(10, 20, 30, 40, 50, 60, 70, 80);
    Rectangle rect(10, 20);
    Square sq(20);
    Parallel par(20, 30, 30, 40);
    Diamond dia(30, 30, 40);

    print_info_ptr(&tri);
    print_info_ptr(&tri_rect);
    print_info_ptr(&tri_isos);
    print_info_ptr(&tri_eq);

    print_info_ptr(&quad);
    print_info_ptr(&rect);
    print_info_ptr(&sq);
    print_info_ptr(&par);
    print_info_ptr(&dia);

    return 0;
}
