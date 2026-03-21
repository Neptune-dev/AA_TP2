#ifndef TEST_H
#define TEST_H

#include "sequence.h"

void initRandom();
void randomiseTable (int t[], int n, int maxPositiveValue);
double testMethod(Seq (*submaxMethod)(int*, int), int t[], int n, Seq *methodResult);

#endif