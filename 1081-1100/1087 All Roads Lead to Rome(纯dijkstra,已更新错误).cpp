#include<iostream>
#include<unordered_map>
#include<vector>
#define Uplimit 999999999
using namespace std;
/*必备数组dis和visit，常规数组path*/
vector<int>dis;//记录到该节点的总路程
vector<bool>visit;//记录该节点是否收录
vector<int>path;//记录该节点的前一步顶点
/*用以计算各点其他权重的数组*/
vector<int>ple;//记录该节点的pleasure
vector<int>plesum;//记录到该节点的总pleasure
vector<int>nodenum;//记录到该节点的总中转数
vector<int>pathnum;//记录到该节点的总路径条数
vector<vector<int>>G;
/*全局变量*/
unordered_map<string, int>M;
unordered_map<int, string>RM;//既能通过名字找下标，也能通过下标找名字
int citynum;
string start, tempstr, tempstr2;
int getmindis()
{
	int num = -1;
	int mindis = Uplimit;
	for (int i = 0; i < citynum; i++)//找到未收录距离最短结点
		if (visit[i] == false && dis[i] < mindis)
		{
			mindis = dis[i];
			num = i;
		}
	return num;
}
void Printpath(int D)//打印到D点的路径
{
	if (path[D] != -1)//不是起点
	{
		Printpath(path[D]);
		cout << "->" << RM[D];
	}
	else
		cout << RM[D];
}
int main()
{
	int roadnum, tempint;
	cin >> citynum >> roadnum >> start;
	/*初始化*/
	ple.resize(citynum);
	plesum.resize(citynum);
	G.resize(citynum, vector<int>(citynum, Uplimit));
	nodenum.resize(citynum);
	dis.resize(citynum, Uplimit);
	visit.resize(citynum, false);
	path.resize(citynum, -1);
	pathnum.resize(citynum, 1);
	M[start] = 0;
	RM[0] = start;
	ple[0] = 0;//自动为0
	/*初始化*/
	for (int i = 0; i < citynum - 1; i++)//已经给起始点赋值了
	{
		cin >> tempstr >> tempint;
		M[tempstr] = i + 1;
		RM[i + 1] = tempstr;
		ple[i + 1] = tempint;
	}//0到citynum-1分别保存了城市的pleasure信息
	/*选用dijkstra算法，注意需要保存每个点的pleasure总和，以及经过的城市数目
	如果收录到ROM即可退出循环
	Floyd算法需要初始化自身到自身的距离为0，dijkstra则无要求,如果初始化为最大值，在遍历邻接点的时候也不会找到自身*/
	for (int i = 0; i < roadnum; i++)
	{
		cin >> tempstr >> tempstr2 >> tempint;
		G[M[tempstr]][M[tempstr2]] = tempint;
		G[M[tempstr2]][M[tempstr]] = tempint;
	}
	/*dijkstra算法，初始化*/
	dis[0] = 0;
	int ROMnum = 1;
	while (1)//循环
	{
		tempint = getmindis();
		if (tempint == M["ROM"] || tempint == -1)
			break;
		visit[tempint] = true;
		for (int i = 0; i < citynum; i++)//对于每个tempint的邻接点
			if (G[tempint][i] < Uplimit && visit[i] == false)//邻接点且没有被收录的，收录了的就不用考虑更新了
			{
				if (dis[i] > dis[tempint] + G[tempint][i])//找到更短路径
				{
					dis[i] = dis[tempint] + G[tempint][i];
					path[i] = tempint;
					nodenum[i] = nodenum[tempint] + 1;
					plesum[i] = plesum[tempint] + ple[i];
					pathnum[i] = pathnum[tempint];
				}
				else if (dis[i] == dis[tempint] + G[tempint][i])//距离相等，比较plesum
				{
					if (plesum[i] < plesum[tempint] + ple[i])
					{
						path[i] = tempint;
						nodenum[i] = nodenum[tempint] + 1;
						plesum[i] = plesum[tempint] + ple[i];
					}
					else if (plesum[i] == plesum[tempint] + ple[i])//plesum也相等
					{
						if (plesum[i] / float(nodenum[i]) < (plesum[tempint] + ple[i]) / float(nodenum[tempint] + 1))//比较平均
						{
							path[i] = tempint;
							nodenum[i] = nodenum[tempint] + 1;
						}
					}
					pathnum[i] += pathnum[tempint];
				}
			}
	}
	printf("%d %d %d %d\n", pathnum[M["ROM"]], dis[M["ROM"]], plesum[M["ROM"]], int(plesum[M["ROM"]] / nodenum[M["ROM"]]));
	Printpath(M["ROM"]);
	return 0;
}
/*
dijkstra最核心的一定是距离，至少需要dis和visit两个数组
dis[起点]一定要为0，其他的有路则为G[起点][i]，否则为MAX;visit数组就不用说了
写完框架再填补。
本题又是经典的名字和序号对应，采用两个map来映射
错误点在于：ROMnum求错，ROMnum不应该为更新dis[ROM]的次数，而是前一步顶点的最短路径条数和，错误已更新
*/