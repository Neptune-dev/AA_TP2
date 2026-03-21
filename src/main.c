#include <stdio.h>
#include "include/sequence.h"
#include "include/submax.h"
#include "include/test.h"

void printTable (int *t, int n, char* label)
{
    printf("%s : ", label);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", t[i]);
    }
    printf("\n");
}

int main (int argc, char * argv[])
{
    
    double** tbl = testRoutine (500, 10, 3, m1, m2, m3);

    freeResults(tbl, 3);

    return 0;

}