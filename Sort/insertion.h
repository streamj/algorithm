#ifndef INSERTION_H
#define INSERTION_H
#include "sortsupport.h"

template <typename T>
void insertionSort(T a[], int n)
{
    for(int i = 0; i < n; i++){
        for(int j = i;j>0;j--){
            if(a[j]<a[j-1]){
                exch(a,j,j-1);
            }else{
                break;
            }
        }
    }
}

// improve version, less exch
template <typename T>
void insertionSortM(T a[], int n)
{
    for(int i = 0; i < n; i++){
        int j = i;
        T temp = a[i];
        for(;j>0 && temp <a[j-1];j--){
            a[j] = a[j-1];
        }
        a[j] = temp;
    }
}

#endif
