#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool visit[1000];
int N, M, K;
vector<vector<bool>>link;
vector<vector<bool>>temp;
void dfs(int station)
{
	visit[station] = true;
	for (int i = 1; i <= N; i++) {
		if (temp[station][i] == true && visit[i] == false)
			dfs(i);
	}
}
void Solve(int concern)//将该城市的出入口全部切断，然后统计连通集个数n，需要修的路为n-1
{
	temp = link;
	for (int i = 1; i <= N; i++) {
		temp[concern][i] = false;
		temp[i][concern] = false;
	}
	int count = 0;
	for (int i = 1; i <= N; i++) {
		if (visit[i] == false) {
			count++;
			dfs(i);
		}
	}
	printf("%d\n", count - 2);
}
int main()
{
	scanf("%d%d%d", &N, &M, &K);
	int sta1, sta2;
	link.resize(N + 1, vector<bool>(N + 1, false));
	temp.resize(N + 1, vector<bool>(N + 1));
	for (int i = 0; i < M; i++) {
		scanf("%d%d", &sta1, &sta2);
		link[sta1][sta2] = true;
		link[sta2][sta1] = true;
	}
	int concern;
	for (int i = 0; i < K; i++) {
		scanf("%d", &concern);
		fill(visit, visit + 1000, false);
		Solve(concern);
	}
	return 0;
}
/*
采用遍历连通集的方式
此题收获：如果需要复制一份数组，那么采用vector是最好的选择

liuchuo：根本不需要改变路程数组，对于每次假设摧毁的城市，只需要把它的visit置为true即可
深层次而言，visit值为true也能说明这条路走不通*/