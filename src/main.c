#include <stdio.h>
#include "include/sequence.h"
#include "include/submax.h"
#include "include/test.h"

int main (int argc, char * argv[])
{
    int maxTableSize = 10000;
    int var = 20; // les valeurs du tableau seront comprises entre -var et var

    // fonction variadique (petit kiff), spécifier le nombre de fonctions testées puis les fonctions en question (m1, m2 ou m3)
    double** tbl = testRoutine (maxTableSize, var, 2, m2, m3);

    //printResults(tbl, maxTableSize, 3); // décommenter pour afficher dans le terminal
    exportResultsToCSV(tbl, maxTableSize, 2, "out.csv");

    freeResults(tbl, 2);

    return 0;

}