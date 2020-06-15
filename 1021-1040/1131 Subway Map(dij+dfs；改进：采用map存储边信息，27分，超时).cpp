#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;
const int Uplimit = 99999999;
vector<int>length[10000];//存储邻接表
unordered_map<int, int>Line;//指示站点所属线路
vector<int>Path[10000];//存储路径
void dfs(int dest);
void Read(int line);
void Solve();
int main()
{
	int N; scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		Read(i);
	int K; scanf("%d", &K);
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
	for (int i = 1; i < M; i++)
	{
		scanf("%d", &station2);
		Line[10000 * station1 + station2] = Line[10000 * station2 + station1] = linename;
		length[station1].push_back(station2);
		length[station2].push_back(station1);
		station1 = station2;
	}
}//length中保存邻接点，Line中保存所属线路
vector<int>temppath;
vector<int>respath;
int mintransnum;
void dfs(int dest)
{
	temppath.push_back(dest);//push顺序为先终点后起点
	if (Path[dest].size() == 0)//找到终点了
	{
		int temptransnum = -1;//记录地铁换乘的次数
		int startline = 0;//记录当前的地铁线路
		for (int i = temppath.size() - 2; i >= 0; i--)//temppath[i]从第二站到终点
		{
			if (Line[temppath[i] * 10000 + temppath[i + 1]] != startline)
			{
				temptransnum++;
				startline = Line[temppath[i] * 10000 + temppath[i + 1]];
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
	int start = 0;//起点站
	int startline = 0;
	for (int i = respath.size() - 2; i >= 0; i--)//respath存储
	{
		if (Line[respath[i] * 10000 + respath[i + 1]] != startline)
		{
			if(i!=respath.size()-2)//第一遍循环只要更新startline和start即可
				printf("Take Line#%d from %04d to %04d.\n", startline, start, respath[i+1]);
			startline = Line[respath[i] * 10000 + respath[i + 1]];
			start = respath[i + 1];
		}
	}
	printf("Take Line#%d from %04d to %04d.\n", startline, start, respath[0]);
}
int dis[10000];
bool visit[10000];
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
		for (int i = 0; i < 10000; i++)//找到dis最小的线路
			if (visit[i] == false && dis[i] < mindis)
			{
				minindex = i;
				mindis = dis[i];
			}
		if (minindex == -1 || minindex == dest)
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
				else if (dis[adj] == dis[minindex] + 1)
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
	return;
}
/*在原基础上，只存储边的线路归属，并且采用图来存储，然后还是超时
具体改进方法：取消dijkstra算法，每次Findmin中都要查找10000个数组，然后对最小距离结点的所有邻接点更新，循环10000次(N平方数量级)*/
