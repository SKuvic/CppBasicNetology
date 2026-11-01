#pragma once
#include "Air.h"

class Broom : public Air {
public:
    Broom();

    // Реализуем его уникальное изменение дистанции
    double getDistanceCoefficient(double distance) const override;
};


