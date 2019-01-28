#pragma once
#include<vector>
using namespace std;//这个要有，没有这一句vector类用不了
template<typename T>
class stack: public vector<T>
{
public:
	stack();
	~stack();
	void push(T const &e) { insert(size(), e); }
	T pop() { return remove(size() - 1); }
	T &top() { return (*this)[size() - 1]; }
};


