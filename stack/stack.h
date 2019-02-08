#pragma once
#include<vector>
using namespace std;//这个要有，没有这一句vector类用不了
template<typename T>
class stack: public vector<T>
{
public:
	stack();
	~stack();
	void push(T const &e) { insert(size(*this), e); }
	T pop() { return remove(size(*this) - 1); }
	T &top() { return (*this)[size(*this) - 1]; }
	//栈的应用
	/*1.进制转换*/
	void convert(stack<char> &S, __int64 n, int base);//栈，数，进制 _int64见onenote/数/栈
	/*2.括号匹配*/
	bool paren(const char exp[], int lo, int hi);//exp[lo,hi)
	/*栈混洗,自己写的*/
	bool HunXi(const char before[], const char after[],int n);
	/*中缀表达式求值*/
	float evaluate(char *S);//传入表达式，输出值

};


