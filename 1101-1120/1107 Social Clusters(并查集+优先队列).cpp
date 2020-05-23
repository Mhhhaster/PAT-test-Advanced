#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int FindRoot(int i);
void Union(int i, int j);
vector<int>Root;
int main()
{
	int N;
	scanf("%d", &N);
	vector<vector<bool>>G(N + 1, vector<bool>(1001,false));//G[i][j]=true说明第i个人有第j个爱好
	int hobbynum, hobby;
	char temp;
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &hobbynum);
		scanf(" %c", &temp);
		while (hobbynum--)
		{
			scanf("%d", &hobby);
			G[i][hobby] = true;
		}
	}//爱好信息存储完毕，接下来使用并查集，如果一个爱好有多人喜欢，那么union两人
	Root.resize(N + 1, -1);//初始化
	for (int j = 1; j <= 1000; j++)
	{//扫描每一个爱好
		int Root1,times=0;
		for (int i = 1; i <= N; i++)//扫描每一个人
		{
			if (G[i][j] && !times)
			{
				Root1 = i;
				times++;
			}
			else if (G[i][j] && times)
				Union(Root1, i);
		}
	}
	int clusternum = 0;
	priority_queue<int,vector<int>,greater<int>>S;
	for (int i = 1; i <= N; i++)
		if (Root[i] < 0)
		{
			clusternum++;
			S.push(Root[i]);
		}
	printf("%d\n", clusternum);
	bool flag = true;
	int value;
	while(!S.empty())
	{
		value = -1*S.top();
		S.pop();
		if (flag)
		{
			cout << value; flag = false;
		}
		else
			cout << " " << value;
	}
	return 0;
}
int FindRoot(int i)
{
	if (Root[i] < 0)
		return i;
	else
		return FindRoot(Root[i]);//直到找到负数为止
}
void Union(int i, int j)
{
	int Root1 = FindRoot(i);
	int Root2 = FindRoot(j);
	if (Root1 != Root2)
	{
		if (Root[Root1] < Root[Root2])//Root1的结点更多
		{
			Root[Root1] += Root[Root2];
			Root[Root2] = Root1;//小树并入大树
		}
		else
		{
			Root[Root2] += Root[Root1];
			Root[Root1] = Root2;
		}
	}
}
/*本题亮点：
使用图表示数据，将关系再转换
并查集的简单使用
本来想使用set集合存储由大到小的数据
但由于set中不允许重复元素所以有个测试点不能通过，转而使用优先队列*/