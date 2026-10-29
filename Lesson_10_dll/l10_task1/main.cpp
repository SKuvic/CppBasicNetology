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

	std::cout << ma_greeter.greet(enter_name) <<std::endl;

	return 0;
}