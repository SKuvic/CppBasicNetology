//Person.h
//Описание класса и то какими методами он обладает
#ifndef Person_h
#define Person_h

#include <string>

class Person {
private:
    std::string name;

public:
    //Construct
    Person();
    Person (const std::string& name);

    //Ввод имени
    void set_name(const std::string& name);

    //Вывод имени
    std::string get_name() const;
};

#endif