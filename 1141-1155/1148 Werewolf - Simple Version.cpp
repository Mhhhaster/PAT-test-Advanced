#include<iostream>
#include<stdlib.h>
using namespace std;
//本题启示，如果题目要求找到最小的i和k，就要以i和k所有情况开始遍历
//不能用撒谎的人情况来遍历，而应该用狼人情况来遍历，情况会简单很多
//比较坑的点是，说法模糊，实际上意思就是一狼人一好人撒谎
int main()
{
	int a[101];
	int N;
	cin >> N;
	for(int i=1;i<=N;i++)
		scanf_s("%d", &a[i]);
	for(int i=1;i<N;i++)
		for (int j = i+1; j <= N; j++)//遍历所有的狼人情况
		{//现在第i号和第j号是狼人,其他人是好人
			int liarnum = 0;
			int tag = 0;//0代表没有狼人撒谎
			for (int k = 1; k <= N; k++)
			{
				if (a[k] > 0)//第k个人说好人
				{
					if (a[k] == i || a[k] == j)//他说的好人是狼人
					{
						liarnum++;
						if (k == i || k == j)
							tag++;
					}
				}
				if (a[k] < 0)//第k个人找狼人
				{
					if (-a[k] != i &&-a[k] != j)//找到的狼人是错的
						liarnum++;
					if (k == i || k == j)
						tag++;
				}
			}
			if (liarnum == 2&&tag==1)//未判断是否有狼人撒谎
			{
				printf("%d %d", i, j);
				return 0;
			}
		}
	printf("No Solution");
	return 0;
}