#pragma once
#include "Vehicle.h"

class Air : public Vehicle {
public:
    // Только объявление конструктора, без фигурных скобок и вызова Vehicle!
    Air(std::string name, double speed);

    virtual ~Air() = default;

    // Переопределяем метод расчета времени
    double calculateTime(double distance) const override;

    // Чисто виртуальный метод для наследников
    virtual double getDistanceCoefficient(double distance) const = 0;
};
