//#include "TXLib.h"
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "Tests.h"
#include "CompareStrAndNumbers.h"


int main(int argc, const char* argv[])
{
    if (argc == 2 && CompareStr(argv[1], "-t"))
    {
        if (!TestSolve())
        {
            return 1;
        }
    }
    double a=0, b=0, c=0, x1=0, x2=0;
    int count=0;
    if (ScanCoaff(&a, &b, &c) == true)
    {
        count = SolveQuadratic(a, b, c, &x1, &x2);
        printf("korni: %lg, %lg kolvo korney: %d\n", x1 ,x2, count);
        return 0;

    }
    return 1;

}

// //! Правильное сравнивание чисел под С------------------------------------
// bool Compare(double FirstNumber, double SecondNumber)
// {
//     if (abs(FirstNumber - SecondNumber) < epsilon)//если 1 число == 2 число
//     {
//         return true;
//     }
//         return false;
// }

//Решение линейного уравнения (a = 0)------------------------------------
int SolveLinear(double b, double c, double* x1, double* x2)
{
    if (Compare(b, 0.0))
    {
        if (Compare(c , 0.0))
        {
            *x1 = *x2 = 0;
            return -1;
        }
        else
        {
            *x1 = *x2 = 0;
            return 0;
        }
    }
    else
    {
        *x1 = *x2 = -c/b;
        return 1;
    }
}

//Скан и проверка правильного ввода (не принимает ввод строк)-------------------------------------------
bool ScanCoaff(double *a, double *b, double *c)
{
    int r=2;
    int m=2;
    double *abc[]={a, b, c};
    for (int i=0; i<3; i++)
    {
        printf("vvedite koaff pri x**%d:", m);
        r = scanf("%lg", abc[i]);
        if (r != 1)
        {
            printf("durak!");
            return false;
        }
        m-=1;
    }
    printf("a = %lg, b = %lg, c = %lg\n", *a, *b, *c);
    return true;
}

//Решение квадратного уравнения (a != 0)-----------------------------------------------------
int SolveQuadratic(double a, double b, double c, double *x1, double *x2)
{
    assert(x1 != NULL);
    assert(x2 != NULL);
    assert(!isinf(a) && !isnan(a));
    assert(!isinf(b) && !isnan(b));
    assert(!isinf(c) && !isnan(c));
    if (Compare(a, 0))// если а == 0
    {
        return SolveLinear(b, c, x1, x2);
    }
    else
    {
        if ((b*b-4*a*c) < 0)
        {
            *x1 = *x2 = 0;
            return 0;
        }
        else
        {
            if (Compare(b*b - 4*a*c, 0))
            {
                *x1 = *x2 = -b/(2*a);
                return 1;
            }
            else
            {
                *x1 = (-b + sqrt(b*b-4*a*c))/(2*a);
                *x2 = (-b - sqrt(b*b-4*a*c))/(2*a);
                return 2;
            }
        }
    }
}

// //Сравнивание строк-------------------------------
// bool CompareStr(const char* Stroka1, const char* Stroka2)
// {
//     int q = 0;
//     while(Stroka1[q] != '\0')
//     {
//         if (*(Stroka1 + q) != *(Stroka2 + q))
//         {
//             return false;
//         }
//         q +=1;
//     }
//     return true;
// }
