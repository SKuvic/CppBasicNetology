#ifndef TRIANGLES_H
#define TRIANGLES_H

#include "Figure.h"

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

#endif
