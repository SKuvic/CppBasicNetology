//Head.h

#ifndef COUNTER_H
#define COUNTER_H

class Counter {
private:
    int number = 1;

public:
    Counter();               // Конструктор по умолчанию
    Counter(int start_value); // Конструктор с параметром

    void increase();         
    void descrease();        
    void shownumber();       
};

#endif