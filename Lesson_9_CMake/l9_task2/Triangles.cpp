#include "Triangles.h"
#include <iostream>

Triangle::Triangle(int a_dim, int b_dim, int c_dim, int A_deg, int B_deg, int C_deg) {
    sides_count = 3;
    name = "Треугольник";
    a = a_dim; b = b_dim; c = c_dim;
    A = A_deg; B = B_deg; C = C_deg;
}
void Triangle::print_info() {
    std::cout << name << " : " << std::endl;
    std::cout << "Стороны: " << "a=" << a << " b=" << b << " c=" << c << std::endl;
    std::cout << "Углы: " << "A=" << A << " B=" << B << " C=" << C << std::endl;
}
Tri_Rect::Tri_Rect(int a, int b, int c, int A, int B) : Triangle(a, b, c, A, B, 90) {
    name = "Пнямоугольный треугольник";
}
Tri_Isos::Tri_Isos(int side_ac, int side_b, int angle_AC, int angle_B) : Triangle(side_ac, side_b, side_ac, angle_AC, angle_B, angle_AC) {
    name = "Равнобедренный треугольник";
}
Tri_equila::Tri_equila(int side) : Triangle(side, side, side, 60, 60, 60) {
    name = "Равносторонний треугольник";
}
