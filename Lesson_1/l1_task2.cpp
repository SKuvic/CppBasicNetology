#include <iostream>
#include <string>

struct account {                                        // Аккаунт пользователя содержит <ID Счета>, <Имя>, <Кол-во средств>
    long accID;
    std::string userName;
    int balance = 0;
};

void balanceUpdate (account& accountData, float newBalance) {                          //Ф-ия обновления данных осредствах на счету в аккаунте "struct"
    
    accountData.balance = newBalance;
}

int main (){
    
    account enterAccount;                                   //"местный" аккаунт по "шаблну" Struct т.к. мы должны куда то записать данные и они точно НЕ должны идти в сам Struct
    float changeBalance = 0;

    std:: cout << "Введите номер счета: " << std:: endl;
    std:: cin >> enterAccount.accID;
    std:: cout << "Введите имя пользователя: " << std:: endl;
    std:: cin >> enterAccount.userName;
    std:: cout << "Введите количество средств на счету: " << std:: endl;
    std:: cin >> enterAccount.balance;


    std:: cout << "Введите новый баланс: " << std:: endl;
    std:: cin >> changeBalance;

    
    balanceUpdate (enterAccount, changeBalance);

    std::cout << "Ваш счет: " << enterAccount.userName << ", " << enterAccount.accID << ", " << enterAccount.balance;


    return 0;
}