#ifndef QUICKSORT3WAY_H
#define QUICKSORT3WAY_H
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include "sortsupport.h"

template <typename T>
void sort3Way(T a[], int lo, int hi)
{
    if(hi<=lo) return;

    int lt = lo, gt = hi;
    T v = a[lo];
    int i = lo;
    while(i <= gt) {
        if(a[i] < v)     { exch(a,lt++,i++);}
        else if(a[i]>v)  { exch(a,i,gt--);}
        else             { i++;}
    }

    sort3Way(a,lo,lt-1);
    sort3Way(a,gt+1,hi);
}

template <typename T>
void quickSort3Way(T a[], int n)
{
    std::srand((unsigned)time(NULL));
    std::random_shuffle(&a[0],&a[n-1]);
    sort3Way(a,0,n-1);
}
#endif
