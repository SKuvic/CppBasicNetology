#include <iostream>
#include <string>

// Подключаем заголовочные файлы ВСЕХ трех подзадач
#include "math_functions.h" 
#include "Counter.h"
#include "Figure.h"
#include "Triangles.h"
#include "Quadrangles.h"

// Вспомогательная функция для вывода фигур через указатель
void print_info_ptr(Figure* fig) {
    fig->print_info();
}

int main() {
    // =================================================================
    // ПОДЗАДАЧА 1: МАТЕМАТИЧЕСКИЕ ФУНКЦИИ
    // =================================================================
    std::cout << "===== [ПОДЗАДАЧА 1: МАТЕМАТИКА] =====" << std::endl;
    double val1 = 0;
    double val2 = 0;
    int math_choice = -1;

    std::cout << "Введите первое число: ";
    std::cin >> val1;
    std::cout << "Введите второе число: ";
    std::cin >> val2;

    std::cout << "Выберите операцию (1 - сложение, 2 - вычитание, 3 - умножение, 4 - деление, 5 - возведение в степень): " << std::endl;
    std::cin >> math_choice;

    switch (math_choice) {
    case 1:
        std::cout << val1 << " + " << val2 << " = " << add(val1, val2) << std::endl;
        break;
    case 2:
        std::cout << val1 << " - " << val2 << " = " << subtract(val1, val2) << std::endl;
        break;
    case 3:
        std::cout << val1 << " * " << val2 << " = " << multiply(val1, val2) << std::endl;
        break;
    case 4:
        std::cout << val1 << " / " << val2 << " = " << divide(val1, val2) << std::endl;
        break;
    case 5:
        std::cout << val1 << " в степени 2 = " << power(val1) << std::endl;
        break;
    default:
        std::cout << "Неверный выбор!" << std::endl;
        break;
    }
    std::cout << std::endl;

    // =================================================================
    // ПОДЗАДАЧА 2: СЧЁТЧИК
    // =================================================================
    std::cout << "===== [ПОДЗАДАЧА 2: СЧЁТЧИК] =====" << std::endl;
    std::string user_response;             

    std::cout << "Вы хотите указать начальное значение счётчика? Введите да или нет: ";
    std::cin >> user_response;

    Counter counter;

    if (user_response == "да") {
        int start_value = 0;
        std::cout << "Введите начальное значение счётчика: ";
        std::cin >> start_value;
        counter = Counter(start_value); 
    }

    char command = ' ';
    while (command != 'x') {
        std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
        std::cin >> command;

        if (command == '+') {
            counter.increase();
        } 
        else if (command == '-') {
            counter.descrease(); 
        } 
        else if (command == '=') {
            counter.shownumber();
        }
        else if (command == 'x') {
            std::cout << "Завершение работы со счётчиком." << std::endl;
        }
    }
    std::cout << std::endl;

    // =================================================================
    // ПОДЗАДАЧА 3: ИЕРАРХИЯ ФИГУР
    // =================================================================
    std::cout << "===== [ПОДЗАДАЧА 3: ФИГУРЫ] =====" << std::endl;
    
    Triangle tri(10, 20, 30, 50, 60, 70);
    Tri_Rect tri_rect(10, 20, 30, 50, 60);
    Tri_Isos tri_isos(10, 20, 50, 60);
    Tri_equila tri_eq(30);

    Quadrangle quad(10, 20, 30, 40, 50, 60, 70, 80);
    Rectangle rect(10, 20);
    Square sq(20);
    Parallel par(20, 30, 30, 40);
    Diamond dia(30, 30, 40);

    print_info_ptr(&tri);
    print_info_ptr(&tri_rect);
    print_info_ptr(&tri_isos);
    print_info_ptr(&tri_eq);

    print_info_ptr(&quad);
    print_info_ptr(&rect);
    print_info_ptr(&sq);
    print_info_ptr(&par);
    print_info_ptr(&dia);

    return 0;
}
