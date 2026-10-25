#include <iostream>
#include <string>
#include "Greeter.h"
#include <windows.h>

int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	std::setlocale(LC_ALL, "Russian");

	Greeter ma_greeter;

	std::string enter_name;

	std::cout << "Enter a Name: ";
	std::cin >> enter_name;

	ma_greeter.set_name(enter_name);

	std::cout << "Greetings, " << ma_greeter.get_name() << "!" << std::endl;
}