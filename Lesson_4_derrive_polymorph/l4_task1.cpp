#include <iostream>
#include <fstream>


class Figure {
  
protected:
    int sides_count = 0;
    std::string name = "Фигура";

public:
    int get_sides_count () {
        return sides_count;
    }

    std::string get_name () {
        return name;
    }

};

class Triangle : public Figure {
public:
    Triangle () {                   //Конструкт
        sides_count = 3;
        name = "Треугольник";

    }
};

class Quadrangle : public Figure {
public:
    Quadrangle () {
        sides_count = 4;
        name = "Квадрат";

    }
};

int main () {
    Figure fig;
    Triangle tri;
    Quadrangle quad;

    std::cout << "Количество сторон:" << std::endl;
    std::cout << fig.get_name () << " : " << fig.get_sides_count () << std::endl;
    std::cout << tri.get_name () << " : " << tri.get_sides_count () << std::endl;
    std::cout << quad.get_name () << " : " << quad.get_sides_count () << std::endl;

    return 0;
}