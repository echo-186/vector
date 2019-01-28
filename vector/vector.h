#pragma once
#include"fib.h"
#ifndef VECTOR_H
#define VECTOR_H
#define DEFAULT_CAPACITY 3
typedef int Rank;


template<typename T>
class vector
{
private:
	Rank _size;
	int _capacity;
	T *_elem;//��ģ��������������
protected:
	void expand();//�����ռ䲻��ʱ����
	void shrink();
	void merge(Rank lo, Rank hi,Rank mi);


public:
	vector();
	~vector();
	void copyFrom(T*const A, Rank lo, Rank hi);//���ڻ����������͵ĸ���
	T &operator[](Rank r)const;//�����±��������ʹ������������ʽ���ø���Ԫ��,�˺�����V[R]��Ӧ�ڲ���V._elem[R]
	Rank insert(Rank r,T const&e);
	int remove(Rank lo, Rank hi);
	T remove(Rank r);//ɾ������������
	int deduplicate();//Ψһ����ɾ����������е��ظ�Ԫ��,����ɾ������
	Rank find(T const&e,Rank lo,Rank hi);//��������˳������㷨,0<=lo<hi<=_size
	/*void traverse(void(* visit)(T&))//����ָ�����
	{
		for(int i=0;i<_size;i++)visit(_elem[i])
	}
	*/
	int disordered();//���������
	int uniquify();//�����޳��ظ�Ԫ�أ���Ч�汾��,���ع�ģ�仯��
    Rank binsearch(T const&e, Rank lo, Rank hi);//���ֲ��ң��汾A��
	Rank fibSearch(T const&e, Rank lo, Rank hi);
	Rank binsearchB(T const&e, Rank lo, Rank hi);//�汾B(������loҲ�ǲ�����e�������)
	void mergeSort(Rank lo, Rank hi);//��������T(n)=T(n/2)+O(n)


};
#endif