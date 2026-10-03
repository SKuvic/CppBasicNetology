#ifndef HEAD_H
#define HEAD_H

#include <iostream>
#include <string>

// Базовый класс
class Figure {
protected:
    int sides_count = 0;
    std::string name = "Фигура";
    int a = 0, b = 0, c = 0, d = 0;
    int A = 0, B = 0, C = 0, D = 0;

public:
    int get_sides_count();
    std::string get_name();
    virtual void print_info();
};

// --- ТРЕУГОЛЬНИКИ ---

class Triangle : public Figure {
public:
    Triangle(int a_dim, int b_dim, int c_dim, int A_deg, int B_deg, int C_deg);
    void print_info() override;
};

class Tri_Rect : public Triangle {
public:
    Tri_Rect(int a, int b, int c, int A, int B);
};

class Tri_Isos : public Triangle {
public:
    Tri_Isos(int side_ac, int side_b, int angle_AC, int angle_B);
};

class Tri_equila : public Triangle {
public:
    Tri_equila(int side);
};

// --- ЧЕТЫРЕХУГОЛЬНИКИ ---

class Quadrangle : public Figure {
public:
    Quadrangle(int a_dim, int b_dim, int c_dim, int d_dim, int A_deg, int B_deg, int C_deg, int D_deg);
    void print_info() override;
};

class Rectangle : public Quadrangle {
public:
    Rectangle(int side_AC, int side_BD);
};

class Parallel : public Quadrangle {
public:
    Parallel(int side_AC, int side_BD, int angle_AC, int angle_BD);
};

class Square : public Quadrangle {
public:
    Square(int side_ABCD);
};

class Diamond : public Quadrangle {
public:
    Diamond(int side_ABCD, int angle_AC, int angle_BD);
};

#endif
