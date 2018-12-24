#pragma once
#include "fib.h"
fib::fib(int n)
{
	_fib = new int[n];
	_fib[0] = _fib[1] = 1;
	int i = 0,f1=1,f2=1;
	while (_fib[i++]< n)
	{
		if (i != 0 && i != 1)
		{
			_fib[i] = f1 + f2;
			f1 = f2;
			f2 = _fib[i];
		}
	}
	_n = i;
}

fib::~fib()
{
	
		delete[]_fib;
	
}

int fib::get()
{
	
	return _fib[_n-1];
}

void fib::prev()
{
	_n--;
}
