#ifndef MERGESORTM_H
#define MERGESORTM_H
#include "sortsupport.h"
#include <assert.h>

#define LINE 10

template <typename T>
void insertSort(T a[], int lo, int hi)
{
    for(int i = lo; i <= hi;i++){
        int j = i;
        T temp = a[i];
        for(;j>lo && temp <a[j-1]; j--){
            a[j] = a[j-1];
        }
        a[j] = temp;
    }
}

template <typename T>
void mergeM(T a[], T aux[], int lo ,int mid, int hi)
{
    assert(isSorted(aux, lo, mid));
    assert(isSorted(aux, mid+1,hi));
    
    // eliminate recursive copy
    int i = lo, j = mid+1;
    for(int k = lo; k <=hi; k++){
        if(i>mid){
            a[k] = aux[j++];
        }
        else if (j>hi){
            a[k] = aux[i++];
        }
        else if (aux[j]<aux[i]){
            a[k] = aux[j++];
        }
        else { a[k] = aux[i++];}
    }
    assert(isSorted(a,lo,hi));
}

template <typename T>
void innerSortM(T a[], T aux[],int lo, int hi)
{   // using insertSort when array is small
    if(hi <= lo + LINE){
        insertSort(a,lo,hi);
        return;
    }

    int mid = lo + (hi - lo) /2 ;
    // eliminate copy to the auxiliary array by switching the role of
    // input and auxiliary array each recursive call like 1,2,3
    innerSortM(aux, a, lo, mid);   // here 1
    innerSortM(aux, a, mid+1, hi); // here 2
    // check if alread sorted, then no need merge
    if(aux[mid] <= aux[mid+1]){
        for(int i = lo; i <= hi; i++){
            a[i] = aux[i];
        }
        return;
    }

    mergeM(a,aux,lo,mid,hi);       // here 3
}
template <typename T>
void mergeSortM(T a[], int n){
    T* aux = new T[n];

    for(int i = 0; i < n; i++){
        aux[i] = a[i];
    }
    innerSortM(a,aux,0,n-1);
}
#endif

