#include "Eagle.h"

// Конструктор: передаем родителю Имя="Орел" и Скорость=8
Eagle::Eagle() : Air("Орёл", 8.0) {}

// Реализуем уникальное изменение дистанции
double Eagle::getDistanceCoefficient(double distance) const {
    return 0.06;                           // Всегда 6%
}
