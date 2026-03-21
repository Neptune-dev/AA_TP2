#include <stdlib.h>
#include <time.h>
#include "include/test.h"

void initRandom ()
{
    srand(time(NULL));
}

// met les n premieres valeurs de t à un entier aléatoire entre -maxPositiveValue et +maxPositiveValue
void randomiseTable (int t[], int n, int maxPositiveValue)
{
    for (int  i = 0; i < n; i++)
    {
        t[i] = (rand() % (2 * maxPositiveValue)) - maxPositiveValue;
    }
}
