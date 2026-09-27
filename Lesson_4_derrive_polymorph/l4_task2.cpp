#include <iostream>
#include <fstream>



class Figure {                      //Основной класс
protected:
    int sides_count = 0;
    std::string name = "Фигура";
    //Длины сторон
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    //Углы
    int A = 0;
    int B = 0;
    int C = 0;
    int D = 0;

public:
    int get_sides_count () {
        return sides_count;
    }

    std::string get_name () {
        return name;
    }

    virtual void print_info () {
        std::cout << name << " : " << std::endl;
        std::cout << "Стороны: " << "a=" << a << " b=" << b << " c=" << c << " d=" << d << std::endl;
        std::cout << "Углы: " << "A=" << A << " B=" << B << " C=" << C << " D=" << D << std::endl;
 
    }
};


class Triangle : public Figure {        //класс Наследник Фигура-Треугольник
public:
    Triangle (int a_dim, int b_dim, int c_dim, int A_deg, int B_deg, int C_deg) {                   //Конструкт
        sides_count = 3;
        name = "Треугольник";

        a = a_dim;
        b = b_dim;
        c = c_dim;
        A = A_deg;
        B = B_deg;
        C = C_deg;
    }

    void print_info () {
    std::cout << name << " : " << std::endl;
    std::cout << "Стороны: " << "a=" << a << " b=" << b << " c=" << c << std::endl;
    std::cout << "Углы: " << "A=" << A << " B=" << B << " C=" << C << std::endl;
    }

};

class Tri_Rect : public Triangle {      //Наследник Фигура-Треугольник-Прямоугольный
public:
    Tri_Rect (int a, int b, int c, int A, int B)
        : Triangle (a, b, c, A, B, 90) {
        name = "Прямоугольный треугольник";
    }
};

class Tri_Isos : public Triangle {      //Наследник Треугольника
public:
    Tri_Isos (int side_ac, int side_b, int angle_AC, int angle_B) 
        : Triangle(side_ac, side_b, side_ac, angle_AC, angle_B, angle_AC) {
        name = "Равнобедренный треугольник";
    }

};

class Tri_equila : public Triangle {    //Наследник Треугольника
public:
    Tri_equila (int side)
        : Triangle (side, side, side, 60, 60, 60) {
        name = "Равносторонний треугольник";
    }
};


class Quadrangle : public Figure {      //Наследник Фигура-Четырехугольник
public:
    Quadrangle (int a_dim, int b_dim, int c_dim, int d_dim, int A_deg, int B_deg, int C_deg, int D_deg) {                   //Конструкт
        sides_count = 4;
        name = "Четырехугольник";

        a = a_dim;
        b = b_dim;
        c = c_dim;
        d = d_dim;
        A = A_deg;
        B = B_deg;
        C = C_deg;
        D = D_deg;
    }

    virtual void print_info () {
    std::cout << name << " : " << std::endl;
    std::cout << "Стороны: " << "a=" << a << " b=" << b << " c=" << c << " d=" << d << std::endl;
    std::cout << "Углы: " << "A=" << A << " B=" << B << " C=" << C << " D=" << D << std::endl;
    };

};

class Rectangle : public Quadrangle {
public:
    //Конструктор
    Rectangle  (int side_AC, int side_BD)
        : Quadrangle (side_AC, side_BD, side_AC, side_BD, 90, 90, 90, 90)
        {
        name = "Прямоугольник";
        }
};

class Parallel : public Quadrangle {
public:
    Parallel  (int side_AC, int side_BD, int angle_AC, int angle_BD)
        : Quadrangle (side_AC, side_BD, side_AC, side_BD,
                     angle_AC, angle_BD, angle_AC, angle_BD){
        name = "Параллелограмм";
    }

};

class Square : public Quadrangle {
public:
    Square  (int side_ABCD)
        : Quadrangle (side_ABCD, side_ABCD, side_ABCD, side_ABCD, 90, 90, 90, 90){
        name = "Квадрат";
    }

};

class Diamond : public Quadrangle {
public:
    Diamond  (int side_ABCD, int angle_AC, int angle_BD)
        : Quadrangle (side_ABCD, side_ABCD, side_ABCD, side_ABCD, angle_AC, angle_BD, angle_AC, angle_BD){
        name = "Ромб";
    }

};


    //Вызов Метода из Figure
void print_info (Figure* fig) {
    fig->print_info();
};



int main () {

    Triangle tri(10, 20, 30, 50, 60, 70);
    Tri_Rect tri_rect(10, 20, 30, 50, 60);
    Tri_Isos tri_isos(10, 20, 50, 60);
    Tri_equila tri_eq(30);

    Quadrangle quad(10, 20, 30, 40, 50, 60, 70, 80);
    Rectangle rect(10, 20);
    Square sq(20);
    Parallel par(20, 30, 30, 40);
    Diamond dia(30, 30, 40);

    print_info(&tri);
    print_info(&tri_rect);
    print_info(&tri_isos);
    print_info(&tri_eq);

    print_info(&quad);
    print_info(&rect);
    print_info(&sq);
    print_info(&par);
    print_info(&dia);

    return 0;
}