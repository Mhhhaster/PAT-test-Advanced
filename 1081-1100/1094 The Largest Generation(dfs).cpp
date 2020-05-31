#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>>T;
vector<int>levelnum(100,0);
void dfs(int root, int level)
{
	levelnum[level]++;
	for (int i = 0; i < T[root].size(); i++)
		dfs(T[root][i], level + 1);
}
int main()
{
	int N, M;
	scanf("%d%d", &N, &M);
	T.resize(N + 1);
	for (int i = 0; i < M; i++)
	{
		int parent, childnum,temp;
		cin >> parent >> childnum;
		for (int j = 0; j < childnum; j++)
		{
			cin >> temp;
			T[parent].push_back(temp);
		}
	}
	dfs(1, 1);
	int max = 0, depth;
	for (int i = 1; i < 100; i++)
		if (levelnum[i] > max)
		{
			max = levelnum[i];
			depth = i;
		}
	printf("%d %d", max, depth);
	return 0;
}
/*
conclude：经典dfs和liuchuo写的一摸一样，有那味了。
*/