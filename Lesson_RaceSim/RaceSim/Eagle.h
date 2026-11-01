//Eagle.h
#pragma once
#include "Air.h"


class Eagle : public Air {
public:
    Eagle();
    // Реализуем его уникальное изменение дистанции
    double getDistanceCoefficient(double distance) const override;
};
