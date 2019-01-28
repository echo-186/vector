#pragma once
#include<vector>
using namespace std;//���Ҫ�У�û����һ��vector���ò���
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


