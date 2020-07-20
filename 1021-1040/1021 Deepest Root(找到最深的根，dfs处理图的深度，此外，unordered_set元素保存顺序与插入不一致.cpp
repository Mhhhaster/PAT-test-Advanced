#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int>>G;
bool visit[10010] = { false };
void dfs(int index)
{
	visit[index] = true;
	for (int i = 0; i < G[index].size(); i++)
		if (visit[G[index][i]] == false)
			dfs(G[index][i]);
}
int maxheight = -1, nowheight = -1;
vector<int>result;
void dfs2(int index, int height)
{
	visit[index] = true;
	if (height > nowheight)
		nowheight = height;
	for (int i = 0; i < G[index].size(); i++)
		if (visit[G[index][i]] == false)
			dfs2(G[index][i], height + 1);
	visit[index] = false;
}
int main()
{
	int nodenum, v1, v2;
	scanf("%d", &nodenum);
	G.resize(nodenum + 1);
	for (int i = 0; i < nodenum - 1; i++) {
		scanf("%d%d", &v1, &v2);
		G[v1].push_back(v2);
		G[v2].push_back(v1);
	}
	int count = 0;
	for (int i = 1; i <= nodenum; i++) {
		if (visit[i] == false) {
			dfs(i);
			count++;
		}
	}
	if (count > 1) {
		printf("Error: %d components", count);
		return 0;
	}
	fill(visit, visit + 10010, false);
	for (int i = 1; i <= nodenum; i++) {
		nowheight = -1;
		dfs2(i, 1);
		if (nowheight > maxheight) {
			result.clear();
			result.push_back(i);
			maxheight = nowheight;
		}
		else if (nowheight == maxheight)
			result.push_back(i);
	}
	for (auto it : result)
		printf("%d\n", it);
	return 0;
}
