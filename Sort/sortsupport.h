#ifndef SORTSUPPORT_H
#define SORTSUPPORT_H
#include <iostream>

template <typename T>
void exch(T a[], int i, int j)
{
    T t = a[i];
    a[i] = a[j];
    a[j] = t;
}

template <typename T>
void show(T a[], int n)
{
	for (int i = 0; i < n; i++){
		std::cout << a[i] << " ";
	}
	std::cout << std::endl;
}

template <typename T>
bool isSorted(T a[], int n)
{
	for (int i = 1; i < n; i++){
		if (a[i] < a[i - 1]) return false;
	}
	return true;
}

// for merge sort
template <typename T>
bool isSorted(T a[], int lo, int hi)
{
	for (int i = lo + 1; i <= hi; i++){
		if (a[i] < a[i - 1]){ return false; }
	}
	return true;
}
#endif
