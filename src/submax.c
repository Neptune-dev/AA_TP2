#include <stdlib.h>
#include <stdio.h>
#include "include/submax.h"
#include "include/sequence.h"

// t est le tableau et n sa taille
Seq m1 (int t[], int n)
{
    Seq maxSequence = newSequence(t, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            Seq s = newSequence (t, i, j);
            if (maxSequence.sum(&maxSequence) < s.sum(&s))
            {
                maxSequence = s;
            }
        }
    }
    return maxSequence;
}

Seq m2 (int t[], int n)
{
    Seq maxSequence = newSequence(t, 0, n - 1);
    int maxSum = maxSequence.sum(&maxSequence);

    for (int i = 0; i < n; i++)
    {
        int sum = t[i];
        for (int j = i + 1; j < n; j++)
        {
            sum += t[j];
            if (maxSum < sum)
            {
                maxSum = sum;
                maxSequence = newSequence(t, i, j);
            }
        }
    }
    return maxSequence;
}

Seq m3 (int t[], int n)
{
    int size = n/2;

    // préparation des échantillons du tbl
    int* t1 = (int*)malloc(size * sizeof(int));
    if (t1 == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    int* t2 = (int*)malloc(size * sizeof(int));
    if (t2 == NULL)
    {
        printf("Memory allocation failed\n");
        free(t1);
        exit(1);
    }

    int* t3 = (int*)malloc(size * sizeof(int));
    if (t3 == NULL)
    {
        printf("Memory allocation failed\n");
        free(t1);
        free(t2);
        exit(1);
    }

    // copie dans les tableaux
    int i = 0;
    while (i < size)
    {
        t1[i] = t[i];
        i++;
    }

    int j = 0;
    while (i < n)
    {
        t2[j] = t[i];
        i++;
        j++;
    }

    i = size / 2;
    j = 0;
    while (i < (3 * n) / 4)
    {
        t3[j] = t[i];
        i++;
        j++;
    }

    // calcul de la séquence pour chaque échantillon
    Seq s1 = m2(t1, size);
    Seq s2 = m2(t2, size);
    Seq s3 = m2(t3, size);

    Seq maxSequence;
    // comparaison
    if ((s1.sum(&s1) > s2.sum(&s2)) && (s1.sum(&s1) > s3.sum(&s3)))
    { 
	    maxSequence = s1;
    } 
    else if (s2.sum(&s2) > s3.sum(&s3))
    {
        maxSequence = s2;
    } else
    {
        maxSequence = s3;
    }

    free(t1);
    free(t2);
    free(t3);

    return maxSequence;
}
