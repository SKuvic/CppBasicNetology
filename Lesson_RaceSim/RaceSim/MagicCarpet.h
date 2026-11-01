//MagicCarpet.h
#pragma once
#include "Air.h"

class MagicCarpet : public Air {
public:
    MagicCarpet();
        // Реализуем его уникальное изменение дистанции
    double getDistanceCoefficient(double distance) const override;
};
