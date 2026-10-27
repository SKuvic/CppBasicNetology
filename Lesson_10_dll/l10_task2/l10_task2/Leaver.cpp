#include "Leaver.h"
#include <utility>



//Конструктор
																//Левый LEaver :: - берет код из другого файла/другой строчки. Компилятор понимает что НЕ создаем новый Класс с таким же именем
Leaver::Leaver (std::string name) : name(std::move(name)) {};	// : name - сразу инциализируем переменную name, эта запись пропускает очистку-запись ячейки переменной. Она сразу вписывает в память

//Метод Set
void Leaver::set_name(std::string name) {
	this-> name = std::move(name);
}

// метод Get
std::string Leaver::get_name() const {
	return this-> name;
}