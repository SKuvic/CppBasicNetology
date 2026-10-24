#include "Person.h"


Person::Person() {} 
// Конструктор
Person::Person(const std::string& name) {
    this->name = name;
}

// Пробиваемся к методу set_name
void Person::set_name(const std::string& name) {
    this->name = name;
}

// Пробиваемся к методу get_name
std::string Person::get_name() const {
    return name;
}
