#pragma once
#include"fib.h"
#ifndef VECTOR_H
#define VECTOR_H
#define DEFAULT_CAPACITY 3
typedef int Rank;


template<typename T>
class vector
{
private:
	Rank _size;
	int _capacity;
	T *_elem;//规模，容量，数据区
protected:
	void expand();//向量空间不足时扩容
	void shrink();
	void merge(Rank lo, Rank hi,Rank mi);


public:
	vector();
	~vector();
	void copyFrom(T*const A, Rank lo, Rank hi);//基于基本数据类型的复制
	T &operator[](Rank r)const;//重载下标操作符，使类似于数组形式引用各个元素,此后对外的V[R]对应内部的V._elem[R]
	Rank insert(Rank r,T const&e);
	int remove(Rank lo, Rank hi);
	T remove(Rank r);//删除操作的重载
	int deduplicate();//唯一化，删除无序操作中的重复元素,返回删除长度
	Rank find(T const&e,Rank lo,Rank hi);//无序向量顺序查找算法,0<=lo<hi<=_size
	/*void traverse(void(* visit)(T&))//函数指针机制
	{
		for(int i=0;i<_size;i++)visit(_elem[i])
	}
	*/
	int disordered();//有序性甄别
	int uniquify();//向量剔除重复元素（高效版本）,返回规模变化量
    Rank binsearch(T const&e, Rank lo, Rank hi);//二分查找（版本A）
	Rank fibSearch(T const&e, Rank lo, Rank hi);
	Rank binsearchB(T const&e, Rank lo, Rank hi);//版本B(若返回lo也是不大于e的最大秩)
	void mergeSort(Rank lo, Rank hi);//快速排序T(n)=T(n/2)+O(n)


};
#endif