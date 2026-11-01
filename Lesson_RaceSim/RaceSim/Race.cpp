#include "Race.h"

Race::Race(int type, double dist)
    : race_type(type), distance(dist), vehicles_count(0), max_vehicles(20) {
    // Выделяем память под массив указателей на транспорт (максимум 20 участников)
    registered_vehicles = new Vehicle * [max_vehicles];
}

Race::~Race() {
    // Чистим память только за самим массивом указателей. 
    // Сами объекты ТС будут удалены в main.cpp, чтобы не было двойного удаления!
    delete[] registered_vehicles;
}

bool Race::registerVehicle(Vehicle* v) {
    // 1. Проверка ТЗ: Можно регистрировать не более одного экземпляра каждого вида ТС
    for (int i = 0; i < vehicles_count; i++) {
        if (registered_vehicles[i]->getName() == v->getName()) {
            return false; // Такой транспорт уже зарегистрирован
        }
    }

    // 2. Проверка ТЗ: Нельзя зарегистрировать на наземную гонку воздушное ТС, а на воздушную — наземное
    if (race_type == 1 && !v->getIsGround()) return false; // Гонка наземная, а ТС летит
    if (race_type == 2 && v->getIsGround()) return false;  // Гонка воздушная, а ТС ползет
    // Если race_type == 3 (совмещенная), то проверки выше пропускаются и регистрируются все

    // 3. Если все проверки прошли, добавляем в массив
    if (vehicles_count < max_vehicles) {
        registered_vehicles[vehicles_count] = v;
        vehicles_count++;
        return true;
    }
    return false;
}

void Race::startRace() {
    if (vehicles_count < 2) return;

    // Сортировка методом пузырька (Пункт ТЗ: результаты выходят по возрастанию времени)
    for (int i = 0; i < vehicles_count - 1; i++) {
        for (int j = 0; j < vehicles_count - i - 1; j++) {
            double time1 = registered_vehicles[j]->calculateTime(distance);
            double time2 = registered_vehicles[j + 1]->calculateTime(distance);

            // Если предыдущий ехал дольше, чем следующий — меняем их местами
            if (time1 > time2) {
                Vehicle* temp = registered_vehicles[j];
                registered_vehicles[j] = registered_vehicles[j + 1];
                registered_vehicles[j + 1] = temp;
            }
        }
    }
}

int Race::getCount() const {
    return vehicles_count;
}

Vehicle* Race::getVehicle(int index) const {
    if (index >= 0 && index < vehicles_count) {
        return registered_vehicles[index];
    }
    return nullptr;
}
