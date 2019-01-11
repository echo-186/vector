#include<iostream>
#include"List.h"
#include"List.cpp"
using namespace std;
int main()
{
	List<int> *p = new List<int>;
	ListNode<int> *tem = new ListNode<int>;
	tem = p->InsertAsLast(10);
	for (int i = 10; i > 0; i--)
	{

		p->InsertBefore(i - 1, tem);
		cout << tem->data << " " << tem << endl;
	/*	if (i == 8)
		{
			p->InsertBefore(i-1, tem);
			cout << tem->data << " " << tem << endl;
		}*/
		tem = tem->pred;

	}
	p->search(5, 10, p->last());
//	关于const修饰类的成员函数，以及指针和被指指针之间牵一发动全身的关系
//tem = p->first();
//	p->first() = tem;//不行，会报错
//	p->first()->succ = tem;//可以
//	p->first()->data = 7;//可以直接修改列表中的值
//	tem->data = 7;//<=>p.first().succ=7,修改tem相当于直接修改p中的节点
//	cout <<p->first()->succ->data //7
////总结:1.const修饰类的成员函数不拦着你在类外修改非成员数据的地址和值，2.指向结构体指针的结构体指针改变成员，也会改变原成员。
	for (int i = 0; i < 10; i++)
	{
		tem = p->first();
		cout << tem->data << " " << tem << endl;
		tem = tem->succ;
	}

	system("pause");
}