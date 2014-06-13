#ifndef __INSERTSORT
#define __INSERTSORT
#include "MySqList.h"
template <typename Type>
void InsertSort(MySqList<Type>* L, int low, int high)
{
	if(!L)
		return;
	if(high==low)
		return;
	int min_id;
	for(int i = low; i<=high; i++)
	{
		min_id = i;
		for(int j=i+1; j<=high; j++)
		{
			if(L->get(j)<L->get(min_id))
				min_id = j;
		}
		L->swap(i,min_id);
	}
}
#endif