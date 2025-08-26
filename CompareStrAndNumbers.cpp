#include <math.h>
#include "CompareStrAndNumbers.h"
#define epsilon 0.000001



//! Правильное сравнивание чисел под С------------------------------------
bool Compare(double FirstNumber, double SecondNumber)
{
    if (abs(FirstNumber - SecondNumber) < epsilon)//если 1 число == 2 число
    {
        return true;
    }
        return false;
}

//Сравнивание строк-------------------------------
bool CompareStr(const char* Stroka1, const char* Stroka2)
{
    int q = 0;
    while(Stroka1[q] != '\0')
    {
        if (*(Stroka1 + q) != *(Stroka2 + q))
        {
            return false;
        }
        q +=1;
    }
    return true;
}
