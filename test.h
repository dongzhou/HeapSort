#include<iostream>
using namespace std;
class MyClass
{
public:
	MyClass(){}
	~MyClass(){}
	void fun()
	{
		cout<<"base fun"<<endl;
	}
	virtual void fun1()
	{
		cout<<"base fun1"<<endl;
	}
private:

};
class MyClass1:public MyClass
{
public:
	MyClass1(){}
	~MyClass1(){}
	void fun(int a)
	{
		cout<<"my fun int"<<endl;
	}
	int fun()
	{
		cout<<"my fun"<<endl;
		return 0;
	}
	void fun1()
	{
		cout<<"my fun1"<<endl;
	}
private:

};


class A

{  

	virtual void g(){

	cout << "A::g" << endl;  }

private:  

	virtual void f(){

	cout << "A::f" << endl;  } 

}; 
class B : public A {

	void g() {

	cout << "B::g" << endl;  }

	virtual void h(){

	cout << "B::h" << endl;  } 

}; 
typedef void( *Fun )( void ); 

typedef struct BiTNode
{
	int data;
	BiTNode *lchild;
	BiTNode *rchild;
}*pBTree;

 typedef struct path
 {  BiTNode * tree;   
   //������ݳ�Ա  
	struct path* next;      //���ָ���Ա 
}PATH,*pPath; 

void init_path( pPath* L ) 
{  
	*L = ( pPath )malloc( sizeof( PATH ) );  //�������� 
	( *L )->next = NULL;  
} 

void push_path(pPath H, pBTree T) 
{  
	pPath p = H->next;  pPath q = H;   
	while( NULL != p )
	{
		q = p; 
		p = p->next; 
	} 
	p = ( pPath )malloc( sizeof( PATH ) );  //�����½�� 
	p->next = NULL;     //��ʼ���½�� 
	p->tree = T;    
	q->next = p; 
//�½����ջ 
} 

void print_path( pPath L ) 
{  
	pPath p = L->next;    
	while( NULL != p )     //��ӡ��ǰջ���������� 
	{   
		printf("%d, ", p->tree->data);  
		p = p->next;  
	}  
} 

void pop_path( pPath H ) 
{  
	pPath p = H->next;  
	pPath q = H;   
	if( NULL == p )      //���鵱ǰջ�Ƿ�Ϊ�� 
	{
		printf("Stack is null!\n");   
		return;  
	} 
	p = p->next; 
	while( NULL != p )     //��ջ 
	{   
		q = q->next;   
		p = p->next;  
	} 
	 free( q->next );      //�ͷų�ջ���ռ� 
	 q->next = NULL;  
} 

int IsLeaf(pBTree T) 
{  return ( T->lchild == NULL )&&( T->rchild==NULL );  } 


int find_path(pBTree T, int sum, pPath L)
{  
	int record = 0;
	push_path( L, T);  record += T->data;  
	if( ( record == sum ) && ( IsLeaf( T ) ) )  
	//��ӡ���������ĵ�ǰ·�� 
	{   
		print_path( L );    
		printf( "\n" );  
	} 
	if( T->lchild != NULL )     //�ݹ���ҵ�ǰ�ڵ������ 
	{  
		find_path( T->lchild, sum, L);  
	} 
	if( T->rchild != NULL )      //�ݹ���ҵ�ǰ�ڵ���Һ��� 
	{  
		find_path( T->rchild, sum, L); 
	} 
	record -= T->data;   
	pop_path(L);   
	return 0; 
} 