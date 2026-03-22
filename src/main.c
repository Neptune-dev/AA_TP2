#include <stdio.h>
#include "include/sequence.h"
#include "include/submax.h"
#include "include/test.h"

int main (int argc, char * argv[])
{
    int maxTableSize = 10000;
    int var = 10;

    double** tbl = testRoutine (maxTableSize, var, 2, m2, m3);
    //printResults(tbl, maxTableSize, 3);
    exportResultsToCSV(tbl, maxTableSize, 2, "out.csv");

    freeResults(tbl, 2);

    //int t[20];
    //initRandom();
    //randomiseTable(t, 20, var);
    //Seq me2;
    //Seq buffer;
    //testMethod(m2, t, 20, &me2);
    //testMethod(m3, t, 20, &buffer);
    //printTable(t, 20, "t");
    //me2.print(&me2);
    //buffer.print(&buffer);

    return 0;

}