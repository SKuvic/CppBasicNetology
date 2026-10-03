#ifndef QUADRANGLES_H
#define QUADRANGLES_H

#include "Figure.h"

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
