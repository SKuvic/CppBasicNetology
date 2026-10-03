//Source.cpp

#include <iostream>
#include "Head.h"


int main () {

    //Входные числа
double val1 {0};
double val2 {0};

    //Выбор
int choice {-1};

std:: cout << "Введите первое число: ";
std:: cin >> val1;
std:: cout << "Введите второе число: ";
std:: cin >> val2;

std:: cout << "Выберите операцию (1 - сложение, 2 вычитание, 3 - умножение, 4 - деление, 5 - возведение в степень): " <<std::endl;
std:: cin >> choice;

switch (choice)
{
case 1:
    std:: cout << val1 << " + " << val2 << " = " << add (val1, val2) << std::endl;
    break;

case 2:
std:: cout << val1 << " - " << val2 << " = " << subtract (val1, val2) << std::endl;
    break;

case 3:
std:: cout << val1 << " * " << val2 << " = " << multiply (val1, val2) << std::endl;
    break;

case 4:
std:: cout << val1 << " / " << val2 << " = " << divide (val1, val2) << std::endl;
    break;

case 5:
std:: cout << val1 << " В степени 2" << " = " << power (val1) << std::endl;
    break;


default:
    std:: cout << "Неверный выбор!" << std::endl;
    break;
}


return 0;

}