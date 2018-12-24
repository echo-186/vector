#pragma once
#ifndef FIB_H
#define FIB_H


class fib
{
private:
	int _n;//³¤¶È
	int*_fib;
public:
	fib(int n);
	~fib();
	int get();
	void prev();
};
#endif 
