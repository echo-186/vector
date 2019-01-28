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
//	描述
//	祖玛是一款曾经风靡全球的游戏，其玩法是：在一条轨道上初始排列着若干个彩色珠子，其中任意三个相邻的珠子不会完全同色。此后，你可以发射珠子到轨道上并加入原有序列中。一旦有三个或更多同色的珠子变成相邻，它们就会立即消失。这类消除现象可能会连锁式发生，其间你将暂时不能发射珠子。
//
//	开发商最近准备为玩家写一个游戏过程的回放工具。他们已经在游戏内完成了过程记录的功能，而回放功能的实现则委托你来完成。
//
//	游戏过程的记录中，首先是轨道上初始的珠子序列，然后是玩家接下来所做的一系列操作。你的任务是，在各次操作之后及时计算出新的珠子序列。
//
//	输入
//	第一行是一个由大写字母'A'~'Z'组成的字符串，表示轨道上初始的珠子序列，不同的字母表示不同的颜色。
//
//	第二行是一个数字n，表示整个回放过程共有n次操作。
//
//	接下来的n行依次对应于各次操作。每次操作由一个数字k和一个大写字母Σ描述，以空格分隔。其中，Σ为新珠子的颜色。若插入前共有m颗珠子，则k ∈[0, m]表示新珠子嵌入之后（尚未发生消除之前）在轨道上的位序。
//
//	输出
//	输出共n行，依次给出各次操作（及可能随即发生的消除现象）之后轨道上的珠子序列。
//
//	如果轨道上已没有珠子，则以“ - ”表示。

struct Node
{
	char data;
	Node*next;
	Node*pred;
};
void insertafter(Node *elem,char e)//在elem后插入e
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

	//标准的不知道要读取多少字符，输入后按一次回车结束的方式
	//scanf("%c", &queue);//只能读取一个字符,是错误的
	gets_s(queue); //能读取一串字符，但读不了空格之后的
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