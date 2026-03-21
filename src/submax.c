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
    Seq a = newSequence (t, 0, n/2);
    Seq b = newSequence (t, (n/2) + 1, n);
    Seq c = newSequence (t, (n/2), (n/2));

    if ((a > b) && (a > c))
    { 
	return a;
    } 
    else if (b > c)
    {
	return b;
    }
    else return c; 
    
}
