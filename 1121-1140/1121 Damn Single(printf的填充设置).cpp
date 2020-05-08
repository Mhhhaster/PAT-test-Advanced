//从0遍历到99999，如果这个人出现过，且对象没有出现过，那么输出
#include<iostream>
#include<string>
using namespace std;
struct PeoNode {
	int cp=-1;
	bool pre = false;//默认没有cp
}peo[100000];
int main()
{
	int N;
	scanf("%d", &N);
	int cp1, cp2;
	while (N--)
	{
		scanf("%d%d", &cp1, &cp2);
		peo[cp1].cp = cp2;
		peo[cp2].cp = cp1;
	}
	int M;
	scanf("%d", &M);
	int man;
	while (M--)
	{
		scanf("%d", &man);
		peo[man].pre = true;
	}
	int single = 0;
	for (int i = 0; i < 100000; i++)
	{
		if (peo[i].pre == true)//首先该人得出席
		{
			if (peo[i].cp == -1)
				single++;
			else if (peo[peo[i].cp].pre == false)//要么没CP要么CP没出席
				single++;
		}
	}
	printf("%d\n", single);
	int tag = 0;
	for (int i = 0; i < 100000; i++)
	{
		if (peo[i].pre == true)//首先该人得出席
		{
			if (peo[i].cp == -1 || (peo[i].cp != -1) && (peo[peo[i].cp].pre == false))//其实同上
			{
				if (tag == 0)
				{
					printf("%05d", i);
					tag++;
				}
				else
					printf(" %05d", i);
			}
		}
	}
}
/*
结论：一定要熟知printf的填充方法；也可用set来保存结果数组，这样便是从小到大，不重复
*/