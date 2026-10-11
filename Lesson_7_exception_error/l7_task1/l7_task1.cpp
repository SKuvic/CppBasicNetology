#include <iostream>
#include <string>
#include <exception> // Нужен для работы с исключениями
#include <string_view>
#include <stdexcept>
#include <windows.h>

int function(std::string str, int forbidden_length) {
    int string_size = 0; // 
    for (char c: str) {                 //Из-за того что криллица весит по 2 байта на 1 символ пришлось сделать это
        if ((c & 0xc0) != 0x80) {
            string_size++;
        }
    }
    if (string_size == forbidden_length) {
        throw std::out_of_range ("OUT OF RANGE ERROR. "); // Бросаем указатель на строку (const char*)
    }

    return string_size;
}

int main() {
    
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    int forbidden_length = 0;
    std::string str = "";

    //Работа с пользователем
    std::cout << "Введите запретную длину: ";
    std::cin >> forbidden_length;

    //Цикл проверки слов        
    while (true) {
        std::cout << "Введите слово: ";
        std::cin >> str;

        // Проверка длины
        try {
            int length = function(str, forbidden_length);   //В функции есть THROW! он переведет на catch
            // Если throw НЕ отработал то
            std::cout << "Длина слова \"" << str << "\" равна " << length << std::endl;
        }
        catch (const std::exception& err) {
            //Если throw сработал то сразу перенос сюда идет и не проходим строку 37
            std::cerr << err.what () << "Вы ввели слово запретной длины! До свидания" << std::endl;

            break;
        }
    }

    return 0;
}
