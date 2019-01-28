#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include"stdio.h"
#include"string.h"
#define MAX 20000
using namespace std;
char queue[MAX];
//Input
//
//
//Output
//
//ABCCBA
//AABCCBA
//AABBCCBA
//-
//A
//Restrictions
//0 <= n <= 10 ^ 4
//
//0 <= length of the initial sequence <= 10 ^ 4
//
//Time: 2 sec
//
//	Memory : 256 MB
//
//	����
//	������һ����������ȫ�����Ϸ�����淨�ǣ���һ������ϳ�ʼ���������ɸ���ɫ���ӣ����������������ڵ����Ӳ�����ȫͬɫ���˺�����Է������ӵ�����ϲ�����ԭ�������С�һ�������������ͬɫ�����ӱ�����ڣ����Ǿͻ�������ʧ����������������ܻ�����ʽ����������㽫��ʱ���ܷ������ӡ�
//
//	���������׼��Ϊ���дһ����Ϸ���̵ĻطŹ��ߡ������Ѿ�����Ϸ������˹��̼�¼�Ĺ��ܣ����طŹ��ܵ�ʵ����ί��������ɡ�
//
//	��Ϸ���̵ļ�¼�У������ǹ���ϳ�ʼ���������У�Ȼ������ҽ�����������һϵ�в�������������ǣ��ڸ��β���֮��ʱ������µ��������С�
//
//	����
//	��һ����һ���ɴ�д��ĸ'A'~'Z'��ɵ��ַ�������ʾ����ϳ�ʼ���������У���ͬ����ĸ��ʾ��ͬ����ɫ��
//
//	�ڶ�����һ������n����ʾ�����طŹ��̹���n�β�����
//
//	��������n�����ζ�Ӧ�ڸ��β�����ÿ�β�����һ������k��һ����д��ĸ���������Կո�ָ������У���Ϊ�����ӵ���ɫ��������ǰ����m�����ӣ���k ��[0, m]��ʾ������Ƕ��֮����δ��������֮ǰ���ڹ���ϵ�λ��
//
//	���
//	�����n�У����θ������β������������漴��������������֮�����ϵ��������С�
//
//	����������û�����ӣ����ԡ� - ����ʾ��

struct Node
{
	char data;
	Node*next;
	Node*pred;
};
void insertafter(Node *elem,char e)//��elem�����e
{
	Node *p = new Node;
	p->data = e;
	p->next = elem->next;
	p->pred = elem;
	elem->next = p;
	p->next->pred = p;
}

string print(Node*elem, int size,string str)
{
	if (size == 0)
	{
		//printf("%c","-");
		str = str+"-";
	}
	else
	{while (size--)
		{
				//printf("%c", elem->data);
				str=str+elem->data;
			elem = elem->next;
		}

	}
	return str;
	
}
int judge(Node*head,Node *tail, int size)
{
	
		Node *p = new Node;
		Node *q = new Node;
	loop:	p = head;
		if (size > 2)
		{
			q = p->next->next;
			while (q != tail)
			{
				if ((p->data == p->next->data) && (q->data == p->data))
				{
					p->pred->next = q->next;
					q->next->pred = p->pred;
					p = q->next;
					if (p == tail)
					{
						size = size - 3;
						return size;
					}
					size = size - 3;
					goto loop;
				}
				else {

					p = p->next;
					q = q->next;
				}

			}
			return size;
		}
		else
		{
            return size;
		}
	
	
}
int main()
{
	
	long int _size = 0;
	Node *header = new Node;
	Node *trailor = new Node;
	trailor->pred = header;
	header->next = trailor;
	Node *p = header;

	//��׼�Ĳ�֪��Ҫ��ȡ�����ַ��������һ�λس������ķ�ʽ
	//scanf("%c", &queue);//ֻ�ܶ�ȡһ���ַ�,�Ǵ����
	gets_s(queue); //�ܶ�ȡһ���ַ����������˿ո�֮���
	//for (int i = 0; i < 5; i++)
		//cout << queue[i];
	_size = strlen(queue);
	for (int i = 0; i < _size; )
	{
		if ('A' <= queue[i] && 'Z' >= queue[i])
		{
			insertafter(p, queue[i]);
			p = p->next;
			i++;
		}
		else if (queue[i] == ' ')
		{
			_size--;
		}
		else
			return 0;
	}
	p = header;
	long int n;

	scanf("%d",&n);
	string *str = new string[n];

	int r;
	char c;
	int i = 0;
	while (n--)
	{
		scanf("%d %c", &r, &c);
		if (r == 0)
		{
			insertafter(header, c);
			_size++;
		}
		else
		{
			while (r--)
			{
				p = p->next;
			}
			insertafter(p, c);
			_size++;

		}
		p = header->next;
		_size=judge(p, trailor, _size);
		p = header->next;
		str[i]=print(p, _size,str[i])+str[i];
		i++;
		p = header;
	}
	n = 0;
	for(;n<i;n++)
	printf("%s\n", str[n].c_str());
	//printf("%d", _size);
	system("pause");
	return 0;
}