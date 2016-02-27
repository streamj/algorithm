#ifndef SORTSUPPORT_H
#define SORTSUPPORT_H
#include <iostream>
template<typename T>
bool lessthan(const T& a, const T& b)
{
    if(a<b) return true;
    return false;
}

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

#endif
