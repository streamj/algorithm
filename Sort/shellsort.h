#ifndef SHELLSORT_H
#define SHELLSORT_H
#include "sortsupport.h"

template <typename T>
void shellSort(T a[], int n)
{
    int h = 1;
    while(h < n/3){
        h = 3*h+1;
    }

    while(h>=1){
        for(int i = h; i < n; i++){
            for(int j = i; j>=h && a[j]< a[j-h]; j-=h){
                exch(a,j,j-h);
            }
        }
        h = h/3;
    }
}

#endif
