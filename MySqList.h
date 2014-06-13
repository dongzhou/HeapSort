#ifndef __MYSQLIST
#define __MYSQLIST
template <typename Type>
class MySqList
{
private:
	int len;
	Type* data;
public:
	MySqList();
	MySqList(MySqList<Type> *t);
	MySqList(int n, const Type* arr);
	const int Len();
	Type* Data();
	void swap(int ind1, int ind2);
	const Type get(int ind);
	void set(int ind, Type v);
	void showdata();
	~MySqList();
};
#endif