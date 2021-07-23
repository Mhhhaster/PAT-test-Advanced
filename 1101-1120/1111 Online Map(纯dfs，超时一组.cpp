#include<iostream>
#include<vector>
using namespace std;
struct Node
{
	int adj, length, times;
};
vector<Node> Path[500];
const int Inf = 999999999;
int des;
int minlength = Inf, mintime = Inf;
vector<int>p, tp;
bool visit[500] = { false };
void dfs(int index, int lengthsum, int timesum)
{
	tp.push_back(index);
	visit[index] = true;
	if (index == des) {
		if (lengthsum < minlength) {
			minlength = lengthsum;
			mintime = timesum;
			p = tp;
		}
		else if (lengthsum == minlength && timesum < mintime) {
			mintime = timesum;
			p = tp;
		}
	}
	else for (int i = 0; i < Path[index].size(); i++)
		if (visit[Path[index][i].adj] == false && lengthsum <= minlength)
			dfs(Path[index][i].adj, Path[index][i].length + lengthsum, timesum + Path[index][i].times);
	visit[index] = false;
	tp.pop_back();
}
int MT = Inf, mintrans = Inf;
vector<int>q, tq;
void dfs2(int index, int timesum, int transum)
{
	tq.push_back(index);
	visit[index] = true;
	if (index == des) {
		if (timesum < MT) {
			MT = timesum;
			mintrans = transum;
			q = tq;
		}
		else if (timesum == MT && transum < mintrans) {
			mintrans = transum;
			q = tq;
		}
	}
	else for (int i = 0; i < Path[index].size(); i++)
		if (visit[Path[index][i].adj] == false && timesum <= MT)
			dfs2(Path[index][i].adj, Path[index][i].times + timesum, transum + 1);
	visit[index] = false;
	tq.pop_back();
}
void Print(vector<int>t)
{
	printf("%d", t[0]);
	for (int i = 1; i < t.size(); i++)
		printf(" -> %d", t[i]);
}
int main()
{
	int ori, Nv, Ne;
	scanf("%d%d", &Nv, &Ne);
	int v1, v2, status, len, times;
	for (int i = 0; i < Ne; i++) {
		scanf("%d%d%d%d%d", &v1, &v2, &status, &len, &times);
		Path[v1].push_back({ v2,len,times });
		if (!status) {
			Path[v2].push_back({ v1,len,times });
		}
	}
	scanf("%d%d", &ori, &des);
	dfs(ori, 0, 0);//得到路径数组p及最短长度minlength
	dfs2(ori, 0, 0);//得到路径数组q及最短时间MT
	if (p == q) {
		printf("Distance = %d; Time = %d: ", minlength, MT);
		Print(q);
	}
	else {
		printf("Distance = %d: ", minlength); Print(p); printf("\n");
		printf("Time = %d: ", MT); Print(q);
	}
}