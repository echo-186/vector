#include "vector.h"
template<class T>
vector<T>::vector()
{
	_capacity = DEFAULT_CAPACITY;
	_size = 0;
	_elem = new T[_capacity];
}

template<class T>
vector<T>::~vector()
{
}
template<class T>
void vector<T>::copyFrom(T * const A, Rank lo, Rank hi)
{
	_elem = new T[_capacity = 2 * (hi - lo)];
	size = 0;//πÊƒ£«Â¡„
	while (lo < hi)
	{
		_elem[size++] = A[lo++];
	}
}
template<class T>
T &[] operator[](Rank r) const
{
	return T & []();
}
