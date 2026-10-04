#include "Quadrangles.h"
#include "bad_figure.h" // EXCEPTION-FILE
#include <iostream>

Quadrangle::Quadrangle(int a_dim, int b_dim, int c_dim, int d_dim, int A_deg, int B_deg, int C_deg, int D_deg) {
    sides_count = 4;
    name = "Четырехугольник";
    a = a_dim; b = b_dim; c = c_dim; d = d_dim;
    A = A_deg; B = B_deg; C = C_deg; D = D_deg;

    // Ограничение: сумма углов равна 360
    if ((A + B + C + D) != 360) {
        throw bad_figure("сумма углов не равна 360");
    }
}

void Quadrangle::print_info() {
    std::cout << name << " (стороны " << a << ", " << b << ", " << c << ", " << d 
              << "; углы " << A << ", " << B << ", " << C << ", " << D << ") создан успешно" << std::endl;
}

Rectangle::Rectangle(int side_AC, int side_BD) : Quadrangle(side_AC, side_BD, side_AC, side_BD, 90, 90, 90, 90) {
    name = "Прямоугольник";
    // Ограничение: стороны попарно равны, все углы равны 90
    if (a != c || b != d || A != 90 || B != 90 || C != 90 || D != 90) {
        throw bad_figure("стороны попарно не равны или углы не равны 90");
    }
}

Parallel::Parallel(int side_AC, int side_BD, int angle_AC, int angle_BD) : Quadrangle(side_AC, side_BD, side_AC, side_BD, angle_AC, angle_BD, angle_AC, angle_BD) {
    name = "Параллелограмм";
    // Ограничение: стороны попарно равны, углы попарно равны
    if (a != c || b != d || A != C || B != D) {
        throw bad_figure("стороны попарно не равны или углы попарно не равны");
    }
}

Square::Square(int side_ABCD) : Quadrangle(side_ABCD, side_ABCD, side_ABCD, side_ABCD, 90, 90, 90, 90) {
    name = "Квадрат";
    // Ограничение: все стороны равны, все углы равны 90
    if (a != b || b != c || c != d || A != 90 || B != 90 || C != 90 || D != 90) {
        throw bad_figure("все стороны должны быть равны, а углы равны 90");
    }
}

Diamond::Diamond(int side_ABCD, int angle_AC, int angle_BD) : Quadrangle(side_ABCD, side_ABCD, side_ABCD, side_ABCD, angle_AC, angle_BD, angle_AC, angle_BD) {
    name = "Ромб";
    // Ограничение: все стороны равны, углы попарно равны
    if (a != b || b != c || c != d || A != C || B != D) {
        throw bad_figure("все стороны должны быть равны или углы попарно не равны");
    }
}
