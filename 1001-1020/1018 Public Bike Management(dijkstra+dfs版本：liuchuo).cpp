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
int sendnum=Uplimit, backnum=Uplimit;//两者都是越小越好，所以初始化为上限
vector<int>temppath;
vector<int>respath;
void dfs(int index)//统计所有路径上的总stanum和bikenum
{
	temppath.push_back(index);
	if (index)//不是最终路径
	{
		for (int i = 0; i < path[index].size(); i++)
			dfs(path[index][i]);
	}
	else//根据temppath中保存的路径统计,相当于在线处理
	{
		int take = 0, back = 0;
		for (int i = temppath.size() - 2; i >= 0; i--)//从第一个站点遍历到终点
		{
			int temp = temppath[i];
			if (bike[temp] < Cmax / 2)//说明当前站点需要补车
			{
				if (bike[temp] + back >= Cmax / 2)//back够减
				{
					back -= Cmax / 2 - bike[temp];
				}
				else//说明可以更新back和take了
				{
					take += Cmax / 2 - bike[temp] - back;
					back = 0;
				}
			}
			else//说明当前站点多了车
			{/*注意，车多了的时候take不能进行更新！*/
				back += bike[temp] - Cmax / 2;
			}
		}
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
	bike.resize(N+1);
	G.resize(N+1, vector<int>(N+1, Uplimit));
	path.resize(N + 1);
	dis.resize(N + 1, Uplimit);
	visit.resize(N + 1, false);
	bike[0] = 0;
	for (int i = 1; i <= N; i++)
		scanf("%d", &bike[i]);
	for(int i=0;i<roadnum;i++)
	{
		int sta1, sta2, time;
		scanf("%d%d%d",&sta1,&sta2,&time);
		G[sta1][sta2] = time;
		G[sta2][sta1] = time;
	}
	dis[0] = 0;//这里不能省略，否则会出现初始点被更新
	/*liuchuo省略处*/
	for (int i = 1; i <= N; i++)
	{
		dis[i] = G[0][i];
		path[i].push_back(0);
	}
	visit[0] = true;
	/*liuchuo省略处，原因：相当于读出的第一个点就是原点，从原点开始更新*/
	while (1)
	{
		int minindex=-1,mindis=Uplimit;
		for(int i=0;i<=N;i++)
			if (visit[i] == false && dis[i] < mindis)
			{
				minindex = i;
				mindis = dis[i];
			}
		if (minindex == -1 || minindex == problemindex)
			break;
		visit[minindex] = true;
		for (int i = 0; i <= N;i++)
			if (G[minindex][i] < Uplimit)//更新所有邻接点
			{//liuchuo这里多做了一层要求，必须是没有访问过的邻接点，实际上访问过的肯定收录了
				if (dis[i] > G[minindex][i]+dis[minindex])
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
/*本题的dijkstra获得最短路径以及dfs遍历每一条路径的很常规(共性)
重难点在于模拟过程(特性):
最开始错在用站点数和单车总数来概括所需要的单车数量，忽视了每个过程的模拟
然后没考虑到后续的多车站点不会更新take，take只会累加,但是back几乎是全过程可加的，除非back不够补充而清零
*/