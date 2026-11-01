#include "TerraBoots.h"

// Скорость = 40, Отдых 60, чтобы он отличался от обычного верблюда
TerraBoots::TerraBoots() : Ground("Ботинки-вездеходы", 6.0, 60.0) {}

double TerraBoots::getRestDuration(int rest_count) const {
    if (rest_count == 1) return 10.0;   // 1-й отдых: 10 часов
    return 5.0;                        // Все следующие: 5 часов
}
