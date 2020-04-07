#include "my_class2.hh"
#include <iostream>
int my_class2::compare(int a, int b){
	counter_compare++;
	return Ops::compare(a, b);
}

void my_class2::swap(int a[], int i, int j){
	counter_swap++;
	Ops::swap(a, i, j);	
}
