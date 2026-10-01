//Source.cpp

#include <iostream>
#include "Counter.h"


int main(int argc, char** argv) {
    
    std::string user_response;             

    // Спрашиваем пользователя (приведем к одному стандарту: да или нет)
    std::cout << "Вы хотите указать начальное значение счётчика? Введите да или нет: ";
    std::cin >> user_response;

    Counter counter; // Срабатывает конструктор по умолчанию (number = 1)

    // Исправлено: проверяем именно user_response
    if (user_response == "да") {
        int start_value = 0;
        std::cout << "Введите начальное значение счётчика: ";
        std::cin >> start_value;

        // Пересоздаем объект конструктором с параметром
        counter = Counter(start_value); 
    }

    char command = ' ';
    
    while (command != 'x') {
        std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
        std::cin >> command;

        if (command == '+') {
            counter.increase();
        } 
        else if (command == '-') {
            counter.descrease(); // Вызов вашего метода с буквой s
        } 
        else if (command == '=') {
            counter.shownumber();
        }
        else if (command == 'x') {
            std::cout << "До свидания!" << std::endl;
        }
    }

    return 0;
}