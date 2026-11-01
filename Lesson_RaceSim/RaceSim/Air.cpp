#include "Air.h"

// Передаем параметры в конструктор базового класса Vehicle, флаг is_ground = false
Air::Air(std::string name, double speed) : Vehicle(name, speed, false) {}

double Air::calculateTime(double distance) const {
    double coeff = getDistanceCoefficient(distance);
    double real_distance = distance * (1.0 - coeff);
    return real_distance / speed;
}
