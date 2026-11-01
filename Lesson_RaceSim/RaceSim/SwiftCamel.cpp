#include "SwiftCamel.h"

// Скорость = 40, Отдых 10, 
SwiftCamel::SwiftCamel() : Ground("Верблюд-быстроход", 40.0, 10.0) {}

double SwiftCamel::getRestDuration(int rest_count) const {
    if (rest_count == 1) return 5.0;   // 1-й отдых: 5 часов
    if (rest_count == 2) return 6.5;   // 2-й отдых: 6.5 часов
    return 8.0;                        // Все следующие: 8 часов
}
 