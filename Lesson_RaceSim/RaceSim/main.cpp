#include <iostream>
#include "Race.h"
#include "Camel.h"
#include "SwiftCamel.h"
#include "Centaur.h"
#include "TerraBoots.h"
#include "MagicCarpet.h"
#include "Eagle.h"
#include "Broom.h"
#include <windows.h>

using namespace std;

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    //setlocale(LC_ALL, "Russian");
    std::setlocale(LC_ALL, ".UTF8");

    while (true) {
        int race_type = 0;
        double distance = 0;

        cout << "=== СИМУЛЯТОР ГОНОК ===\n";
        cout << "1. Гонка для наземного транспорта\n";
        cout << "2. Гонка для воздушного транспорта\n";
        cout << "3. Гонка для наземного и воздушного транспорта\n";
        cout << "0. Выход из программы\n";
        cout << "Выберите тип гонки: ";
        cin >> race_type;

        if (race_type == 0) break;

        cout << "Укажите расстояние гонки (в км): ";
        cin >> distance;

        // Создаем объект гонки
        Race current_race(race_type, distance);

        // Список всех доступных ТС в игре
        int total_game_vehicles = 7;
        Vehicle** available_vehicles = new Vehicle * [total_game_vehicles];
        available_vehicles[0] = new Camel();
        available_vehicles[1] = new SwiftCamel();
        available_vehicles[2] = new Centaur();
        available_vehicles[3] = new TerraBoots();
        available_vehicles[4] = new MagicCarpet();
        available_vehicles[5] = new Eagle();
        available_vehicles[6] = new Broom();

        bool registering = true;
        while (registering) {
            cout << "\n--- Список доступных для регистрации ТС ---\n";
            for (int i = 0; i < total_game_vehicles; i++) {
                cout << i + 1 << ". " << available_vehicles[i]->getName() << endl;
            }
            cout << "0. Завершить регистрацию и НАЧАТЬ ГОНКУ\n";
            cout << "Выберите ТС для регистрации: ";
            int v_choice;
            cin >> v_choice;

            if (v_choice == 0) {
                if (current_race.getCount() < 2) {
                    cout << "Ошибка! Нужно зарегистрировать минимум 2 транспорта!\n";
                }
                else {
                    registering = false;
                }
            }
            else if (v_choice > 0 && v_choice <= total_game_vehicles) {
                Vehicle* selected = available_vehicles[v_choice - 1];
                if (current_race.registerVehicle(selected)) {
                    cout << "ТС успешно зарегистрировано!\n";
                }
                else {
                    cout << "Не удалось зарегистрировать (тип не подходит или уже добавлен)!\n";
                }
            }
        }

        // Запуск гонки и сортировка
        current_race.startRace();

        cout << "\n======= РЕЗУЛЬТАТЫ ГОНКИ =======\n";
        for (int i = 0; i < current_race.getCount(); i++) {
            Vehicle* v = current_race.getVehicle(i);
            cout << i + 1 << ". " << v->getName()
                << " | Время: " << v->calculateTime(distance) << " ч.\n";
        }
        cout << "================================\n\n";

        // Очистка памяти выделенных ТС
        for (int i = 0; i < total_game_vehicles; i++) {
            delete available_vehicles[i];
        }
        delete[] available_vehicles;

        cout << "Хотите провести еще одну гонку? (1 - Да, 0 - Выйти): ";
        int restart;
        cin >> restart;
        if (restart == 0) break;
    }

    cout << "Программа завершена. Удачи на защите!\n";
    return 0;
}
