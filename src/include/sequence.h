#ifndef SEQUENCE_H
#define SEQUENCE_H

typedef struct Sequence {
    int * t;
    int d;
    int f;
    int (*sum)(struct Sequence *);
    void (*print)(struct Sequence *);
} Seq;

int sumSequence (Seq * sequence);
void printSequence (Seq * sequence);
Seq newSequence (int t[], int d, int f);

#endif