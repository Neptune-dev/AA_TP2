#include <stdio.h>
#include "include/sequence.h"

// calcule la somme de tous les elements d'une sequence
int sumSequence (Seq * sequence)
{
    int res = 0;
    for (int i = sequence->d; i <= sequence->f; i++)
    {
        res += sequence->t[i];
    }
    return res;
}

void printSequence (Seq * sequence)
{
    printf("d   = %d\nf   = %d\nsum = %d\n", sequence->d, sequence->f, sequence->sum(sequence));
}

Seq newSequence (int t[], int d, int f)
{
    Seq res;
    res.d = d;
    res.f = f;
    res.t = t;
    res.sum = sumSequence;
    res.print = printSequence;
    return res;
}