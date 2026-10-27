#include <iostream>
#include <string>
#include "Leaver.h"
#include <windows.h>

int main() {

	std::string name;
	std::cout << "Введите имя: ";
	std::cin >> name;

	Leaver leaver;

	leaver.set_name(name);

	std::cout << "До свидания, " << leaver.get_name() << "!" << std::endl;

	return 0;
}
