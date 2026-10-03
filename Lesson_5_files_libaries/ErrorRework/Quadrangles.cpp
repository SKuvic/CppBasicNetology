#include "Quadrangles.h"
#include <iostream>

Quadrangle::Quadrangle(int a_dim, int b_dim, int c_dim, int d_dim, int A_deg, int B_deg, int C_deg, int D_deg) {
    sides_count = 4;
    name = "Четырехугольник";
    a = a_dim; b = b_dim; c = c_dim; d = d_dim;
    A = A_deg; B = B_deg; C = C_deg; D = D_deg;
}
void Quadrangle::print_info() {
    std::cout << name << " : " << std::endl;
    std::cout << "Стороны: " << "a=" << a << " b=" << b << " c=" << c << " d=" << d << std::endl;
    std::cout << "Углы: " << "A=" << A << " B=" << B << " C=" << C << " D=" << D << std::endl;
}
Rectangle::Rectangle(int side_AC, int side_BD) : Quadrangle(side_AC, side_BD, side_AC, side_BD, 90, 90, 90, 90) {
    name = "Прямоугольник";
}
Parallel::Parallel(int side_AC, int side_BD, int angle_AC, int angle_BD) : Quadrangle(side_AC, side_BD, side_AC, side_BD, angle_AC, angle_BD, angle_AC, angle_BD) {
    name = "Параллелограмм";
}
Square::Square(int side_ABCD) : Quadrangle(side_ABCD, side_ABCD, side_ABCD, side_ABCD, 90, 90, 90, 90) {
    name = "Квадрат";
}
Diamond::Diamond(int side_ABCD, int angle_AC, int angle_BD) : Quadrangle(side_ABCD, side_ABCD, side_ABCD, side_ABCD, angle_AC, angle_BD, angle_AC, angle_BD) {
    name = "Ромб";
}
