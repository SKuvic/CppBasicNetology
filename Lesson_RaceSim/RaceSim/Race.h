#pragma once
#include "Vehicle.h"

class Race {
private:
    int race_type;      // 1 - Наземная, 2 - Воздушная, 3 - Совмещенная
    double distance;    // Дистанция гонки

    Vehicle** registered_vehicles; // Динамический массив указателей через new
    int vehicles_count;            // Сколько ТС зарегистрировано прямо сейчас
    int max_vehicles;              // Максимальная вместимость массива

public:
    // Конструктор принимает тип гонки и дистанцию
    Race(int type, double dist);

    // Деструктор очищает только массив указателей
    ~Race();

    // Метод регистрации ТС. Возвращает true (успех) или false (не прошло проверки ТЗ)
    bool registerVehicle(Vehicle* v);

    // Метод запуска гонки. Сортирует участников по времени
    void startRace();

    // Вспомогательные геттеры для main.cpp
    int getCount() const;
    Vehicle* getVehicle(int index) const;
};
