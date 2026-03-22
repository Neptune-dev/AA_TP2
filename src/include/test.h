#ifndef TEST_H
#define TEST_H

#include "sequence.h"

typedef Seq (*SubmaxMethod)(int*, int);

void initRandom ();
void freeResults(double** resultsTable, int func);
void randomiseTable (int t[], int n, int maxPositiveValue);
double testMethod(SubmaxMethod submaxMethod, int t[], int n, Seq *methodResult);
double** testRoutine (int maxTableSize, int n, int func, ...);
void printResults (double** results, int maxTableSize, int func);
void printTable (int *t, int n, char* label);
void exportResultsToCSV(double** results, int maxTableSize, int func, const char* filename);

#endif