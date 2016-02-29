#include "sortsupport.h"
#include "selection.h"
#include "insertion.h"
#include "shellsort.h"
#include "mergesort.h"
#include "mergesortm.h"
#include "mergesortbu.h"
#include <string>
#include <time.h>
#include <stdlib.h>
using namespace std;

template <typename T>
void test(T a[],int n, void(*sort)(T a[],int n))
{
    cout << endl;
    show(a,n);
    sort(a,n);
    assert(isSorted(a,n));
    show(a,n);
}

int main(int argc, char** argv)
{
    int a[8] = {3,8,7,99,348,32,88,256};
    int b[8] = {1,87,65,98,578,365,67,39};
    string c[9] = { "haha", "mimi", "suki", "jones", "johnny",
        "swift", "abandon", "boku","gahara"};
    int aa[25] = { 9, 3, 6, 7, 8, 2, 22, 11, 4, 23, 0, 13, 25, 35,
        87, 31, 29, 82, 88, 95, 101, 293, 100, 58, 65 };    
    int bb[25] = { 7, 34, 4, 6, 77, 33, 95, 87, 30, 27, 797, 433,
        235, 18, 101, 15, 3, 1, 0, 73, 95, 11, 2, 71, 60};
    int cc[50] = { 9, 3, 6, 7, 8, 2, 22, 11, 4, 23, 0, 13, 25, 35,
        87, 31, 29, 82, 88, 95, 101, 293, 100, 58, 65,7, 34, 4, 6,
        77, 33, 95, 87, 30, 27, 797, 433, 235, 18, 101, 15, 3, 1, 
        0, 73, 95, 11, 2, 71, 60 };
    
    int* dd = new int[50];
    srand((unsigned)time(NULL));
    for(int i = 0; i < 50; i++){
        dd[i] = rand() % 100;
    }
    cout << "Testing...";
    test(a,8,selectionSort);
    test(b,8,insertionSort);            
    test(c,9,insertionSortM);
    test(aa,25,shellSort);
    test(bb,25,mergeSort); 
    test(cc,50,mergeSortM);
    test(dd,50,mergeSortBU);
    
    delete [] dd;
    return 0;
}
