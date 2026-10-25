#pragma once
#ifndef Greeter_h
#define Greeter_h
#include <string>


class Greeter {
private:
	std::string name;

public:
	Greeter() = default;				// <- It's A Constructor!

	explicit Greeter(std::string name);	//Конструктор с параметром-запретом неявного преобразования

	void set_name ( std::string name);	    // Вызов Метода ввода имени

	const std::string& get_name() const;				// Метод вывода имени
};

#endif