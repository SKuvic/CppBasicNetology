#include <iostream>
#include <string>
#include <exception> // Нужен для работы с исключениями
#include <string_view>


int function(std::string str, int forbidden_length) {
    int string_size = str.length(); // Считаем длину стандартным методом

    // Если длина совпала с запретной — триггерим аварийную остановку
    if (string_size == forbidden_length) {
        throw "Запретная длина!"; // Бросаем указатель на строку (const char*)
    }
    
    return string_size; 
}

int main() {
    setlocale(LC_ALL, "Russian");

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
        catch (const char* error_message) {
            //Если throw сработал то сразу перенос сюда идет и не проходим строку 37
            std::cout << "Вы ввели слово запретной длины! До свидания" << std::endl;
            
            break;
        }
    }

    return 0;
}
