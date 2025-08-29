#include <assert.h>
#include <math.h>
#include "CompareStrAndNumbers.h"

static const double EPSILON = 1e-6;


//! Сравнение 2ух чисел
//! Вводимые значения: 2 числа
//! @return Сравнимы числа или нет
//! @retval true если числа сравнимы
//! @retval false если числа не сравнимы

bool Compare(double FirstNumber, double SecondNumber)
{
    assert(!isinf(FirstNumber) && !isnan(FirstNumber));
    assert(!isinf(SecondNumber) && !isnan(SecondNumber));
    if (abs(FirstNumber - SecondNumber) < EPSILON)
    {
        return true;
    }
        return false;
}

//! Сравнение 2ух строк
//! Вводимые значения: 2 строки
//! @return Сравнимы строки или нет
//! @retval true если строки сравнимы
//! @retval false если строки не сравнимы

bool CompareStr(const char* Str1, const char* Str2)
{
    assert(Str1 != NULL);
    assert(Str2 != NULL);
    int q = 0;
    while(Str1[q] != '\0')
    {
        if (*(Str1 + q) != *(Str2 + q))
        {
            return false;
        }
        q +=1;
    }
    return true;
}
