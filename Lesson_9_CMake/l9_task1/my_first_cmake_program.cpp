#include <iostream>
#include <string>
#include "Person.h"

int main() {

    //Имя пользователя для передачи в метод
    std::string input_name;

    Person person;


    std::cout << "Введите имя: ";
    std::cin >> input_name; // Считываем имя с клавиатуры
    person.set_name(input_name);
    
    std::cout << "Здравствуйте, " << person.get_name() << "!" << std::endl;

    return 0;
}
