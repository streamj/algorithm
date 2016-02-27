#include "sortsupport.h"

template <typename T>
void selectionSort(T a[], int n)
{
    for(int i = 0; i < n; i++){
        int min = i;
        for(int j = i+1; j< n;j++){
            if(a[j] < a[min]) min = j;
        }
        exch(a, i, min);
    }
}
