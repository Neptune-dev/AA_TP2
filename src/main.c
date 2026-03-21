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
    //int test[] = {1, -8, 4, -5, -5, 3, 2, -1, 3};
    //Seq res = m2 (test, 9);
    //res.print(&res);

    initRandom();

    int test[1000];
    printTable(test, 1000, "test avant randomise");
    randomiseTable(test, 1000, 10);
    printTable(test, 1000, "test apres randomise");

    Seq res;
    double v = testMethod(m1, test, 1000, &res);
    res.print(&res);
    printf("time : %f\n", v);


    return 0;
}