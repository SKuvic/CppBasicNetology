#include "Greeter.h"
#include <utility> // Нужно для std::move


//Сразу иницилизируем переменную 
Greeter::Greeter(std::string name) : name (std::move(name)) {}

void Greeter::set_name(std::string name) {
	this->name = std::move(name);
}

const std::string& Greeter::get_name() const {
	return name;
}