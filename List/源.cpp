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
	//cout << "p.first()" << p->first()->data <<" "<< p->first() << endl;

	//	//p->first() = tem;//���У��ᱨ��
	//	//p->first()->data = 7;//����ֱ���޸��б��е�ֵ
	//	//tem->data = 7;//<=>p.first().succ=7,�޸�tem�ĳ�Ա�൱��ֱ���޸�p�еĽڵ��Ա����
	//	//cout << p->first()->data<<endl; //7
	//	//cout << tem->data;//7,�޸�p�нڵ��Ա�൱���޸�tem��Ա

	//	p->first()->succ = p->first()->succ->succ;
	//	cout <<tem<<" "<<tem->data<<endl;//
	//	cout << p->first()->succ<<" "<< p->first()->succ->data<<endl;//oof768  2
	//	tem = tem->succ;
	//	cout << tem<<" " << tem->data<<endl;//oof768  2��tem->first(),��ʱ��first().suc�Ѿ����ԭ��first().suc.suc,tem.sucָ���ʱfirst().suc��
	//	//cout << p->first()->succ<<" " << p->first()->succ->data<<endl;//oof768  2
	////�ܽ�:1.const������ĳ�Ա�������������������޸ķǳ�Ա���ݵ�ֵ�͵�ַ,2.ָ��ṹ��ָ��Ľṹ��ָ��ı�ָ�򣬲���ı�ԭ��Աָ��ָ��
	//��ԭ��Աָ��ָ��һ�䶯��ָ������ָ����֮�䶯��

	system("pause");
}