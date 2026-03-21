#ifndef TEST_H
#define TEST_H

#include "sequence.h"

typedef Seq (*SubmaxMethod)(int*, int);

void initRandom ();
void freeResults(double** resultsTable, int func);
void randomiseTable (int t[], int n, int maxPositiveValue);
double testMethod(SubmaxMethod submaxMethod, int t[], int n, Seq *methodResult);
double** testRoutine (int maxTableSize, int n, int func, ...);

#endif