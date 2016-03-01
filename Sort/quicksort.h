#ifndef QUICKSORT_H
#define QUICKSORT_H
#include "sortsupport.h"
#include <algorithm>
#include <ctime>
#include <cstdlib>

template <typename T>
int partition(T a[], int lo, int hi)
{
    int i = lo,j = hi+1;
    T v = a[lo];
    while(true){
        while(a[++i]<v){
            if(i==hi)break;
        }
        while(a[--j]>v){
            if(j==lo)break;
        }

        if(i>=j)break;

        exch(a,i,j);
    }
    exch(a,lo,j);
    return j;
}

template <typename T>
void iSort(T a[], int lo, int hi)
{
    if(hi <= lo) return;

    int j = partition(a,lo,hi);
    iSort(a,lo,j-1);
    iSort(a,j+1,hi);
}

template <typename T>
void quickSort(T a[], int n)
{
    // shuffle
    std::srand((unsigned)time(NULL));
    std::random_shuffle(&a[0],&a[n-1]);
    iSort(a,0,n-1);
}

#endif
