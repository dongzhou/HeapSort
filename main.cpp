// sorts.cpp : 定义控制台应用程序的入口点。
//
#include <iostream>
using namespace std;

#include "MySqList.cpp"
#include "HeapSort.h"
#include "InsertSort.h"
#include "QuickSort.h"

class Base
{ 
public:
	virtual void f()
	{ cout << "Base::f" << endl; } 
	virtual void g() 
	{ cout << "Base::g" << endl; } 
	virtual void h() 
	{ cout << "Base::h" << endl; } 
};
typedef void(*Fun) (void);
int data = 0;

int main()
{
	int b[9]={1,6,7,8,9,256,3,4,5};  
	char a[] = "deabghcf";
	int len = sizeof(b)/sizeof(int);
	
	MySqList<int > *L = new MySqList<int>(len,b);
	MySqList<char> *ls = new MySqList<char>(strlen(a),a);
	MySqList<char> *c = new MySqList<char>(ls);
	QuickSort(ls, 0, ls->Len()-1);
	InsertSort(L, 0, L->Len()-1);
	HeapSort(c);
	HeapSort(L);
	L->showdata();
	c->showdata();
	cin>>a;
	return 0;
}