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
//	����const������ĳ�Ա�������Լ�ָ��ͱ�ָָ��֮��ǣһ����ȫ��Ĺ�ϵ
//tem = p->first();
//	p->first() = tem;//���У��ᱨ��
//	p->first()->succ = tem;//����
//	p->first()->data = 7;//����ֱ���޸��б��е�ֵ
//	tem->data = 7;//<=>p.first().succ=7,�޸�tem�൱��ֱ���޸�p�еĽڵ�
//	cout <<p->first()->succ->data //7
////�ܽ�:1.const������ĳ�Ա�������������������޸ķǳ�Ա���ݵĵ�ַ��ֵ��2.ָ��ṹ��ָ��Ľṹ��ָ��ı��Ա��Ҳ��ı�ԭ��Ա��
	for (int i = 0; i < 10; i++)
	{
		tem = p->first();
		cout << tem->data << " " << tem << endl;
		tem = tem->succ;
	}

	system("pause");
}