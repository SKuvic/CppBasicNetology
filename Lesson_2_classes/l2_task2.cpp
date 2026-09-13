#include <iostream>
#include <string>

class Counter {
private:
    int number = 1;

public:
    // 1. Конструктор по умолчанию (обязательно нужен для строки Counter counter;)
    Counter() {
        number = 1;
    }

    // 2. Конструктор с параметром
    Counter(int start_value) {             
        number = start_value;
    }

    void increase() {                      
        number++;
    }

    void descrease() { // Обратите внимание: у вас в main написано decrease, а тут descrease (с буквой s). Оставил как у вас, чтобы не ломать вызов.                   
        number--;
    }

    void shownumber() {                    
        std::cout << number << std::endl;
    }
};

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
