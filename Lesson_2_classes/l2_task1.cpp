#include <iostream>
#include <string>

class Calculator
{
public:                 // Модификатор доступа
    int num1 = 0;       // Поле класса 1
    int num2 = 0;       // Поле класса 2

    //Сложение
    void add ()    //Метод. Я решил оставить void т.к. хочу чтобы возвращалось именно число
    {
        std::cout << "Num1 + Num2 = " << num1 + num2 << std::endl;
    }

    //Вычитание
    void sub () { 
        std::cout << "Num1 - Num2 = " << num1 - num2 << std::endl;
    }

    //Вычитание обратное
    void revsub () { 
        std::cout << "Num2 - Num1 = " << num2 - num1 << std::endl;
    }

    //Умножение
    void mul () { 
        std::cout << "Num1 * Num2 = " << num1 * num2 << std::endl;
    }

    //Деление
    void div () { 
        double result = static_cast<double>(num1) / num2;
        std::cout << "Num1 / Num2 = " << result << std::endl;
    }

    //Деление обратное
    void revdiv () { 
        double result = static_cast<double>(num2) / num1;
        std::cout << "Num2 / Num1 = " << result << std::endl;
    }
};

int main (int argc, char** argv){
Calculator calcmain;

    std::cout << "Введите Num1: ";
    std::cin >> calcmain.num1;
    std::cout << "Введите Num2: ";
    std::cin >> calcmain.num2;

while (calcmain.num1 == 0) {                        //Проверки на ноль
    std::cout << "Неверный ввод!" << std::endl;
    std::cout << "Введите Num1: ";
    std::cin >> calcmain.num1;
}

while (calcmain.num2 == 0) {
    std::cout << "Неверный ввод!" << std::endl;
    std::cout << "Введите Num2: ";
    std::cin >> calcmain.num2;
}

    calcmain.add();
    calcmain.sub();
    calcmain.revsub();
    calcmain.mul();
    calcmain.div();
    calcmain.revdiv();

    return 0;
}