//#include "TXLib.h"
#include <stdio.h>
#include <math.h>
#include <assert.h>
#define epsilon 0.000001

struct calc
{
    double a;
    double b;
    double c;
    double x1;
    double x2;
    int count;
};
int SolveLinear(double b, double c, double* x1, double* x2);
int SolveQuadratic(double a, double b, double c, double *x1, double *x2);
bool ScanCoaff(double *a, double *b, double *c);
bool TestSolve();
bool Compare(double FirstNumber, double SecondNumber);
//---------------------------------
int main()
{
    if (TestSolve())
    {
        double a=0, b=0, c=0, x1=0, x2=0;
        int count=0;
        if (ScanCoaff(&a, &b, &c) == true)
        {
            count = SolveQuadratic(a, b, c, &x1, &x2);
            printf("korni: %lg, %lg kolvo korney: %d", x1 ,x2, count);
            return 0;
        }
        return 1;
    }
    return 1;
}
//------------------------------------
bool Compare(double FirstNumber, double SecondNumber)
{
    if (abs(FirstNumber - SecondNumber) < epsilon)//если 1 число == 2 число
    {
        return true;
    }
        return false;
}
//------------------------------------
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
//-------------------------------------------
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
//-----------------------------------------------------
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
//a b c x1 x2 count
//1 -3 2 1 2 2
//1 -6 5 1 5 2
bool TestSolve()
{
    double x1 = 0, x2 = 0;
    struct calc test[6] =
    {
        {1, -3, 2, 2, 1, 2},   // Первый набор
        {2, -6, 5, 0, 0, 0},   // Второй набор
        {0, 0, 0, 0, 0, -1},   // Третий набор !!!! <- ошибка но ее не выдает
        {0, 0, 1, 0, 0, 0},    // Четвертый набор
        {1, 2, 1, -1, -1, 1},  // Пятый набор
        {0, -2, 4, 2, 2, 1},   // Шестой набор
    };
    for(int i=0; i<6; i++)
    {
        int count = SolveQuadratic(test[i].a, test[i].b, test[i].c, &x1, &x2);
        printf("%lg, %lg, %lg, %lg, %lg, %d\n", test[i].a, test[i].b, test[i].c, x1, x2, count);
        if (!(Compare(test[i].count, count) && Compare(test[i].x1, x1) && Compare(test[i].x2, x2)))
        {
            printf("FAILD: korni: x1 = %lg, x2 = %lg, count = %d (should be x1 = %lg, x2 = %lg, count = %d)\n", x1, x2, count, test[i].x1, test[i].x2, test[i].count);
            return false;

        }
    }
    return true;
}
