#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int Uplimit = 99999999;
vector<int>length[10000];//邻接表
vector<int>Line[10000];//指示站点所属线路
vector<int>Path[10000];
void dfs(int dest);
void Read(int line);
void Solve();
int main()
{
	int N;scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		Read(i);
	int K;scanf("%d", &K);
	for (int i = 0; i < K; i++)
		Solve();
	return 0;
}
void Read(int linename)
{
	int M;
	scanf("%d", &M);
	int station1, station2;
	scanf("%d", &station1);
	Line[station1].push_back(linename);
	for (int i = 1; i < M; i++)
	{
		scanf("%d", &station2);
		Line[station2].push_back(linename);
		length[station1].push_back(station2);
		length[station2].push_back(station1);
		station1 = station2;
	}
}//length中保存邻接点，Line中保存所属线路
vector<int>temppath;
vector<int>respath;
int mintransnum;
int Judgeline(int i,int j)//判断当前站点位于哪一条线上,比较前一站点和当前站点的共同线路
{
	bool line[101] = { false };
	for (int k = 0; k < Line[i].size(); k++)
		line[Line[i][k]] = true;
	for (int k = 0; k < Line[j].size(); k++)
		if (line[Line[j][k]] == true)
			return Line[j][k];
}
void dfs(int dest)
{
	temppath.push_back(dest);//push顺序为先终点后起点
	if (Path[dest].size() == 0)//找到终点了
	{
		int temptransnum = 0;//记录地铁换乘的次数
		int nowline = Judgeline(temppath[temppath.size()-1],temppath[temppath.size() - 2]);//获得起点的线路
		for (int i = temppath.size() - 2; i >= 0; i--)
		{
			int index = temppath[i];
			for (int j = 0; j < Line[index].size(); j++)
			{
				if (Line[index][j] == nowline)//说明没有换乘
				{
					break;
				}
				if(j==Line[index].size()-1)//当前站点和记录的线路不匹配，换乘了
				{
					nowline=Judgeline(temppath[i+1],index);
					temptransnum++;
				}
			}
		}
		if (temptransnum < mintransnum)
		{
			mintransnum = temptransnum;
			respath = temppath;//respath保存换乘站点数量最少的线路
		}
	}
	else
	{
		for (int i = 0; i < Path[dest].size(); i++)
			dfs(Path[dest][i]);
	}
	temppath.pop_back();
}
void Print()//根据格式要求输出respath路径
{
	printf("%d\n", respath.size() - 1);
	int start = respath[respath.size() - 1];//起点站
	int startline = Judgeline(respath[respath.size() - 1], respath[respath.size() - 2]);//获得起点的站名称
	for (int i = respath.size() - 2; i >= 0; i--)//从第二站一直到终点站
	{
		int tempstation = respath[i];
		for (int j = 0; j < Line[tempstation].size(); j++)
		{
			if (Line[tempstation][j] == startline)
				break;
			if (j == Line[tempstation].size() - 1)
			{
				int transtation = respath[i + 1];//找到上一站
				printf("Take Line#%d from %04d to %04d.\n",startline,start,transtation);
				start = transtation;
				startline = Judgeline(transtation, tempstation);
			}
		}
	}
	printf("Take Line#%d from %04d to %04d.\n", startline, start, respath[0]);
}
int dis[10000];
bool visit[10000] ;
void Solve()
{
	/*经典dijkstra*/
	int start, dest;
	scanf("%d%d", &start, &dest);
	fill(dis, dis + 10000, Uplimit);
	fill(visit, visit + 10000, false);
	dis[start] = 0;
	for (int i = 0; i < 10000; i++)
		Path[i].clear();
	while (1)
	{
		int minindex = -1, mindis = Uplimit;
		for (int i = 0; i <10000; i++)//找到dis最小的线路
			if (visit[i] == false && dis[i] < mindis)
			{
				minindex = i;
				mindis = dis[i];
			}
		if (minindex == -1||minindex==dest)
			break;
		visit[minindex] = true;
		for (int i = 0; i < length[minindex].size(); i++)//遍历它所有邻接点
		{
			int adj = length[minindex][i];//minindex的邻接点
			if (visit[adj] == false)
			{
				if (dis[adj] > dis[minindex] + 1)
				{
					dis[adj] = dis[minindex] + 1;
					Path[adj].clear();
					Path[adj].push_back(minindex);
				}
				else if (dis[adj] == dis[minindex] +1)
				{
					Path[adj].push_back(minindex);
				}
			}
		}
	}
	/*最短路径保存完毕，接下来dfs遍历每一条路径,得到换乘唯一符合要求的路径*/
	temppath.clear(); respath.clear(); mintransnum = Uplimit;//初始化
	dfs(dest);
	Print();//按格式要求打印路径
	return ;
}
/*优先考虑最短距离，再考虑换乘次数
Each station interval belongs to a unique subway line
说明不存在一条路同属于两条地铁*/
