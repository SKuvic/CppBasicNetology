//Centaur.h
#pragma once
#include "Ground.h"


class Centaur : public Ground {
public:
    // Передаем в базовый класс: Имя="Кентавр", Скорость=10, Время хода=10
    Centaur();

    // Длительность отдыха
    double getRestDuration(int rest_count) const override;

};

