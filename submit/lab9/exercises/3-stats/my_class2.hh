#ifndef MY_CLASS2_HH_
#define MY_CLASS2_HH_
#include "ops.hh"

class my_class2 : public Ops{
	public:
		int counter_compare = 0;
		int counter_swap = 0;
	
		virtual int compare(int a, int b);
		virtual void swap(int a[], int i, int j);

};

#endif
