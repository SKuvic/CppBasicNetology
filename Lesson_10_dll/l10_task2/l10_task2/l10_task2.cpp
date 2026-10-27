#include <iostream>
#include <string>
#include "Leaver.h"
#include <windows.h>

int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	std::setlocale(LC_ALL, "Russian");

	Leaver ma_leaver;

	std::string enter_name;

	std::cout << "Enter a Name: ";
	std::cin >> enter_name;

	ma_leaver.set_name(enter_name);

	std::cout << "Farewell, " << ma_leaver.get_name() << "!" << std::endl;
}