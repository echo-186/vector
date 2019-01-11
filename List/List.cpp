#include<iostream>
#include "List.h"
using namespace std;
template<typename T>
void List<T>::init()
{
	header = new ListNode<T>;//这里调用的是默认构造函数
	trailer = new ListNode<T>;
	header->succ = trailer;
	header->pred = nullptr;
	trailer->pred = header;
	trailer->succ = nullptr;
	_size = 0;
}

template<typename T>
void List<T>::clear()
{
	while (0<_size)
	{
		remove(header->succ);

	}
}

template<typename T>
void List<T>::copyNodes(ListNode<T> * p, int n)
{
	init();
	while (n > 0) {
		n--;
		InsertAsLast(p->data);
		p = p->succ;
	}
}

template<typename T>
ListNode<T>* List<T>::selectmax(ListNode<T>* p, int n)
{
	ListNode<T> *tem = p;
	while (n--)
	{
		if (p->data < tem->data)
			tem = p;
		p = p->succ;
	}
	return tem;
}

template<typename T>
ListNode<T> * List<T>::find(const T &e,int n,ListNode<T>*p)const
{
	while (0<n--)
	{
		p = p->pred;
		if (p->data == e)
			return p;
	}
	return nullptr;
}
template<typename T>
ListNode<T> * List<T>::find(const T &e, ListNode<T>*p ,int n)const
{
	ListNode<T> *tem = new ListNode<T>;//创指针指向结构体时这么写就好了，无需像结构体数组那样写明分配多少空间
	tem = nullptr;
	while (0 < n--)
	{
		p = p->succ;
		if (p->data == e)
			tem=p;
	}
	return tem;
}

template<typename T>
ListNode<T>* List<T>::search(const T & e, int n, ListNode<T>* p) const
{
	ListNode<T> *tem = p;
    ListNode<T>*tem = p->pred;
	while (n--)
	{
		if (tem->data <= e)
			return tem;
		tem = tem->pred;
	}
	
	return nullptr;
}

template<typename T>
ListNode<T>* List<T>::InsertAsFirst(T const & e)
{
	_size++;//别忘了扩大规模
	return header->insertAsSucc(e);
}

template<typename T>
ListNode<T>* List<T>::InsertAsLast(T const & e)
{
	_size++;
	return trailer->insertAsPred(e) ;
}

template<typename T>
ListNode<T>* List<T>::InsertBefore(T const & e, ListNode<T> * p)
{
	_size++;
	return p->insertAsPred(e);
}

template<typename T>
ListNode<T>* List<T>::InsertAfter(ListNode<T>* p, T const & e)
{
	_size++;
	return p->insertAsSucc(e);
}

template<typename T>
T List<T>::remove(ListNode<T>* p)
{
	T e = p->data;
	p->succ->pred = p->pred;
	p->pred->succ = p->succ;
	_size--;
	delete p;
	return e;
}

template<typename T>
int List<T>::deduplicate()
{
	int _oldsize = _size;
	if (_size < 2)//平凡列表自然唯一
		return 0;
	ListNode<T>*tem = new ListNode<T>;
	tem = header;//从首届点开始
	int i = 0;
	while (tem!=trailer)
	{
		find(tem->data, i, tem)?remove(find(tem->data, i, tem)):i++;
		tem = tem->succ;
	}
	return _oldsize-_size;//返回规模（_size此时已经改变了）
}

template<typename T>
int List<T>::uniquify()
{
	int _oldsize = _size;
	if (_size < 2)//先考虑平凡情况
		return 0;
	ListNode<T>* p = first();//考虑起始条件
	ListNode<T>*q = p->succ;
	while (trailer!=q)//再考虑边界条件
	{
		if (p->data == q->data)
			remove(q);
		else
			p = q;
	}
	q = p->succ;//注意！别写成q=q.succ,q remove释放后指针还在，但指向的空间已经被释放了
	return _oldsize-_size;
}

template<typename T>
void List<T>::selectionSort( ListNode<T>*p,int n)
{
	ListNode<T>*head = p->pred;
	ListNode<T>*tail = p;
	for (int i = 0; i < n; i++)
	{
		tail = tail->succ;
	}
	while (1<n)
	{
		ListNode<T>*max = selectmax(p->pred, n);
		InsertBefore(tail, remove(max));
		n--;
		tail = tail->pred;
	}
}

template<typename T>
void List<T>::insertSort(ListNode<T>* p, int n)
{
	int r = 0;
	while (n-->=0)
	{
		InsertAfter(search(p->data,r++, p), p->data);
		p = p->succ;//有趣
		remove(p->pred);//有趣
	}
}


template<typename T>
List<T>::List()
{
	init(); 
}

template<typename T>
List<T>::List(ListNode<T>  * p, int n)
{
	copyNodes(p, n);
}

template<typename T>
List<T>::~List()
{
	clear();
	delete header;
	delete trailer;
}

template<typename T>
T&List<T>::operator[](int r) const
{
	ListNode<T> *p = new ListNode<T>;
	p = header;
	while (r-->0)
	{
		p = p->succ;
	}
	return p->data;
}
