#pragma once
typedef int Rank;
#define DEFAULT_CAPACITY 3

template<class T>
class vector
{
private:
	Rank _size;
	int _capacity;
	T *_elem;//规模，容量，数据区
protected:
void copyFrom(T*const A, Rank lo, Rank hi);//基于基本数据类型的复制
public:
	vector();
	~vector();
	T&[] operator[](Rank r)const;//重载下标操作符，使类似于数组形式引用各个元素
	


};

