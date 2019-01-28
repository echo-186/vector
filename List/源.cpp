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
	//cout << "p.first()" << p->first()->data <<" "<< p->first() << endl;

	//	//p->first() = tem;//不行，会报错
	//	//p->first()->data = 7;//可以直接修改列表中的值
	//	//tem->data = 7;//<=>p.first().succ=7,修改tem的成员相当于直接修改p中的节点成员数据
	//	//cout << p->first()->data<<endl; //7
	//	//cout << tem->data;//7,修改p中节点成员相当于修改tem成员

	//	p->first()->succ = p->first()->succ->succ;
	//	cout <<tem<<" "<<tem->data<<endl;//
	//	cout << p->first()->succ<<" "<< p->first()->succ->data<<endl;//oof768  2
	//	tem = tem->succ;
	//	cout << tem<<" " << tem->data<<endl;//oof768  2（tem->first(),此时的first().suc已经变成原先first().suc.suc,tem.suc指向此时first().suc）
	//	//cout << p->first()->succ<<" " << p->first()->succ->data<<endl;//oof768  2
	////总结:1.const修饰类的成员函数不拦着你在类外修改非成员数据的值和地址,2.指向结构体指针的结构体指针改变指向，不会改变原成员指针指向，
	//但原成员指针指向一变动，指向它的指针随之变动。

	system("pause");
}