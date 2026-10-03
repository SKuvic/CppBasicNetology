#ifndef COUNTER_H
#define COUNTER_H

class Counter {
private:
    int number = 1;

public:
    Counter();               
    Counter(int start_value); 

    void increase();         
    void descrease();        
    void shownumber();       
};

#endif
