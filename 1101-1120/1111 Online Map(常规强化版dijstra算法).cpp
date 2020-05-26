#include<iostream>
#include<vector>
#include<stack>
#define Empty -1
#define Uplimit 65535
using namespace std;
struct Node {
	int length;
	int time;
};
vector<int>dis, times, disway, timesway;//dis和times初始化为无穷，disway和timesway初始化为-1
vector<bool>collect1, collect2;//收录初始化为false
vector<int>result1, result2;
int Dijkstralength(int start,int end,vector<vector<Node>>G, int N);
int Dijkstratimes(int start, int end, vector<vector<Node>>G, int N);
int main()
{
	int N, M;
	scanf("%d%d", &N,&M);
	vector<vector<Node>>G(N, vector<Node>(N, { Uplimit,Uplimit }));//N*N的矩阵，全部初始化为无穷
	dis.resize(N,Uplimit); times.resize(N,Uplimit); disway.resize(N, -1); timesway.resize(N, -1);
	collect1.resize(N, false); collect2.resize(N, false);
	int po1, po2,one,length,time;
	for (int i = 0; i < M; i++)
	{
		scanf("%d%d%d%d%d", &po1, &po2, &one, &length, &time);
		if (one == 1)//单向
		{
			G[po1][po2].length = length;
			G[po1][po2].time = time;
		}
		else//双向
		{
			G[po1][po2].length = length;
			G[po2][po1].length = length;
			G[po1][po2].time = time;
			G[po2][po1].time = time;
		}
	}//自身到自身为无穷
	int start, end;
	scanf("%d%d", &start, &end);
	int shortcost=Dijkstralength(start, end, G, N);//根据出发点和目的地输出最短路径
	int fastcost=Dijkstratimes(start, end, G, N);//输出最快路径
	bool same = true;
	if (result1.size() != result2.size())
		same = false;
	if (same == true)
		for (int i = 0; i < result1.size(); i++)
			if (result1[i] != result2[i])
				same = false;
	if (!same)
	{
		printf("Distance = %d: %d", shortcost,result1[0]);
		for (int i = 1; i < result1.size(); i++)
			printf(" -> %d", result1[i]);
		printf("\nTime = %d: %d", fastcost, result2[0]);
		for (int i = 1; i < result2.size(); i++)
			printf(" -> %d", result2[i]);
	}
	else
	{
		printf("Distance = %d; Time = %d: %d", shortcost, fastcost, result2[0]);
		for (int i = 1; i < result2.size(); i++)
			printf(" -> %d", result2[i]);
	}
	return 0;
}
//Distance = 3; Time = 4: 3 -> 2 -> 5
int FindMin1(int N)
{
	int min = Uplimit, minposition;
	for(int i=0;i<N;i++)
		if(!collect1[i])
			if (dis[i] < min)
			{
				minposition = i;
				min = dis[i];
			}
	if (min == Uplimit)
		return Empty;
	else
		return minposition;
}
int Dijkstralength(int start, int end, vector<vector<Node>>G, int N)//根据出发点和目的地输出最短路径
{
	//收录初始节点，把邻接点初始化
	//找到距离最小的结点，收录，并把邻接点初始化
	vector<int>timeprice(N,Uplimit);
	collect1[start] = true;
	for (int i = 0; i < N; i++)
		if (G[start][i].length < Uplimit)
		{
			dis[i] = G[start][i].length;//初始化dis数组
			disway[i] = start;
			timeprice[i] = G[start][i].time;
		}
	dis[start] = 0;
	timeprice[start] = 0;
	while (1)
	{
		int temp = FindMin1(N);//从dis数组中找到未被收录的最小值
		if (temp == Empty)
			break;
		collect1[temp] = true;
		for (int i = 0; i < N; i++)
		{
			if (dis[i] > dis[temp] + G[temp][i].length)
			{
				dis[i] = dis[temp] + G[temp][i].length;
				disway[i] = temp;
				timeprice[i] = timeprice[temp] + G[temp][i].time;
			}
			else if (dis[i] == dis[temp] + G[temp][i].length && timeprice[i] > timeprice[temp] + G[temp][i].time)
			{
				dis[i] = dis[temp] + G[temp][i].length;
				disway[i] = temp;
				timeprice[i] = timeprice[temp] + G[temp][i].time;
			}
		}
	}
	int Distance=dis[end];
	stack<int>S;
	while (end != start)
	{
		S.push(end);
		end = disway[end];
	}
	result1.push_back(start);
	int temp;
	while (!S.empty())
	{
		temp = S.top();
		S.pop();
		result1.push_back(temp);
	}
	return Distance;
}//当有多条最短路时，输出最快的那条,改进方法，记录每条路的times权值
int FindMin2(int N)
{
	int min = Uplimit, minposition;
	for (int i = 0; i < N; i++)
		if (!collect2[i])
			if (times[i] < min)
			{
				minposition = i;
				min = times[i];
			}
	if (min == Uplimit)
		return Empty;
	else
		return minposition;
}
int Dijkstratimes(int start, int end, vector<vector<Node>>G, int N)
{
	collect2[start] = true;
	vector<int>Nodeprice(N,Uplimit);
	for (int i = 0; i < N; i++)
		if (G[start][i].time < Uplimit)
		{
			times[i] = G[start][i].time;//初始化dis数组
			timesway[i] = start;
			Nodeprice[i] = 1;
		}
	times[start] = 0;
	Nodeprice[start] = 0;
	while (1)
	{
		int temp = FindMin2(N);//从dis数组中找到未被收录的最小值
		if (temp == Empty)
			break;
		collect2[temp] = true;
		for (int i = 0; i < N; i++)
		{
			if (times[i] > times[temp] + G[temp][i].time)
			{
				times[i] = times[temp] + G[temp][i].time;
				timesway[i] = temp;
				Nodeprice[i] = Nodeprice[temp] + 1;
			}
			else if (times[i] == times[temp] + G[temp][i].time && Nodeprice[i] > Nodeprice[temp]+1)//路程相等但可以更新最小节点数
			{
				times[i] = times[temp] + G[temp][i].time;
				timesway[i] = temp;
				Nodeprice[i] = Nodeprice[temp] + 1;
			}
		}
	}
	int Time=times[end];
	result2.push_back(start);
	stack<int>S;
	while (end != start)
	{
		S.push(end);
		end = timesway[end];
	}
	int temp;
	while (!S.empty())
	{
		temp = S.top();
		S.pop();
		result2.push_back(temp);
	}
	return Time;
}//当有多条最快路时，输出最少结点的那条,改进方法，记录所需走结点值
//如果是同一条路，那么只需要输出一次就行;