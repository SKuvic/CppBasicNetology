#pragma once
#include "Vehicle.h"

class Ground : public Vehicle {
protected:
    double move_time;

public:
    // Только объявление конструктора! Никакого двоеточия и тела функции!
    Ground(std::string name, double speed, double move_time);

    virtual ~Ground() = default;

    // Переопределяем метод расчета времени
    double calculateTime(double distance) const override;

    // Чисто виртуальный метод отдыха
    virtual double getRestDuration(int rest_count) const = 0;
};
