#include<iostream>
#include <cstdio>
#include"stdlib.h"
#define L 500005
using namespace std;
int arr[L];
int b[L];
int ja = 0;
int jb = 0;
//描述
//数轴上有n个点，对于任一闭区间[a, b]，试计算落在其内的点数。
//
//输入
//第一行包括两个整数：点的总数n，查询的次数m。
//
//第二行包含n个数，为各个点的坐标。
//
//以下m行，各包含两个整数：查询区间的左、右边界a和b。
//
//输出
//对每次查询，输出落在闭区间[a, b]内点的个数。
//
//样例
//见英文题面
//
//限制(不需要你来限制，指的是测试数据的限制)
//0 ≤ n, m ≤ 5×105
//
//对于每次查询的区间[a, b]，都有a ≤ b
//
//各点的坐标互异
//
//各点的坐标、查询区间的边界a、b，均为不超过10 ^ 7的非负整数
//
//时间：2 sec
//
//内存：256 MB
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