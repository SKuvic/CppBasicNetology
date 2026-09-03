#include <iostream>
#include <string>

struct adress {                                        // Аккаунт пользователя содержит <ID Счета>, <Имя>, <Кол-во средств>
    std::string city;
    std::string street;
    int house;
    int appartment;
    long index;
};

void adressInsert (adress& adressData) {                          //Ф-ия обновления данных осредствах на счету в аккаунте "struct"
    
    std:: cout << "Город: " << adressData.city << std::endl;
    std:: cout << "Улица: " << adressData.street << std:: endl;
    std:: cout << "Дом: "<< adressData.house << std:: endl;
    std:: cout << "Квартира: " << adressData.appartment <<std::endl;
    std:: cout << "Индекс: " << adressData.index <<std::endl;
    std:: cout << " " << std::endl;
}

int main (){
    
    adress adress_A = {"Москва", "Арбат", 12, 8, 123456};
    adress adress_B = {"Ижевск", "Пушкина", 59, 143, 953769};

    adressInsert (adress_A);
    
    adressInsert (adress_B);

    return 0;
}