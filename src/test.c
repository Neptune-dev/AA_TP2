#include <stdlib.h>
#include <time.h>
#include "include/test.h"
#include "include/sequence.h"

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

// renvoie le temps d'execution de submaxMethod pour les arguments t et n, stocke le resultat de la methode dans methodResult
double testMethod(Seq (*submaxMethod)(int*, int), int t[], int n, Seq *methodResult)
{
    clock_t start, end;

    start = clock();

    *methodResult = submaxMethod(t, n);

    end = clock();

    return ((double)(end - start)) / CLOCKS_PER_SEC;
}

