#include "Ground.h"

// Передаем параметры в конструктор базового класса Vehicle (флаг true) и инициализируем move_time
Ground::Ground(std::string name, double speed, double move_time)
    : Vehicle(name, speed, true), move_time(move_time) {
}

double Ground::calculateTime(double distance) const {
    double time = distance / speed; // Чистое время в пути

    int rests = static_cast<int>(time / move_time);
    if (time == rests * move_time) {
        rests--; // Отдых на финише не нужен
    }

    // Добавляем время каждого отдыха
    for (int i = 1; i <= rests; ++i) {
        time += getRestDuration(i);
    }

    return time;
}
