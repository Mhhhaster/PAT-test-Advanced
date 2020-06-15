#include<iostream>
#include<vector>
#include<stack>
#define Uplimit 99999999
using namespace std;
int Cmax, N, problemindex, roadnum;
vector<int>bike;
vector<vector<int>>G;
vector<int>dis;
vector<bool>visit;
vector<vector<int>>path;
int sendnum = Uplimit, backnum = Uplimit;//两者都是越小越好，所以初始化为上限
vector<int>temppath;
vector<int>respath;
void dfs(int index)//统计所有路径上的总stanum和bikenum
{
	temppath.push_back(index);
	if (path[index].size())//不是最终路径
	{
		for (int i = 0; i < path[index].size(); i++)
			dfs(path[index][i]);
	}
	else
	{
		int take = 0, sum = 0, back = 0;
		for (int i = temppath.size() - 2; i >= 0; i--)//从第一个站点遍历到终点
		{//take保存全过程中最小的权重和，sum保存总和
			sum += bike[temppath[i]];
			if (sum < take)
				take = sum;
		}
		take = 0 - take;
		back = take + sum;
		if (take < sendnum)
		{
			sendnum = take;
			respath = temppath;
			backnum = back;
		}
		else if (take == sendnum && back < backnum)
		{
			respath = temppath;
			backnum = back;
		}
	}
	temppath.pop_back();
}
int main()
{
	scanf("%d%d%d%d", &Cmax, &N, &problemindex, &roadnum);
	bike.resize(N + 1);
	G.resize(N + 1, vector<int>(N + 1, Uplimit));
	path.resize(N + 1);
	dis.resize(N + 1, Uplimit);
	visit.resize(N + 1, false);
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &bike[i]);
		bike[i] -= Cmax / 2;
	}
	for (int i = 0; i < roadnum; i++)
	{
		int sta1, sta2, time;
		scanf("%d%d%d", &sta1, &sta2, &time);
		G[sta1][sta2] = time;
		G[sta2][sta1] = time;
	}
	dis[0] = 0;//这里不能省略，否则会出现初始点被更新
	while (1)
	{
		int minindex = -1, mindis = Uplimit;
		for (int i = 0; i <= N; i++)
			if (visit[i] == false && dis[i] < mindis)
			{
				minindex = i;
				mindis = dis[i];
			}
		if (minindex == -1 || minindex == problemindex)
			break;
		visit[minindex] = true;
		for (int i = 0; i <= N; i++)
			if (G[minindex][i] < Uplimit)//更新所有邻接点
			{//liuchuo这里多做了一层要求，必须是没有访问过的邻接点，实际上访问过的肯定收录了
				if (dis[i] > G[minindex][i] + dis[minindex])
				{
					path[i].clear();
					dis[i] = G[minindex][i] + dis[minindex];
					path[i].push_back(minindex);
				}
				else if (dis[i] == G[minindex][i] + dis[minindex])
					path[i].push_back(minindex);
			}
	}//得到所有通往problemindex的最短路径,至此，化为树形结构图，采用经典dfs
	dfs(problemindex);
	printf("%d 0", sendnum);
	for (int i = respath.size() - 2; i >= 0; i--)
		printf("->%d", respath[i]);
	printf(" %d", backnum);
	return 0;
}
