#include<iostream>
#include<algorithm>
using namespace std;
const int Uplimit = 99999999;
int length[500][500];
int cost[500][500];//对于很大的数组要定义在主函数外面
void Print(int path[],int des);
int main()
{
	fill(length[0], length[0] + 500 * 500, Uplimit);
	fill(cost[0], cost[0] + 500 * 500, Uplimit);
	int N, M, S, D;
	scanf("%d%d%d%d", &N, &M, &S, &D);
	for (int i = 0; i < M; i++)
	{
		int road1, road2, dis, cos;
		scanf("%d%d%d%d", &road1, &road2, &dis, &cos);
		length[road1][road2] =length[road2][road1]= dis;
		cost[road1][road2] =cost[road2][road1]= cos;
	}
	int dis[500];
	int price[500];
	int path[500];
	fill(path, path + 500, -1);
	fill(dis, dis + 500, Uplimit);
	fill(price, price + 500, Uplimit);
	bool visit[500] = { false };
	dis[S] = 0; price[S] = 0;
	while (1)
	{
		int minindex = -1, mindis = Uplimit;
		for(int i=0;i<N;i++)
			if (visit[i] == false && dis[i] < mindis)
			{
				minindex = i;
				mindis = dis[i];
			}
		if (minindex == -1)
			break;
		visit[minindex] = true;
		for(int i=0;i<N;i++)
			if (visit[i] == false && length[minindex][i] < Uplimit)
			{
				if (dis[i] > dis[minindex] + length[minindex][i])
				{
					dis[i] = dis[minindex] + length[minindex][i];
					path[i] = minindex;
					price[i] = price[minindex] + cost[minindex][i];
				}
				else if (dis[i] == dis[minindex] + length[minindex][i] && price[i] > price[minindex] + cost[minindex][i])
				{
					price[i] = price[minindex] + cost[minindex][i];
					path[i] = minindex;
				}
			}
	}
	Print(path,D);
	printf(" %d %d", dis[D], price[D]);
}
void Print(int path[],int des)
{
	if (path[des] != -1)
	{
		Print(path,path[des]);
		printf(" %d", des);
	}
	else
		printf("%d", des);
}
/*经典dijkstra，求最短路径，可以用price来更新*/