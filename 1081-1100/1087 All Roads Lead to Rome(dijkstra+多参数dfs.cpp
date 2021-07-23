#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<string>
using namespace std;
vector<int>hap;
int G[201][201];
vector<bool>visit;
vector<int>dis;
const int Inf = 99999999;
vector<int>path[201];//指示路径
unordered_map<string, int>M;
unordered_map<int, string>RM;
string start;
float resavehappy = 0;
int pathsum = 0, reshappy = 0;
vector<int>respath, temppath;
void dfs(int index, int happysum, int passsum)
{
	temppath.push_back(index);
	if (index == 1) {//说明回溯到起点了
		pathsum++;
		if (happysum > reshappy || (happysum == reshappy && happysum * 1.0 / passsum > resavehappy)) {
			reshappy = happysum;
			resavehappy = happysum * 1.0 / passsum;
			respath = temppath;
		}
	}
	else
		for (int i = 0; i < path[index].size(); i++)
			dfs(path[index][i], happysum + hap[index], passsum + 1);
	temppath.pop_back();
}
int main()
{

	fill(G[0], G[0] + 201 * 201, Inf);
	int citynum, pathnum, happy, length;
	string temp, temp2;
	cin >> citynum >> pathnum >> start;
	M[start] = 1; RM[1] = start;
	visit.resize(citynum + 1, false);
	dis.resize(citynum + 1, Inf);
	hap.resize(citynum + 1);
	for (int i = 1; i < citynum; i++) {
		cin >> temp >> happy;
		M[temp] = i + 1;
		RM[i + 1] = temp;
		hap[M[temp]] = happy;
	}
	for (int i = 0; i < pathnum; i++) {
		cin >> temp >> temp2 >> length;
		G[M[temp]][M[temp2]] = G[M[temp2]][M[temp]] = length;
	}
	//dijkstra算法得到最短路径
	dis[M[start]] = 0;
	while (1) {
		int min = Inf, minindex = -1;
		for (int i = 1; i <= citynum; i++) {
			if (dis[i] < min && visit[i] == false) {
				minindex = i;
				min = dis[i];
			}
		}
		if (minindex == -1 || minindex == M["ROM"])
			break;
		visit[minindex] = true;
		for (int i = 1; i <= citynum; i++) {
			if (G[minindex][i] + dis[minindex] < dis[i]) {
				dis[i] = G[minindex][i] + dis[minindex];
				path[i].clear();
				path[i].push_back(minindex);//到i的路上经过minindex
			}
			else if (G[minindex][i] + dis[minindex] == dis[i]) {
				path[i].push_back(minindex);
			}
		}
	}
	/*dijktra算法结束*/
	dfs(M["ROM"], 0, 0);
	printf("%d %d %d %d\n", pathsum, dis[M["ROM"]], reshappy, int(resavehappy));
	printf("%s", RM[respath[respath.size() - 1]].c_str());
	for (int i = respath.size() - 2; i >= 0; i--)
		printf("->%s", RM[respath[i]].c_str());
	return 0;
}
/*
很烦，把pathsum和dis[ROM]的输出顺序弄反了卡了很久
本题注意的点：
采用dijkstra得到最短的路径，再dfs回溯
dfs可以只传index，也可以带上更多参数
happy值可以通过index索引，其实第一种相对更容易理解
dijkstra有个小技巧是只初始化dis[start]=0，让邻接点的初始化在第一次循环自己做
很常规的一道dijkstra算法题
*/