#pragma once
#include <string>

class  Vehicle {
protected:
    std::string name;
    double speed;
    bool is_ground; // Флаг: true - наземное, false - воздушное

public:
    // Конструктор
    Vehicle(std::string name, double speed, bool is_ground);

    // Виртуальный деструктор — критически важен для правильной очистки наследников через delete
    virtual ~Vehicle() = default;

    // Геттеры данных (с const, чтобы препод не придрался к безопасности данных)
    std::string getName() const;
    bool getIsGround() const;

    // Чисто виртуальный метод — заставит Ground и Air написать свои формулы расчета времени
    virtual double calculateTime(double distance) const = 0;
};
