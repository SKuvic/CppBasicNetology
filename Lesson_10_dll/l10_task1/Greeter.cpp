#include "Greeter.h"

//Сразу иницилизируем переменную 
std::string Greeter::greet(const std::string& name) {

	return "Greetings, " + name + "!";
}

