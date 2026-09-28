#include <iostream>
#include <string>

class Figure {
protected:
    int sides_count = 0;
    std::string name = "Фигура";
    
    int a = 0; int b = 0; int c = 0; int d = 0;
    int A = 0; int B = 0; int C = 0; int D = 0;

public:
    virtual bool check() {
        if (sides_count == 0) {
            return true;
        } else {
            return false;
        }
    }

    virtual void print_info() {
        std::cout << name << ":" << std::endl;
        
        if (check() == true) {
            std::cout << "Правильная" << std::endl;
        } else {
            std::cout << "Неправильная" << std::endl;
        }
        
        std::cout << "Количество сторон: " << sides_count << std::endl;
    }
};


class Triangle : public Figure {
public:
    Triangle(int a_dim, int b_dim, int c_dim, int A_deg, int B_deg, int C_deg) {
        name = "Треугольник";
        sides_count = 3;
        a = a_dim; b = b_dim; c = c_dim;
        A = A_deg; B = B_deg; C = C_deg;
    }

    bool check() {
        if (A + B + C == 180) {
            return true;
        } else {
            return false;
        }
    }

    void print_info() {
        Figure::print_info(); 
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << std::endl;
        std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << std::endl;
    }
};

class Tri_Rect : public Triangle {
public:
    Tri_Rect(int a, int b, int c, int A, int B, int C) : Triangle(a, b, c, A, B, C) {
        name = "Прямоугольный треугольник";
    }

    bool check() {
        if (Triangle::check() == true && C == 90) {
            return true;
        } else {
            return false;
        }
    }
};

class Tri_Isos : public Triangle {
public:
    Tri_Isos(int a, int b, int c, int A, int B, int C) : Triangle(a, b, c, A, B, C) {
        name = "Равнобедренный треугольник";
    }

    bool check() {
        if (Triangle::check() == true && a == c && A == C) {
            return true;
        } else {
            return false;
        }
    }
};

class Tri_equila : public Triangle {
public:
    Tri_equila(int a, int b, int c, int A, int B, int C) : Triangle(a, b, c, A, B, C) {
        name = "Равносторонний треугольник";
    }

    bool check() {
        if (Triangle::check() == true && a == b && b == c && A == 60 && B == 60 && C == 60) {
            return true;
        } else {
            return false;
        }
    }
};

class Quadrangle : public Figure {
public:
    Quadrangle(int a_dim, int b_dim, int c_dim, int d_dim, int A_deg, int B_deg, int C_deg, int D_deg) {
        name = "Четырёхугольник";
        sides_count = 4;
        a = a_dim; b = b_dim; c = c_dim; d = d_dim;
        A = A_deg; B = B_deg; C = C_deg; D = D_deg;
    }

    bool check() {
        if (A + B + C + D == 360) {
            return true;
        } else {
            return false;
        }
    }

    void print_info() {
        Figure::print_info();
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << std::endl;
        std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << std::endl;
    }
};

class Rectangle : public Quadrangle {
public:
    Rectangle(int a, int b, int c, int d, int A, int B, int C, int D) 
        : Quadrangle(a, b, c, d, A, B, C, D) {
        name = "Прямоугольник";
    }

    bool check() {
        if (Quadrangle::check() == true && a == c && b == d && A == 90 && B == 90 && C == 90 && D == 90) {
            return true;
        } else {
            return false;
        }
    }
};

class Square : public Quadrangle {
public:
    Square(int a, int b, int c, int d, int A, int B, int C, int D) 
        : Quadrangle(a, b, c, d, A, B, C, D) {
        name = "Квадрат";
    }

    bool check() {
        if (Quadrangle::check() == true && a == b && b == c && c == d && A == 90 && B == 90 && C == 90 && D == 90) {
            return true;
        } else {
            return false;
        }
    }
};

class Parallel : public Quadrangle {
public:
    Parallel(int a, int b, int c, int d, int A, int B, int C, int D) 
        : Quadrangle(a, b, c, d, A, B, C, D) {
        name = "Параллелограмм";
    }

    bool check() {
        if (Quadrangle::check() == true && a == c && b == d && A == C && B == D) {
            return true;
        } else {
            return false;
        }
    }
};

class Diamond : public Quadrangle {
public:
    Diamond(int a, int b, int c, int d, int A, int B, int C, int D) 
        : Quadrangle(a, b, c, d, A, B, C, D) {
        name = "Ромб";
    }

    bool check() {
        if (Quadrangle::check() == true && a == b && b == c && c == d && A == C && B == D) {
            return true;
        } else {
            return false;
        }
    }
};

void print_any_figure(Figure* fig) {
    fig->print_info();
    std::cout << std::endl;
}

int main() {
    Figure fig;
    Triangle tri(10, 20, 30, 50, 60, 70);
    Tri_Rect tri_rect_wrong(10, 20, 30, 50, 60, 90);
    Tri_Rect tri_rect_correct(10, 20, 30, 50, 40, 90);
    Tri_Isos tri_isos(10, 20, 10, 50, 60, 50);
    Tri_equila tri_eq(30, 30, 30, 60, 60, 60);

    Quadrangle quad(10, 20, 30, 40, 50, 60, 70, 80);
    Rectangle rect(10, 20, 10, 20, 90, 90, 90, 90);
    Square sq(20, 20, 20, 20, 90, 90, 90, 90);
    Parallel par(20, 30, 20, 30, 30, 40, 30, 40);
    Diamond dia(30, 30, 30, 30, 30, 40, 30, 40);

    print_any_figure(&fig);
    print_any_figure(&tri);
    print_any_figure(&tri_rect_wrong);
    print_any_figure(&tri_rect_correct);
    print_any_figure(&tri_isos);
    print_any_figure(&tri_eq);

    print_any_figure(&quad);
    print_any_figure(&rect);
    print_any_figure(&sq);
    print_any_figure(&par);
    print_any_figure(&dia);

    return 0;
}
