#include<iostream>
#include <cstdio>
#include"stdlib.h"
#define L 500005
using namespace std;
int arr[L];
int b[L];
int ja = 0;
int jb = 0;
//����
//��������n���㣬������һ������[a, b]���Լ����������ڵĵ�����
//
//����
//��һ�а��������������������n����ѯ�Ĵ���m��
//
//�ڶ��а���n������Ϊ����������ꡣ
//
//����m�У�������������������ѯ��������ұ߽�a��b��
//
//���
//��ÿ�β�ѯ��������ڱ�����[a, b]�ڵ�ĸ�����
//
//����
//��Ӣ������
//
//����(����Ҫ�������ƣ�ָ���ǲ������ݵ�����)
//0 �� n, m �� 5��105
//
//����ÿ�β�ѯ������[a, b]������a �� b
//
//��������껥��
//
//��������ꡢ��ѯ����ı߽�a��b����Ϊ������10 ^ 7�ķǸ�����
//
//ʱ�䣺2 sec
//
//�ڴ棺256 MB
//void merge(int *arr, int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = i; j < n; j++)
//		{
//			if (arr[i] > arr[j])
//			{
//				int a = arr[i];
//				arr[i] = arr[j];
//				arr[j] = a;
//			}
//		}
//	}
//}
int compare(const void *a, const void *b)
{
	int *pa = (int*)a;
	int *pb = (int*)b;
	return (*pa) - (*pb); 
}

void swap(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

int binsearch(int *arr, int e,int n)
{
	int r1 = 0;
	int r2 = n;
	int mi;
	if (e < arr[r1])
		return -1;
	while (1<r2-r1)
	{
		mi = (r1 + r2) >> 1;
		if (e<arr[mi])
		{
			r2 = mi;
		}
		else
		{
			r1 = mi;
		}
	}
	
	if (arr[r1] == e && ja == 0)
		jb = 1;
	return r1;
	
}
int main()

{
	int n, m, a, b;
	scanf("%d%d",&n,&m);
		for (int i = 0; i < n; i++)
		{
			scanf("%d",&arr[i]);
		}
		//merge(arr, n);
		qsort(arr, n, sizeof(int), compare);
		int arrab [2*L];
		for (int i = 0; i < 2 * m; i++)
		{
			scanf("%d",&arrab[i]);
			scanf("%d",&arrab[++i]);

		}
		int c, v;
		for (int i = 0; i < 2 * m; i++)
		{
			a = arrab[i];
			b = arrab[++i];
			
			v = binsearch(arr, a, n);
			ja= 1;
			c = binsearch(arr, b, n);
			if(jb==1)printf("%d\n",c-v+1);
			else printf("%d\n", c - v);
			ja = 0;
			jb = 0;
			

		}

}