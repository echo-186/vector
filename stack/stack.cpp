#include "stack.h"


template<typename T>
stack<T>::stack()//��һ����
{
	vector<T>();
}

template<typename T>
stack<T>::~stack()//��һ����
{
	~vector<T>();
}

template<typename T>
void stack<T>::convert(stack<char>& S, __int64 n, int base)
{
	static char digit[] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };//�ɸ���baseֵ�ʵ�����
	while (n > 0)
	{
		S.push(digit[n%base]);//��������Ӧ����λ����ջ
		n = n / base;
	}
}

template<typename T>
bool stack<T>::paren(const char exp[], int lo, int hi)
{
	stack<char> *s;
	while (hi-lo>0)
	{
		if (exp[lo] == '(')
			s->push(exp[lo]);
		else if (exp[lo] == ')')
		{
			if (s->empty())
			{
				return false;

			}
			s->pop();
		}
		

	}
	return s->empty();
}

template<typename T>
bool stack<T>::HunXi(const char before[], const char after[], int n)
{
	stack<char>S;//�м�ջ
	int i = 0;
	int j = n - 1;

	while (i <= n)
	{
		if (S.empty() || after[j] != S.top())
		{
			S.push(before[i++]);
		}
		if (after[j] == S.top())
		{
			S.pop();
			j--;
		}


	}
	return S.empty() ? 1 : 0;
}
