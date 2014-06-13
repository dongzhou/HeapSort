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
   //结点数据成员  
	struct path* next;      //结点指针成员 
}PATH,*pPath; 

void init_path( pPath* L ) 
{  
	*L = ( pPath )malloc( sizeof( PATH ) );  //创建空树 
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
	p = ( pPath )malloc( sizeof( PATH ) );  //申请新结点 
	p->next = NULL;     //初始化新结点 
	p->tree = T;    
	q->next = p; 
//新结点入栈 
} 

void print_path( pPath L ) 
{  
	pPath p = L->next;    
	while( NULL != p )     //打印当前栈中所有数据 
	{   
		printf("%d, ", p->tree->data);  
		p = p->next;  
	}  
} 

void pop_path( pPath H ) 
{  
	pPath p = H->next;  
	pPath q = H;   
	if( NULL == p )      //检验当前栈是否为空 
	{
		printf("Stack is null!\n");   
		return;  
	} 
	p = p->next; 
	while( NULL != p )     //出栈 
	{   
		q = q->next;   
		p = p->next;  
	} 
	 free( q->next );      //释放出栈结点空间 
	 q->next = NULL;  
} 

int IsLeaf(pBTree T) 
{  return ( T->lchild == NULL )&&( T->rchild==NULL );  } 


int find_path(pBTree T, int sum, pPath L)
{  
	int record = 0;
	push_path( L, T);  record += T->data;  
	if( ( record == sum ) && ( IsLeaf( T ) ) )  
	//打印符合条件的当前路径 
	{   
		print_path( L );    
		printf( "\n" );  
	} 
	if( T->lchild != NULL )     //递归查找当前节点的左孩子 
	{  
		find_path( T->lchild, sum, L);  
	} 
	if( T->rchild != NULL )      //递归查找当前节点的右孩子 
	{  
		find_path( T->rchild, sum, L); 
	} 
	record -= T->data;   
	pop_path(L);   
	return 0; 
} 