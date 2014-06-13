
#include "MySqList.h"
#include <string.h>
template <typename Type>
MySqList<Type>::MySqList()
{
	len = 10;
	data = new Type[len];
}

template <typename Type>
MySqList<Type>::MySqList(MySqList<Type> *t)
{
	if((t->Len() > len) || (this != t))
	{
		len = t->len;
		data = new Type[len+1];

		memcpy(data, t->data, len*sizeof(Type));
	/*	for(int i=0;i<len;i++)
			data[i] = t->data[i];*/
		data[len] = 0;
	}
}

template <typename Type>
MySqList<Type>::MySqList(int n, const Type* arr)
{
	if(!arr)
	{
		len = 0;
		data = 0;
		return;
	}
	len = n;
	if(data != arr && len <= n)
	{
		data = new Type[len+1];
	}
	memcpy(data, arr, len*sizeof(Type));
	/*for(int i=0;i<n;i++)
		data[i] = arr[i];*/
	data[len]=0;
}

template <typename Type>
MySqList<Type>::~MySqList()
{
	delete[] data;
	data = 0;
}


template <typename Type>
Type* MySqList<Type>::Data()
{
	return data;
}

template <typename Type>
const int MySqList<Type>::Len()
{
	return len;
}

template <typename Type>
const Type MySqList<Type>::get(int ind)
{
	return data[ind];
}

template <typename Type>
void MySqList<Type>::set(int ind, Type v)
{
	data[ind] = v;
}

template <typename Type>
void MySqList<Type>::swap(int ind1, int ind2)
{
	if(ind1 == ind2)
		return;
	Type temp = data[ind1];
	data[ind1] = data[ind2];
	data[ind2] = temp;
}

template <typename Type>
void MySqList<Type>::showdata()
{
	for(int i=0; i<len-1; i++)
		cout<<data[i]<<" ";
	cout<<data[len-1]<<endl;
}