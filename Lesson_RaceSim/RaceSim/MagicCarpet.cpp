//MagicCarpet.cpp
#include "MagicCarpet.h"

// Конструктор: передаем родителю Имя="Ковер-самолет" и Скорость=10
MagicCarpet::MagicCarpet() : Air("Ковёр-самолет", 10.0) {}

// Реализуем уникальное изменение дистанции
double MagicCarpet::getDistanceCoefficient(double distance) const {
    if (distance < 1000) return 0.0;       // 0%
    if (distance < 5000) return 0.03;      // 3%
    if (distance < 10000) return 0.10;     // 10%
    return 0.05;  // 5 % - на остальные случаи
}
