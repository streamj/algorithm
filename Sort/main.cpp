#include "sortsupport.h"
#include "selection.h"
#include "insertion.h"
#include "shellsort.h"
#include "mergesort.h"
#include <string>

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
    show(a,8);
    selectionSort(a,8);
    show(a,8);

    cout << endl;

    show(b,8);
    insertionSort(b,8);
    show(b,8);

    cout << endl;

    show(c,9);
    insertionSortM(c,9);
    show(c,9);

    cout << endl;

    show(aa,25);
    shellSort(aa,25);
    show(aa,25);
    
    cout << endl;
    show(bb,25);
    mergeSort(bb,25);
    show(bb,25);

    return 0;
}
