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
    show(a,8);
    selectionSort(a,8);
    assert(isSorted(a,8));
    show(a,8);

    cout << endl;

    show(b,8);
    insertionSort(b,8);
    assert(isSorted(b,8));
    show(b,8);

    cout << endl;

    show(c,9);
    insertionSortM(c,9);
    assert(isSorted(c,9));
    show(c,9);

    cout << endl;

    show(aa,25);
    shellSort(aa,25);
    assert(isSorted(aa,25));
    show(aa,25);
    
    cout << endl;
    show(bb,25);
    mergeSort(bb,25);
    assert(isSorted(bb,25));
    show(bb,25);

    cout << endl;
    show(cc,50);
    mergeSortM(cc,50);
    assert(isSorted(cc,50));
    show(cc,50);

    cout << endl;
    show(dd,50);
    mergeSortBU(dd,50);
    assert(isSorted(dd,50));
    show(dd,50);
    
    delete [] dd;
    return 0;
}
