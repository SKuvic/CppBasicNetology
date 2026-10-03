#include <iostream>
#include "HEAD.h"

void print_info(Figure* fig) {
    fig->print_info();
}

int main() {
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
