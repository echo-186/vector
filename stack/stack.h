#pragma once
#include<vector>
using namespace std;//���Ҫ�У�û����һ��vector���ò���
template<typename T>
class stack: public vector<T>
{
public:
	stack();
	~stack();
	void push(T const &e) { insert(size(*this), e); }
	T pop() { return remove(size(*this) - 1); }
	T &top() { return (*this)[size(*this) - 1]; }
	//ջ��Ӧ��
	/*1.����ת��*/
	void convert(stack<char> &S, __int64 n, int base);//ջ���������� _int64��onenote/��/ջ
	/*2.����ƥ��*/
	bool paren(const char exp[], int lo, int hi);//exp[lo,hi)
	/*ջ��ϴ,�Լ�д��*/
	bool HunXi(const char before[], const char after[],int n);
	/*��׺���ʽ��ֵ*/
	float evaluate(char *S);//������ʽ�����ֵ

};


