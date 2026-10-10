#include <iostream>
#include <exception>
#include <string>
#include <cassert>

// 1.Создание класса Fraction
class Fraction {
private:
    int numerator = 0;                  //Числитель
    int denumerator = 1;                //Знаменатель

    // Алгоритм Евклида для НОД
    static int gcd_manual(int a, int b) {
        if (a < 0) a = -a;
        if (b < 0) b = -b;
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a == 0 ? 1 : a;}

    // Дополнительное требование: Сокращение и обеспечение корректной работы со знаками
    void optimize() {
        if (denumerator < 0) {
            numerator = -numerator;
            denumerator = -denumerator;
        }
        int g = gcd_manual(numerator, denumerator);
        numerator /= g;
        denumerator /= g;}

public:
    //Конструктор надо
    Fraction (int nu, int denu) { 
        if (denu == 0) {                                        //Проверка на ноль в знаменателе
            throw "Знаменатель равен нулю!";                    // if-true Выкинет ошибку
        }
        
        numerator = nu;
        denumerator = denu;
        optimize(); // Автоматически сокращает при создании
    }

    //Конструктор по умолчанию
    Fraction() : numerator(0), denumerator(1) {}

    // Запись дроби в строку
    std::string dump() const {
        return std::to_string(numerator) + "/" + std::to_string(denumerator);}

// 2.Перегрузка операторов сравнения
    //  ==
    bool operator==(const Fraction& other) const {
        int left = numerator * other.denumerator;       //Левое число для сравнения
        int right = other.numerator * denumerator;      //правое для сравнения
        return (left == right);}

    //  !=
    bool operator!=(const Fraction& other) const {
        int left = numerator * other.denumerator;       //Левое число для сравнения
        int right = other.numerator * denumerator;
        return (left != right);}
            
    //  <
    bool operator<(const Fraction& other) const {
        int left = numerator * other.denumerator;       //Левое число для сравнения
        int right = other.numerator * denumerator;      //правое для сравнения
        return (left < right);}
    //  >
    bool operator>(const Fraction& other) const {
        int left = numerator * other.denumerator;       //Левое число для сравнения
        int right = other.numerator * denumerator;      //правое для сравнения
        return (left > right);}

    //  <=
    bool operator<=(const Fraction& other) const {
        int left = numerator * other.denumerator;       //Левое число для сравнения
        int right = other.numerator * denumerator;      //правое для сравнения
        return (left <= right);}

    //  >=
    bool operator>=(const Fraction& other) const {
        int left = numerator * other.denumerator;       //Левое число для сравнения
        int right = other.numerator * denumerator;      //правое для сравнения
        return (left >= right);}

//3.Перегрузка арифметических операторов
    //Арифметика - Бинарные операторы
    //  +
    Fraction operator+(const Fraction& other) const {
        int left = numerator * other.denumerator;       //Левое число для сравнения
        int right = other.numerator * denumerator;      //правое для сравнения
        
        int new_numerator  = left + right;                         //Результат перекрестного умножения числителей
        int new_denumerator = denumerator * other.denumerator;      // умножение знаменателей

        return Fraction(new_numerator, new_denumerator);}
    
    //  -
    Fraction operator-(const Fraction& other) const {
        int left = numerator * other.denumerator;       //Левое число для сравнения
        int right = other.numerator * denumerator;      //правое для сравнения
        
        int new_numerator  = left - right;                         //Результат перекрестного умножения числителей
        int new_denumerator = denumerator * other.denumerator;      // умножение знаменателей

        return Fraction(new_numerator, new_denumerator);}
    
    //  *
    Fraction operator*(const Fraction& other) const {
        return Fraction((numerator * other.numerator), (denumerator * other.denumerator));}

    //  / deleniye
    Fraction operator/(const Fraction& other) const {
        return Fraction((numerator * other.denumerator), (denumerator * other.numerator));}

    
//4. Перегрузка унарных операторов
    
    //  +=
    Fraction& operator+=(const Fraction& other) {        //БЕЗ const снаружи т.к. нужно ПЕРЕПРИСВОИТЬ в переменную
        int left = numerator * other.denumerator;       //Левое число для сравнения
        int right = other.numerator * denumerator;      //правое для сравнения
        
        int new_numerator  = left + right;                         //Результат перекрестного умножения числителей
        int new_denumerator = denumerator * other.denumerator;      // умножение знаменателей

        numerator = new_numerator;
        denumerator = new_denumerator;
        optimize();

        return  *this;}

    //  -=
    Fraction& operator-=(const Fraction& other) {        //БЕЗ const снаружи т.к. нужно ПЕРЕПРИСВОИТЬ в переменную
        int left = numerator * other.denumerator;       //Левое число для сравнения
        int right = other.numerator * denumerator;      //правое для сравнения
        
        int new_numerator  = left - right;                         //Результат перекрестного умножения числителей
        int new_denumerator = denumerator * other.denumerator;      // умножение знаменателей

        numerator = new_numerator;
        denumerator = new_denumerator;
        optimize();

        return *this;}

    //  *=
    Fraction& operator*=(const Fraction& other) {
        numerator = numerator * other.numerator;
        denumerator = denumerator * other.denumerator;
        optimize();
        return *this;}

    //  /=
    Fraction& operator/=(const Fraction& other) {
        numerator = numerator * other.denumerator;
        denumerator = denumerator * other.numerator;
        optimize();
        return *this;}

