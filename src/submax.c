#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
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


// trouve la meilleure séquence qui traverse mid
// private
Seq maxCrossingSeq(int t[], int left, int mid, int right)
{
    int leftSum = INT_MIN;
    int sum = 0;
    int maxLeft = mid;
    for (int i = mid; i >= left; i--)
    {
        sum += t[i];
        if (sum > leftSum)
        {
            leftSum = sum;
            maxLeft = i;
        }
    }

    int rightSum = INT_MIN;
    sum = 0;
    int maxRight = mid + 1;
    for (int j = mid + 1; j <= right; j++)
    {
        sum += t[j];
        if (sum > rightSum)
        {
            rightSum = sum;
            maxRight = j;
        }
    }

    return newSequence(t, maxLeft, maxRight);
}

// divide and conquer principal
// private
Seq mainDC(int t[], int left, int right)
{
    if (left == right)
    {
        return newSequence(t, left, right);
    }

    int mid = (left + right) / 2;

    Seq leftSeq = mainDC(t, left, mid);
    Seq rightSeq = mainDC(t, mid + 1, right);
    Seq crossSeq = maxCrossingSeq(t, left, mid, right);

    int leftSum = leftSeq.sum(&leftSeq);
    int rightSum = rightSeq.sum(&rightSeq);
    int crossSum = crossSeq.sum(&crossSeq);

    if (leftSum >= rightSum && leftSum >= crossSum)
    {
        return leftSeq;
    } else if (rightSum >= leftSum && rightSum >= crossSum)
    { 
        return rightSeq;
    } else
    {
        return crossSeq;
    }
}

Seq m3(int t[], int n)
{
    return mainDC(t, 0, n - 1);
}