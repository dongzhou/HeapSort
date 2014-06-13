#ifndef __QUICKSORT
#define __QUICKSORT
#include "MySqList.h"
#include "InsertSort.h"

template <typename Type>
void QuickSort(MySqList<Type>* L, int low, int high)
{
	if(high==low)
		return;
	else if(high-low < 6)
		InsertSort(L, low, high);
	else
	{
		int temp = Partition(L, low, high);
		QuickSort(L, low, temp-1);
		QuickSort(L, temp+1, high);
	}
}

template <typename Type>
int Partition(MySqList<Type>* L, int low, int high)
{
	int temp = (low+high)/2;
	while(low<high)
	{
		while(low<high&&L->get(high)>L->get(temp))
			high--;
		L->swap(temp, high);
		temp = high;

		while(low<high&&L->get(low)<L->get(temp))
			low++;
		L->swap(temp, low);
		temp = low;
	}
	return temp;
}

#endif