#include "Triangles.h"
#include "bad_figure.h" //Добавлено по заданию 2 урока 7
#include <iostream>

Triangle::Triangle(int a_dim, int b_dim, int c_dim, int A_deg, int B_deg, int C_deg) {
    sides_count = 3;
    name = "Треугольник";
    a = a_dim; b = b_dim; c = c_dim;
    A = A_deg; B = B_deg; C = C_deg;

    //Ограничение по сумме углов. Задание 2 Урок 7
    if ((A+B+C) != 180) {
        throw bad_figure ("Сумма углов не равноа 180");
    }
    
}
void Triangle::print_info() {
    std::cout << name << " : " << std::endl;
    std::cout << "Стороны: " << "a=" << a << " b=" << b << " c=" << c << std::endl;
    std::cout << "Углы: " << "A=" << A << " B=" << B << " C=" << C << std::endl;
}
Tri_Rect::Tri_Rect(int a, int b, int c, int A, int B) : Triangle(a, b, c, A, B, 90) {
    name = "Пнямоугольный треугольник";

    //Ограничение по Углу С ЗАДАНИЕ 2 УРОК 7
    //==============================================
    if (C != 90) {
        throw bad_figure("угол C не равен 90 град");}

    //==============================================

}
Tri_Isos::Tri_Isos(int side_ac, int side_b, int angle_AC, int angle_B) : Triangle(side_ac, side_b, side_ac, angle_AC, angle_B, angle_AC) {
    name = "Равнобедренный треугольник";

    //Ограничение равенства сторон А=С и а=с ЗАДАНИЕ 2 УРОК 7
    //==============================================

     if (a != c || A != C) {
        throw bad_figure("стороны a и c или углы A и C не равны");}
    //==============================================

}
Tri_equila::Tri_equila(int side) : Triangle(side, side, side, 60, 60, 60) {
    name = "Равносторонний треугольник";
    //Ограничение равенства А=С, (a or b or c) = 60 grad ЗАДАНИЕ 2 УРОК 7
    //==============================================

     if (a != b || b != c || A != 60 || B != 60 || C != 60) {
        throw bad_figure("все стороны должны быть равны, а углы равны 60");}
    //==============================================

}
