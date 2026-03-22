#include <stdio.h>
#include "include/sequence.h"
#include "include/submax.h"
#include "include/test.h"

int main (int argc, char * argv[])
{
    int maxTableSize = 1000;
    int var = 10;

    double** tbl = testRoutine (maxTableSize, var, 3, m1, m2, m3);
    //printResults(tbl, maxTableSize, 3);
    exportResultsToCSV(tbl, maxTableSize, 3, "test.csv");

    freeResults(tbl, 3);

    return 0;

}