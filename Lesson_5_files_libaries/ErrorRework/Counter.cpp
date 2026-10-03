#include "Counter.h"
#include <iostream>

Counter::Counter() { number = 1; }
Counter::Counter(int start_value) { number = start_value; }
void Counter::increase() { number++; }
void Counter::descrease() { number--; }
void Counter::shownumber() { std::cout << number << std::endl; }
