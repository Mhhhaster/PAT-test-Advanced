#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
int membernum;
double rawprice, rate;
vector<int>Sub[100001];
double pricesum = 0;
void dfs(int root, int level)
{
	if (Sub[root][0] > 100000)//说明是零售商
		pricesum += rawprice*pow(rate / 100 + 1, level) * (double(Sub[root][0]) - 100001);
	else
		for (int i = 0; i < Sub[root].size(); i++)
			dfs(Sub[root][i], level + 1);
}
int main()
{
	scanf("%d%lf%lf", &membernum, &rawprice, &rate);
	int subnum,subid,productnum;
	for (int i = 0; i < membernum; i++)
	{
		scanf("%d", &subnum);
		if (subnum == 0)
		{
			scanf("%d", &productnum);
			Sub[i].push_back(productnum + 100001);//存储一个不可能是标号的数字
		}
		else
			for (int j = 0; j < subnum; j++)
			{
				scanf("%d", &subid);
				Sub[i].push_back(subid);
			}
	}
	dfs(0, 0);
	printf("%.1lf", pricesum);
	return 0;
}
/*经典树形dfs
此题创新点在于叶子节点的存储信息与其他节点不同
故采用映射方法，简化了程序和计算表示
不然需要采用结构体：
一个变量存储数据
一个数组存储下属结点*/