#pragma once
#include "vector.h"
template<typename T> vector<T>::vector()
{
	_capacity = DEFAULT_CAPACITY;
	_size = 0;
	_elem = new T[_capacity];
}
template<typename T>vector<T>::~vector()
{
	delete[]_elem;
}
template<typename T>void vector<T>::copyFrom(T * const A, Rank lo, Rank hi)
{
	_elem = new T[_capacity = 2 * (hi - lo)];
	_size = 0;//规模清零
	while (lo < hi)
	{
		_elem[_size++] = A[lo++];
	}
}
/*
1.const 的使用，使得成员函数不能更改成员变量与调用非Const函数
2.操作符重载：返回值为类型T的引用，使得返回值可以成为左值；
*/
template<typename T>T & vector<T>::operator [](Rank r)const

{
	return _elem[r];
}
template<typename T>Rank vector<T>::insert(Rank r, T const & e)
{
	expand();//判断有没有需要扩容
	for (int i = _size; i > r; i--)
	{
		_elem[i] = _elem[i - 1];
	}
	_elem[r] = e;
	_size++;
	return r;
}
template<typename T>int vector<T>::remove(Rank lo, Rank hi)//删除的是[lo,hi)
{
	if(lo==hi)
	return 0;
	while(hi < _size)
	{
		_elem[lo++] = _elem[hi++];
	}
	_size = lo;
	shrink();
	return hi - lo;//返回被删除元素数
}
template<typename T>void vector<T>::expand()
{
	if (_size < _capacity)//未满员时不必扩容
		return;
	if (_capacity < DEFAULT_CAPACITY)//如果向量空间小于最低容量
		_capacity = DEFAULT_CAPACITY;
	T *_oldElem = _elem;
	_elem = new T[_capacity = 2 * _capacity];
	for (int i = 0; i < _size; i++)
	{
		_elem[i] = _oldElem[i];
	}//复制元素
	delete[]_oldElem;
}
template<typename T>void vector<T>::shrink()
{
	if (_capacity < DEFAULT_CAPACITY << 1)return;
	if (_size << 2 > _capacity)return;//以25%为界
	
		T *_oldElem = _elem;
		_elem = new T[_capacity=_capacity>>1];
		for(int i=0;i++;i<_size)
		_elem[i]= _oldElem[i];
		delete[]_oldElem;

}

template<typename T>
void vector<T>::merge(Rank lo, Rank hi, Rank mi)
{
	/*T *A = _elem + lo;//别忘了
	int lb = mi - lo;
	T*B = new T[lb];
	for (Rank i = 0; i < lb; B[i] = A[i++]);
	int lc = hi - mi;
	T*C = _elem + mi;
	for (Rank i = 0, j = 0, k = 0; ((j < lb) || (k < lc));)
	{
		if ((j < lb) && ((lc <= k )||( B[j] <= C[k]))
			A[i++] = B[i++];
	    if((k < lc) && (lb <= j || (C[k] < B[j]))
			A[i++] = C[k++];
	}
	delete[]B;*/
}

template<typename T>T vector<T>::remove(Rank r)
{
	shrink();
	T tem = _elem[r];
	remove(r, r+1);
	return tem;
}
template<typename T>int vector<T>::deduplicate()
{
	int _oldsize = _size;//记录原规模
	Rank i = 1;
	while (i < _size)
		0 < find(_elem[i],0, i) ? remove(i) : i++;
	return _oldsize - _size;
}

template<typename T>Rank vector<T>::find(T const&e, Rank lo, Rank hi)
{
	while ((lo < hi--) && (_elem[hi] != e));//从后向前顺序查找
	return hi;//若hi<lo则查找失败
}

template<typename T>int vector<T>::disordered()
{
	int n = 0;
	for (int i = 1; i < _size; i++)
	{
		if (_elem[i-1] > _elem[i])
			n++;
	}
	return n;

}


template<typename T>int vector<T>::uniquify()
{
	int i = 0; int j = 0;
	while (++j<_size)
	{
		if (_elem[i] != _elem[j])
			_elem[++i] = _elem[j];
	}
	_size = ++i;
	return j - i;;
}

template<typename T>
Rank vector<T>::binsearch(T const & e, Rank lo, Rank hi)
{
	Rank mi;
	while (lo < hi)
	{
		mi = (lo + hi) >> 1;
		if (e < _elem[mi])
			hi = mi;
		else if (_elem[mi] < e)
			lo = mi + 1;
		else
			return mi;
}
	return -1;
}

template<typename T>
Rank vector<T>::fibSearch(T const & e, Rank lo, Rank hi)
{
	fib f(hi - lo);//创建数列
	while (lo<hi)//确认合法区间
	{
		while(hi-lo<f.get())f.prev();//判断是否需要取其前一项，不可省略。
		Rank mi = lo + f.get() - 1;
		if (e < _elem[mi])hi = mi;
		else if ( _elem[mi]<e )lo = mi + 1;
		else return mi;
	}
	return -1;
}

template<typename T>
Rank vector<T>::binsearchB(T const & e, Rank lo, Rank hi)
{
	Rank mi;
	while (1<hi-lo)
	{
		mi = (lo + hi) >> 1;
		if (e < _elem[mi])
			hi = mi;
		else
			lo = mi ;
	
	}
	return (e == _elem[lo] ? lo:-1);
}

template<typename T>
void vector<T>::mergeSort(Rank lo, Rank hi)
{
	if (hi - lo < 2) return;//单区间元素自然有序，递归基可这样取
	int mi = (lo + hi) >> 1;
	mergeSort(lo, mi);
	mergeSort(mi, hi);
	merge(lo, hi,mi);
}







