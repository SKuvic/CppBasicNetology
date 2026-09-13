#include <iostream>
#include <string>

class Calculator
{
private:                 // Модификатор доступа
    double num1 = 0;       // Поле класса 1
    double num2 = 0;       // Поле класса 2

public:
    //Сложение
    double add ()    //Метод.
    {
        return num1 + num2;
    }

    //Вычитание
    double subtract_2_1() { 
        return num1 - num2;
    }

    //Вычитание обратное
    double subtract_1_2() { 
        return num2 - num1;
    }

    //Умножение
    double multiply() { 
       return num1 * num2;
    }

    //Деление
    double divide_1_2() { 
        return num1 / num2;
    }

    //Деление обратное
    double divide_2_1() {
       return num2 / num1;
    }

    //
    bool set_num1 (int num1) {
        if (num1 == 0)
            return false;

            this -> num1 = num1;
            return true;
    }

    //
    bool set_num2 (int num2) {
        if (num2 == 0)
            return false;
        
            this -> num2 = num2;
            return true;
    }



};

int main (int argc, char** argv){

    Calculator calcmain;
    double tmp_input = 0;

    //BLOCK I. проверка нулей на ввод
      
    std::cout << "Введите Num1: ";                           //num1
    std::cin >> tmp_input;

    while (!calcmain.set_num1(tmp_input)){
        std::cout << "Неверный ввод!" << std::endl;
        std::cout << "Введите Num1: ";
        std::cin >> tmp_input;
    }
        
    std::cout << "Введите Num2: ";
    std::cin >> tmp_input;

    while (!calcmain.set_num2(tmp_input)){
        std::cout << "Неверный ввод!" << std::endl;
        std::cout << "Введите Num2: ";
        std::cin >> tmp_input;
    }    
    

    //BLOCK II. Вызовы методов и вывод в терминал
    std::cout << "num1 + num2 = " << calcmain.add() << std::endl;
    std::cout << "num1 - num2 = " << calcmain.subtract_2_1() << std::endl;
    std::cout << "num2 - num1 = " << calcmain.subtract_1_2() << std::endl;
    std::cout << "num1 * num2 = " << calcmain.multiply() << std::endl;
    std::cout << "num1 / num2 = " << calcmain.divide_1_2() << std::endl;
    std::cout << "num2 / num1 = " << calcmain.divide_2_1() << std::endl;

    return 0;
}