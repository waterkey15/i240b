#ifndef SORTS_HH_
#define SORTS_HH_

#include <cassert>

#include "ops.hh"
#include "my_class2.hh"

void insertionSort(int a[], int n, my_class2* ops);
void bubbleSort(int a[], int n, my_class2* ops);
void selectionSort(int a[], int n, my_class2* ops);
void mergeSort(int a[], int n, my_class2* ops) ;
void quickSort(int a[], int n, my_class2* ops);

#endif //ifndef SORTS_HH_

