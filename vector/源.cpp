#pragma once
#include<iostream>
#include"vector.h"
#include"vector.cpp"
using namespace std;
int main()
{
	int A[7] = { 0,1,2,3,4,5,6 };
	vector <int> T;
	T.copyFrom(A, 0, 7);
	T.fibSearch(3, 0, 7);

}