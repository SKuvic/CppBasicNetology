//Camel.cpp
#include "Camel.h"

// Передаем в базовый класс: Имя="Верблюд", Скорость=10, Время хода=10
Camel::Camel() : Ground("Верблюд", 10.0, 30.0) {}

// Длительность отдыха
double Camel::getRestDuration(int rest_count) const {
        if (rest_count == 1) return 5.0;   // 1-й отдых: 5 часов
        return 8.0;                        // Все следующие: 8 часов
}
