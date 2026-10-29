#ifndef Greeter_h
#define Greeter_h
#include <string>


class Greeter {

public:
	Greeter() = default;				// <- It's A Constructor!

	std::string greet(const std::string& name);				// Метод Приветствия
};

#endif