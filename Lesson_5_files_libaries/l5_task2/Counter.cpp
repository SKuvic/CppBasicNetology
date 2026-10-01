#include "Counter.h"
#include <iostream>

// 1. Конструктор по умолчанию
Counter::Counter() {
    number = 1;
}

// 2. Конструктор с параметром
Counter::Counter(int start_value) {             
    number = start_value;
}

void Counter::increase() {                      
    number++;
}

void Counter::descrease() {                    
    number--;
}

void Counter::shownumber() {                    
    std::cout << number << std::endl;
}
