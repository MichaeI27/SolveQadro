#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "CompareStrAndNumbers.h"
#include "Solver.h"


//! Решение квадратного уравнения
//! Вводимые данные: a, b, c - коэффициенты уравнения
//! @return Количество корней
//! @retval 0 - нет решений
//! @retval 1 - одно решение
//! @retval 2 - два решения

int SolveQuadratic(double a, double b, double c, double *x1, double *x2)
{
    assert(x1 != NULL);
    assert(x2 != NULL);
    assert(!isinf(a) && !isnan(a));
    assert(!isinf(b) && !isnan(b));
    assert(!isinf(c) && !isnan(c));
    double dis = (b*b - 4*a*c);
    if (Compare(a, 0))
    {
        return SolveLinear(b, c, x1, x2);
    }
    else
    {
        if (dis < 0)
        {
            *x1 = *x2 = 0;
            return 0;
        }
        else
        {
            if (Compare(dis, 0))
            {
                *x1 = *x2 = -b/(2*a);
                return 1;
            }
            else
            {
                *x1 = (-b + sqrt(dis)
    )/(2*a);
                *x2 = (-b - sqrt(dis)
    )/(2*a);
                return 2;
            }
        }
    }
}

//! Решение уравнения линейного (a = 0)
//! Используемые переменные: a, b, c соответственно коэффициенты
//! квадратного уравнения ax^2 + bx + c = 0. x1 и x2 корни этого
//! уравнения считаемые в процессе
//! @return Количество корней
//! @retval -1 если корней бесконечность
//! @retval 0 если ноль корней
//! @retval 1 если один корень
//! @retval 2 если два корня

int SolveLinear(double b, double c, double* x1, double* x2)
{
    assert(x1 != NULL);
    assert(x2 != NULL);
    assert(!isinf(b) && !isnan(b));
    assert(!isinf(c) && !isnan(c));
    if (Compare(b, 0))
    {
        if (Compare(c , 0))
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
