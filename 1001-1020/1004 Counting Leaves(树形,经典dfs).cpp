#include<vector>
#include<iostream>
using namespace std;
vector<int>Par[100];
vector<int>Output(100);
int maxlevel = 0;
void dfs(int id, int level)
{
	if (Par[id].size() == 0)
		Output[level]++;
	if (level > maxlevel)
		maxlevel = level;
	for (int i = 0; i < Par[id].size(); i++)
		dfs(Par[id][i], level + 1);
}
int main()
{
	int N, M;
	scanf("%d", &N);
	if (!N)
		return 0;
	scanf("%d", &M);
	int ID, childnum, childname;
	for (int i = 0; i < M; i++)
	{
		scanf("%d%d", &ID, &childnum);
		for (int i = 0; i < childnum; i++)
		{
			scanf("%d", &childname);
			Par[ID].push_back(childname);
		}
	}
	dfs(1, 0);
	printf("%d", Output[0]);
	for (int i = 1; i <= maxlevel; i++)
		printf(" %d", Output[i]);
	return 0;
}
/*经典树形结构的dfs
和liuchuo的唯一不同就是她只在叶节点更新最大层数*/