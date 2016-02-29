#ifndef MERGESORTBU_H
#define MERGESORTBU_H
template <typename T>
void iMerge(T a[], T aux[],int lo, int mid, int hi)
{
    for(int i = lo; i<= hi;i++){
        aux[i] = a[i];
    }
    int i = lo,j = mid+1;
    for(int k = lo; k <=hi;k++){
        if(i > mid)           { a[k]= aux[j++];}
        else if(j>hi)         { a[k]= aux[i++];}
        else if(aux[j]<aux[i]){ a[k]= aux[j++];}
        else                  { a[k]= aux[i++];}
    }
}

template <typename T>
void mergeSortBU(T a[], int n)
{
    T* aux = new T[n];
    for(int sz = 1; sz < n; sz = sz + sz){
        for(int lo = 0; lo < n-sz; lo += sz + sz){
            iMerge(a,aux,lo, lo+sz-1, lo+sz+sz-1<n-1?lo+sz+sz-1:n-1);
        }
    }
    delete [] aux;
}
#endif
