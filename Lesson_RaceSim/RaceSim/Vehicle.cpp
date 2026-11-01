#include "Vehicle.h"

// Конструктор инициализирует базовые поля
Vehicle::Vehicle(std::string name, double speed, bool is_ground)
    : name(name), speed(speed), is_ground(is_ground) {
}

std::string Vehicle::getName() const {
    return name;
}

bool Vehicle::getIsGround() const {
    return is_ground;
}
