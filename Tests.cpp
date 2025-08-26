#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "Tests.h"
#include "CompareStrAndNumbers.h"

struct calc
{
    double a;
    double b;
    double c;
    double x1;
    double x2;
    int count;
};


//Проверка примерами----------------------------------------------
bool TestSolve()
{
    //double x1 = 0, x2 = 0;
    FILE* Examples = fopen("ExampleForTest.txt", "r");
    //ментор - check return value; use perror
    struct calc test[6] = {};
    for (int i=0; i<6; i++)
    {
        //p = fscanf(Examples, "%lg %lg %lg %lg %lg %d",&(test[i].a), &(test[i].b), &(test[i].c), &(test[i].x1), &(test[i].x2), &(test[i].count));
        fscanf(Examples, "%lg %lg %lg %lg %lg %d",&(test[i].a), &(test[i].b),
            &(test[i].c), &(test[i].x1), &(test[i].x2), &(test[i].count));
        if (fgetc(Examples) != '\n')
        {
            printf("Mistake in Examples file!, Error line - %d", i+1);
            return false;
        }
    }
    double x1 = 0, x2 = 0;
    printf("a, b, c, x1, x2, count\n");
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

