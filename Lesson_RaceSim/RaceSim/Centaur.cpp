#include "Centaur.h"

// Передаем в базовый класс: Имя="Кентавр", Скорость=15, Время хода=8
Centaur::Centaur() : Ground("Кентавр", 15.0, 8.0) {}

// Длительность отдыха
double Centaur::getRestDuration(int rest_count) const {
    return 2.0;                        // Все следующие: 2 часа
}
