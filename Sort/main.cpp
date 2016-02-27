#include "sortsupport.h"
#include "selection.h"
#include "insertion.h"
#include "shellsort.h"
#include <string>
#include <iostream>

using namespace std;
template <typename T>
void printarray(T a[], int n)
{
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

int main(int argc, char** argv)
{
    int a[8] = {3,8,7,99,348,32,88,256};
    int b[8] = {1,87,65,98,578,365,67,39};
    string c[9] = { "haha", "mimi", "suki", "jones", "johnny",
        "swift", "abandon", "boku","gahara"};
    int aa[25] = { 9, 3, 6, 7, 8, 2, 22, 11, 4, 23, 0, 13, 25, 35,
        87, 31, 29, 82, 88, 95, 101, 293, 100, 58, 65 };    
    printarray(a,8);
    selectionSort(a,8);
    printarray(a,8);

    cout << endl;

    printarray(b,8);
    insertionSort(b,8);
    printarray(b,8);

    cout << endl;

    printarray(c,9);
    insertionSortM(c,9);
    printarray(c,9);

    cout << endl;

    show(aa,25);
    shellSort(aa,25);
    show(aa,25);

    return 0;
}
