#ifndef MERGESORT_H
#define MERGESORT_H
#include "sortsupport.h"
#include <assert.h>
template <typename T>
void merge(T a[], T aux[], int lo, int mid, int hi)
{
	assert(isSorted(a, lo, mid));
	assert(isSorted(a, mid + 1, hi));
	// copy a[lo, hi] to aux [lo, hi]
	for (int k = lo; k <= hi; k++){
		aux[k] = a[k];
	}
	// merge a[lo, mid] ... a[mid+1, hi]
	int i = lo, j = mid + 1;
	for (int k = lo; k <= hi; k++){
		// left side has no member, use right side
		if (i > mid)				{ a[k] = aux[j++]; }
		// right side has no member, use left side
		else if (j > hi)			{ a[k] = aux[i++]; }
		// right < left, use left and index j++
		else if (aux[j] < aux[i])	{ a[k] = aux[j++]; }
		// left >= right use left and index i++
		else						{ a[k] = aux[i++]; }
	}

	assert(isSorted(a, lo, hi));
}

template <typename T>
void inner_sort(T a[], T aux[], int lo, int hi)
{	// notice the = case
	if (hi <= lo){ return; }

	int mid = lo + (hi - lo) / 2;
	// recursive
	inner_sort(a, aux, lo, mid);
	inner_sort(a, aux, mid + 1, hi);

	merge(a, aux, lo, mid, hi);
}

template <typename T>
void mergeSort(T a[], int n)
{	// create a aux array here, avoid recursive create
	T* aux = new T[n];
	inner_sort(a, aux, 0, n - 1);
	delete[] aux;
}
#endif
