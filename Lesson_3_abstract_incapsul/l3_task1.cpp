#include <iostream>
#include <fstream>

class adress {
private:
    std::string city = "";
    std::string street = "";
    int buildingNumber = 0;
    int appartmentsNumber = 0;

public:
//конструктор адресов
    adress (std::string c, std::string s, int b, int a) {
        city = c;
        street = s;
        buildingNumber = b;
        appartmentsNumber = a;
    }

//Метод отвечающий за запись
    void printAdress (std::ofstream& out) {
        //std::cout << city << ", " << street << ", " << buildingNumber << ", " << appartmentsNumber << std::endl;
        out << city << ", " << street << ", " << buildingNumber << ", " << appartmentsNumber << std::endl;

    }
};
//


int main () {
    std::ifstream input_file ("in.txt");    //Открыть файл
    
    int adressCount = 0;            //Число адресов в файле по первому числу первой строки
    input_file >> adressCount;
    adress** arr = new adress*[adressCount];
    
    for (int i = 0; i < adressCount; i++) { //Цикл на чтение?
        std::string c;
        std::string s;
        int b = 0;
        int a = 0;
        input_file >> c >> s >> b >> a;

        arr [i] = new adress (c, s, b, a);
    }

    input_file.close();
    std::ofstream output_file ("out.txt");

    output_file << adressCount << std::endl;

    for (int i = adressCount - 1; i >= 0; i--) {     //На запись в файл
        arr [i]->printAdress(output_file);
        delete arr[i];
    }

    delete[] arr; 
    output_file.close(); // Закрыть выходной файл

    return 0;
    //
}