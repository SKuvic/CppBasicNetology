#include "Figure.h"
#include <iostream>

int Figure::get_sides_count() { return sides_count; }
std::string Figure::get_name() { return name; }
void Figure::print_info() {
    std::cout << name << " : " << std::endl;
    std::cout << "Стороны: " << "a=" << a << " b=" << b << " c=" << c << " d=" << d << std::endl;
    std::cout << "Углы: " << "A=" << A << " B=" << B << " C=" << C << " D=" << D << std::endl;
}
