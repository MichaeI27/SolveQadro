//#include "TXLib.h"
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "Tests.h"
#include "CompareStrAndNumbers.h"
#include "Solver.h"
bool ScanCoeff(double *a, double *b, double *c);

//! Подключены считыватели количества строк ввода и массив,
//! который записывает эти строки
//! При надобности запускаются тесты флагом -t
//! @return Количество корней
//! @retval 1 если провалились тесты или введенные коэффициенты не числа с плавающей запятой
//! @retval 0 если все проверки прошли.

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
    if (ScanCoeff(&a, &b, &c) == true)
    {
        count = SolveQuadratic(a, b, c, &x1, &x2);
        printf("korni: %lg, %lg kolvo korney: %d\n", x1 ,x2, count);
        return 0;

    }
    return 1;

}

//! Проверка на то что коэффициенты - числа
//! Водятся a, b, c, коэффициенты уравнения
//! @return Количество корней
//! @retval 0 если коэффициенты не числа
//! @retval 1 в противном

bool ScanCoeff(double *a, double *b, double *c)
{
    assert(a != NULL);
    assert(b != NULL);
    assert(c != NULL);

    int r=2;
    int m=2;
    double *abc[]={a, b, c};
    for (int i=0; i<3; i++)
    {
        printf("vvedite koaff pri x**%d:", m);
        r = scanf("%lg", abc[i]);
        if (r != 1)
        {
            printf("durak!\n");
            return false;
        }
        m-=1;
    }
    printf("a = %lg, b = %lg, c = %lg\n", *a, *b, *c);
    return true;
}