    // Дополнительно: Унарный минус (требуется по ТЗ)
    Fraction operator-() const {
        return Fraction(-numerator, denumerator);}

//5. Перегрузка операторов инкремента и декремента
    //  ++Префикс
    Fraction& operator++ () {
        numerator += denumerator;
        optimize();
        return *this;}
    //  --Префикс
    Fraction& operator-- () {
        numerator -= denumerator;
        optimize();
        return *this;}
    //  Постфикс++
    Fraction operator++ (int) { // БЕЗ амперсанда, чтобы исправить -Wreturn-local-addr
        Fraction prev_val = *this;
        numerator += denumerator;
        optimize();
        return prev_val;}
    //  Постфикс--
    Fraction operator-- (int) { // БЕЗ амперсанда, чтобы исправить -Wreturn-local-addr
        Fraction prev_val = *this;
        numerator -= denumerator;
        optimize();
        return prev_val;}

//6. Дополнительно: оператор << для красивого вывода дроби в std::cout
    friend std::ostream& operator<<(std::ostream& os, const Fraction& f) {
        os << f.numerator << "/" << f.denumerator;
        return os;}

};


int main(){
    try {
        // --- Часть 1: Юнит-тестирование неравенства из ДЗ ---
        std::cout << "--- Ручная проверка неравенств (f1=4/3, f2=6/11) ---" << std::endl;
        Fraction f1(4, 3);
        Fraction f2(6, 11);

        std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << '\n';
        std::cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << '\n';
        std::cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << '\n';
        std::cout << "f1" << ((f1 > f2) ? " > " : " not > ") << "f2" << '\n';
        std::cout << "f1" << ((f1 <= f2) ? " <= " : " not <= ") << "f2" << '\n';
        std::cout << "f1" << ((f1 >= f2) ? " >= " : " not >= ") << "f2" << '\n';

        // --- Часть 2: Интерактивный сценарий из ДЗ с арифметикой и выводами ---
        std::cout << "\n--- Проверка сценария арифметики дробей ---" << std::endl;
        int num1 = 3, den1 = 4, num2 = 4, den2 = 5;
        std::cout << "Введите числитель дроби 1: " << num1 << "\n";
        std::cout << "Введите знаменатель дроби 1: " << den1 << "\n";
        std::cout << "Введите числитель дроби 2: " << num2 << "\n";
        std::cout << "Введите знаменатель дроби 2: " << den2 << "\n";

        Fraction main_f1(num1, den1);
        Fraction main_f2(num2, den2);

        std::cout << main_f1 << " + " << main_f2 << " = " << (main_f1 + main_f2) << "\n";
        std::cout << main_f1 << " - " << main_f2 << " = " << (main_f1 - main_f2) << "\n";
        std::cout << main_f1 << " * " << main_f2 << " = " << (main_f1 * main_f2) << "\n";
        std::cout << main_f1 << " / " << main_f2 << " = " << (main_f1 / main_f2) << "\n";
        
        Fraction scenario_f1 = main_f1; 
        std::cout << "++" << main_f1 << " * " << main_f2 << " = " << (++scenario_f1 * main_f2) << "\n";
        std::cout << "Значение дроби 1 = " << scenario_f1 << "\n";
        std::cout << scenario_f1 << "-- * " << main_f2 << " = " << (scenario_f1-- * main_f2) << "\n";
        std::cout << "Значение дроби 1 = " << scenario_f1 << "\n";

    // --- Часть 3: Автоматические Юнит-тесты через assert ---
    std::cout << "\n--- Запуск автоматических юнит-тестов... ---" << std::endl;

    // Тест 1: Проверка конструкторов и dump
    {
    Fraction tf1(3, 4);
    Fraction tf2(4, 5);
    assert(tf1.dump() == "3/4");
    assert(tf2.dump() == "4/5");
    }

    // Тест 2: Проверка неравенства    
    {        
    Fraction tf1(4, 3);
    Fraction tf2(6, 11);
    assert(!(tf1 == tf2));
    assert(tf1 != tf2);
    assert(!(tf1 < tf2));
    assert(tf1 > tf2);
    assert(!(tf1 <= tf2));
    assert(tf1 >= tf2);
    }
    // Тест 3: Проверка равенства
    {
    Fraction tf1(4, 3);
    Fraction tf2(8, 6);
    assert(tf1 == tf2);
    assert(!(tf1 != tf2));
    assert(!(tf1 < tf2));
    assert(!(tf1 > tf2));
    assert(tf1 <= tf2);
    assert(tf1 >= tf2);
    }
    // Тест 4: Проверка сценария
    {
    Fraction tf1(3, 4);
    Fraction tf2(4, 5);

    assert((tf1 + tf2).dump() == "31/20");
    assert((tf1 - tf2).dump() == "-1/20");
    assert((tf1 * tf2).dump() == "3/5");
    assert((tf1 / tf2).dump() == "15/16");
    assert((++tf1 * tf2).dump() == "7/5");
    assert(tf1.dump() == "7/4");
    assert((tf1-- * tf2).dump() == "7/5");
    assert(tf1.dump() == "3/4");
    }
    // Тест 5: Дополнительные проверки с унарным минусом
    {
    Fraction tf1(2, 3);
    Fraction tf2(-2, 3);

    assert((-tf1).dump() == "-2/3");
    assert((-tf2).dump() == "2/3");
    assert((-tf1) == tf2);
    }
    // Тест 6: Проверка сокращения дробей
    {
    Fraction tf1(4, 8);
    Fraction tf2(2, 4);

    assert(tf1.dump() == "1/2");
    assert(tf2.dump() == "1/2");
    assert(tf1 == tf2);
    }
    std::cout << "УСПЕХ: ВСЕ ЮНИТ-ТЕСТЫ ASSERТ УСПЕШНО ПРОЙДЕНЫ!" << std::endl;
    }
    catch (const char* error) {
    std:: cout << "Oshibka! " << error << std::endl;
    }
return 0;
}