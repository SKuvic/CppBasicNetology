//Camel.h
#pragma once
#include "Ground.h"

class Camel : public Ground {
public:
    // Передаем в базовый класс: Имя="Верблюд", Скорость=10, Время хода=10
    Camel();

    // Длительность отдыха
    double getRestDuration(int rest_count) const override;
};
