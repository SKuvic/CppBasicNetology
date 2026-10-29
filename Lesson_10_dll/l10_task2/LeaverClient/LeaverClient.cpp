#include <iostream>
#include <string>
#include "../l10_task2/Leaver.h"
#include <windows.h>

int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	Leaver ma_leaver;
	std::string enter_name;

	std::cout << "Введите имя: ";
	std::cin >> enter_name;

	std::cout << ma_leaver.leave(enter_name) << std::endl;

	return 0;
}
