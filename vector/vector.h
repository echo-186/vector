#pragma once
typedef int Rank;
#define DEFAULT_CAPACITY 3

template<class T>
class vector
{
private:
	Rank _size;
	int _capacity;
	T *_elem;//��ģ��������������
protected:
void copyFrom(T*const A, Rank lo, Rank hi);//���ڻ����������͵ĸ���
public:
	vector();
	~vector();
	T&[] operator[](Rank r)const;//�����±��������ʹ������������ʽ���ø���Ԫ��
	


};

