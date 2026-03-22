#include <stdio.h>
#include "include/sequence.h"
#include "include/submax.h"
#include "include/test.h"

int main (int argc, char * argv[])
{
    //int maxTableSize = 1000;
    //int var = 10;
//
    //double** tbl = testRoutine (maxTableSize, var, 3, m1, m2, m3);
    ////printResults(tbl, maxTableSize, 3);
    //exportResultsToCSV(tbl, maxTableSize, 3, "test.csv");
//
    //freeResults(tbl, 3);


    int tbl[100];
    
    initRandom();
    randomiseTable(tbl, 100, 10);
    printTable(tbl, 100, "tbl");

    Seq s1 = m1(tbl, 100);
    Seq s2 = m2(tbl, 100);
    Seq s3 = m3(tbl, 100);

    s1.print(&s1);
    s2.print(&s2);
    s3.print(&s3);

    return 0;

}