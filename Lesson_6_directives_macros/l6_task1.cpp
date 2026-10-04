#include <iostream>
//Определение
#define MODE 26  

//Ошибка неопределнности
#ifndef MODE
#error НЕ ОПРЕДЕЛЕН РЕЖИМ <MODE>!
#endif

//Функция ADD 
#if MODE == 1
int add (int neum1, int neum2) {
        return neum1 + neum2;
}
#endif


int main (){
//Переменные для функции ADD
    int neum1 = 0;
    int neum2 = 0;

#if MODE == 0
std::cout << "Работа в режиме тренировки. CODE " << MODE << std::endl;

#elif MODE == 1
std::cout << "Работаю в боевом режиме. CODE " << MODE << std::endl;
std::cout << "Введите число 1: ";
std::cin >> neum1;
std::cout << "Введите число 2: ";
std::cin >> neum2;
std:: cout << neum1 << " + "<< neum2 << " = "<< add (neum1, neum2) << std::endl;

#else
std::cout << "Работа в режиме UNKNWN. Завершение работы." << std::endl;
#endif

    return 0;
}