#include "MySqList.h"

template <typename Type>
void HeapSort(MySqList<Type>* L)
{
	for(int i = (L->Len()-1)/2; i>=0; i--)
		HeapAdjust(L, L->Len(), i);
	for(int i=L->Len()-1; i>=0; i--)
	{
		L->swap(0, i);
		HeapAdjust(L, i, 0);
	}
}

template <typename Type>
void HeapAdjust(MySqList<Type>* L, int n, int i)
{
	int temp, s;
	temp = L->get(i);
	for(s=2*i+1; s<n; s = s*2+1)
	{
		if(s<n-1 && L->get(s) < L->get(s+1))
		{
			s++;
		}
		if(temp >= L->get(s))
		{
			break;
		}
		L->swap(i,s);
		i = s;
	}
}
