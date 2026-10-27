#ifndef Leaver_h
#define Leaver_h
#include <string>


class __declspec(dllexport) Leaver {
private:
	std::string name;

public:
	Leaver() = default;			//Для пустых name 

	Leaver(std::string name);	//Для НЕ пустых name

	//Методы
	void set_name(std::string name);    // Setter — записывает
	std::string get_name() const;
};

#endif