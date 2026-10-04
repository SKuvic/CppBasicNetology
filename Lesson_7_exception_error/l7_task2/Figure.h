#ifndef FIGURE_H
#define FIGURE_H

#include <string>

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

#endif
