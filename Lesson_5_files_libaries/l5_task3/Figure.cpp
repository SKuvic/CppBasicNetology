#include "HEAD.h"

// Методы базового класса Figure
int Figure::get_sides_count() { return sides_count; }
std::string Figure::get_name() { return name; }
void Figure::print_info() {
    std::cout << name << " : " << std::endl;
    std::cout << "Стороны: " << "a=" << a << " b=" << b << " c=" << c << " d=" << d << std::endl;
    std::cout << "Углы: " << "A=" << A << " B=" << B << " C=" << C << " D=" << D << std::endl;
}

// Реализация Triangle
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

// Реализация остальных треугольников
Tri_Rect::Tri_Rect(int a, int b, int c, int A, int B) : Triangle(a, b, c, A, B, 90) {
    name = "Прямоугольный треугольник";
}
Tri_Isos::Tri_Isos(int side_ac, int side_b, int angle_AC, int angle_B) : Triangle(side_ac, side_b, side_ac, angle_AC, angle_B, angle_AC) {
    name = "Равнобедренный треугольник";
}
Tri_equila::Tri_equila(int side) : Triangle(side, side, side, 60, 60, 60) {
    name = "Равносторонний треугольник";
}

// Реализация Quadrangle
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

// Реализация остальных четырехугольников
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
