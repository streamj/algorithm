#ifndef HEAPSORT_H
#define HEAPSORT_H
// heap i is array i-1
template <typename Item>
void hs_exch(Item pq[], int i, int j)
{
    Item t = pq[i-1];
    pq[i-1] = pq[j-1];
    pq[j-1] = t;
}

template <typename Item>
bool hs_less(Item pq[], int i, int j)
{
    return pq[i-1] < pq[j-1];
}


template <typename Item>
void sink(Item pq[], int k, int n)
{
    while(2 * k <= n){
        int j = 2 * k;
        if(j < n && hs_less(pq,j,j+1)){ j++;}
        if(!hs_less(pq,k,j)) { break; }

        hs_exch(pq,k,j);
        k = j;
    }
}

template <typename Item>
void heapSort(Item pq[], int n)
{
    // create heap
    for(int k = n/2; k >=1; k--){
        sink(pq,k,n);
    }

    // sort
    while(n > 1){
        hs_exch(pq,1,n);
        sink(pq,1,--n);
    }
}

#endif
