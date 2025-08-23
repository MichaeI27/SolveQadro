#include <stdio.h>
#include <math.h>

void solveLinear(double b, double c, double* x1, double* x2, double* count);
void solveQuadratic(double a, double b, double c, double *x1, double *x2, double *count);
bool scanCoef(double *a, double *b, double *c);
//---------------------------------
int main()
{
    double a=0, b=0, c=0, x1=0, x2=0, count=0;
    // TODO int scanResult = ...
    // if (scanResult == 0) ...
    // --------------------OR-----------------------
    // if (scanCoef(...) == 0) ...
    if (scanCoef(&a, &b, &c) == true)
    {
        solveQuadratic(a, b, c, &x1, &x2, &count);
        printf("korni: %g, %g kolvo korney: %g", x1 ,x2, count);
        return 0;
    }
    return 1;
}
//------------------------------------
void solveLinear(double b, double c, double* x1, double* x2, double* count)
{
    if (b == 0)
    {
        if (c == 0)
        {
        // TODO fix tabs
        *x1 = *x2 = 0;
        *count = -1;
        }
        else
        {
        *x1 = *x2 = 0;
        *count = 0;
        }
    }
    else
    {
        *x1 = *x2 = -c/b;
        *count = 1;
    }
}
//-------------------------------------------
bool scanCoef(double *a, double *b, double *c)
{
    int r=2;
    int m=2; // TODO what is r?

    // TODO move to function
    // if (!scanCoeff('2', a)) {
    //     return 1;
    // }
    for (int i=0; i<3; i++)
    {
        printf("vvedite koaff pri x**%d:", m);
        r = scanf("%lg", a);
        if (r==0)
        {
            printf("durak!");
            return false;
        }
        m-=1;
    }
    return true;
}
//-----------------------------------------------------
void solveQuadratic(double a, double b, double c, double* x1, double *x2, double *count)
{
    if (a == 0)
    {
        solveLinear(b, c, x1, x2, count);
    }
    else
    {
        if ((b*b-4*a*c) < 0)
        {
            *x1 = *x2 = 0;
            *count = 0;
        }
        else
        {
            if ((b*b-4*a*c) == 0)
            {
                *x1 = *x2 = -b/(2*a);
                *count = -1;
            }
            else
            {
                *x1 = (-b + sqrt(b*b-4*a*c))/(2*a);
                *x2 = (-b - sqrt(b*b-4*a*c))/(2*a);
                *count = 2;
            }
        }
    }
}
