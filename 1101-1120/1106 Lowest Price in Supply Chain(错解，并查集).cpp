#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
/*
10 1.80 1.00
3 2 3 5
1 9
1 4
1 7
0
2 6 1
1 8
0
0
0*/
int main()
{
	int N;
	double rawprice, incpercent;
	scanf("%d%lf%lf", &N, &rawprice, &incpercent);
	vector<int>a(N);//记录自己的上家
	vector<bool>b(N, false);//记录是否有下家
	int downnum, temp;
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &downnum);
		if (downnum)//有下家
		{
			while (downnum--)
			{
				scanf("%d", &temp);
				a[temp] = i;//下家指向它
				b[i] = true;
			}
		}
	}
	int times, min = 100000, num=1;//记录从零售商找到总生产者需要的次数
	for (int i = 0; i < N; i++)
		if (!b[i])	//b[i]=flase即为没有下家的零售商
		{
			int j = a[i];
			times = 1;
			while (j != 0)
			{
				j = a[j];
				times++;
			}
			if (times < min)
			{
				min = times;
				num = 1;
			}
			else if (times == min)
				num++;
		}
	printf("%.4lf %d", rawprice *pow(1 + incpercent / 100, min), num);
	return 0;
}
//该解法认为本题只能有一个上家，但是有多个下家，所以采用并查集。但是提交后发现大部分出错，所以只能换种解法。