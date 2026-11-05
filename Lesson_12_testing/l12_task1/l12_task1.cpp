#include "pch.h"
#include "CppUnitTest.h"
#include "extended_array.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace l12task1
{
    TEST_CLASS(ExtArrayTests)
    {
    public:

        // Задание 1: Проверка пустых массивов
        TEST_METHOD(TestTask1EmptyArrays)
        {
            ExtArray<int> empty_arr({});

            Assert::AreEqual(0.0, empty_arr.mean());
            Assert::AreEqual(0.0, empty_arr.median());

            auto mode_res = empty_arr.mode();
            Assert::AreEqual(0, mode_res.second); // Частота моды должна быть 0
        }

        // Задание 2: Проверка среднего арифметического для диапазона
        TEST_METHOD(TestTask2MeanRange)
        {
            ExtArray<double> arr({ 1.0, 2.0, 3.0, 4.0, 5.0 });

            // Корректный диапазон: элементы с индексами 1, 2, 3 (это 2.0, 3.0, 4.0) -> среднее 3.0
            Assert::AreEqual(3.0, arr.mean(1, 4));

            // Ошибочный диапазон (start >= end) — проверяем, что выбрасывается исключение
            auto invalid_range_func1 = [&]() { arr.mean(4, 2); };
            Assert::ExpectException<std::invalid_argument>(invalid_range_func1);

            auto invalid_range_func2 = [&]() { arr.mean(2, 2); };
            Assert::ExpectException<std::invalid_argument>(invalid_range_func2);
        }

        // Задание 3: Проверка контрольной суммы (checkSum)
        TEST_METHOD(TestTask3Checksum)
        {
            // 1. Проверка правильности результата
            ExtArray<bool> bool_arr({ true, false, true, true, false }); // 3 единицы
            Assert::AreEqual(3, bool_arr.checkSum());

            ExtArray<int> int_binary_arr({ 1, 0, 1, 1, 0, 0 }); // 3 единицы
            Assert::AreEqual(3, int_binary_arr.checkSum());

            // 2. Проверка типа массива (должно выбросить std::bad_typeid для double)
            ExtArray<double> double_arr({ 1.0, 0.0 });
            auto invalid_type_func = [&]() { double_arr.checkSum(); };
            Assert::ExpectException<std::bad_typeid>(invalid_type_func);

            // 3. Проверка содержимого массива (должно выбросить std::logic_error, если есть двойка)
            ExtArray<int> int_invalid_arr({ 1, 0, 2, 1 });
            auto invalid_content_func = [&]() { int_invalid_arr.checkSum(); };
            Assert::ExpectException<std::logic_error>(invalid_content_func);
        }
    };
}
