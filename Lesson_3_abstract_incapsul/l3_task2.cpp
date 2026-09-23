#include <iostream>
#include <fstream>
#include <string>

class address {
private:
    std::string city = "";
    std::string street = "";
    int buildingNumber = 0;
    int apartmentsNumber = 0;

public:
    // Конструктор адресов
    address(std::string c, std::string s, int b, int a) {
        city = c;
        street = s;
        buildingNumber = b;
        apartmentsNumber = a;
    }

    // Геттер для получения названия города (нужен для сортировки)
    std::string get_city() const {
        return city;
    }

    // Метод, возвращающий строку для вывода в файл
    std::string get_output_address() const {
        return city + ", " + street + ", " + std::to_string(buildingNumber) + ", " + std::to_string(apartmentsNumber);
    }
};

// Функция сортировки пузырьком по названию города
void sort(address** addresses, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            // Сравниваем строки городов по алфавиту
            if (addresses[j]->get_city() > addresses[j + 1]->get_city()) {
                // Меняем указатели местами
                address* temp = addresses[j];
                addresses[j] = addresses[j + 1];
                addresses[j + 1] = temp;
            }
        }
    }
}

int main() {
    std::ifstream input_file("in.txt"); // Открываем файл на чтение
    if (!input_file.is_open()) {
        std::cerr << "Не удалось открыть файл in.txt!" << std::endl;
        return 1;
    }

    int addressCount = 0;
    input_file >> addressCount;
    
    // Создаем динамический массив указателей на объекты класса
    address** arr = new address*[addressCount];
    
    for (int i = 0; i < addressCount; i++) {
        std::string c;
        std::string s;
        int b = 0;
        int a = 0;
        input_file >> c >> s >> b >> a;

        arr[i] = new address(c, s, b, a);
    }
    input_file.close();

    // Сортируем адреса перед записью
    sort(arr, addressCount);

    std::ofstream output_file("out.txt"); // Открываем файл на запись
    if (!output_file.is_open()) {
        std::cerr << "Не удалось открыть файл out.txt!" << std::endl;
        // Не забываем очистить память перед выходом, если файл не открылся
        for (int i = 0; i < addressCount; i++) delete arr[i];
        delete[] arr;
        return 1;
    }

    output_file << addressCount << std::endl;

    // Записываем отсортированные адреса в файл (теперь по порядку от 0)
    for (int i = 0; i < addressCount; i++) {
        output_file << arr[i]->get_output_address() << std::endl;
        delete arr[i]; // Освобождаем память
    }

    delete[] arr; // Освобождаем массив указателей
    output_file.close();

    return 0;
}
