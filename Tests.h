#ifndef TESTS_H
#define TESTS_H

int SolveLinear(double b, double c, double* x1, double* x2);
int SolveQuadratic(double a, double b, double c, double *x1, double *x2);
bool ScanCoaff(double *a, double *b, double *c);
bool TestSolve();
// bool Compare(double FirstNumber, double SecondNumber);
// bool CompareStr(const char* Stroka1, const char* Stroka2);

#endif
