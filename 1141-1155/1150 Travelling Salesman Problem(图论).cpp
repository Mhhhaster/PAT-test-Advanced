#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
int G[205][205];
int N, M;
const int uplimit = 99999999;
int shortestdis = uplimit, index;
void Judge(int t)
{
	bool visit[205] = { false };
	int totaldis = 0;
	int n;
	scanf("%d", &n);
	vector<int>path(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &path[i]);
	int start = path[0];
	int end = path[n - 1];
	for (int i = 0; i < n - 1; i++) {
		totaldis += G[path[i]][path[i + 1]];
		if (totaldis > uplimit) {
			printf("Path %d: NA (Not a TS cycle)\n", t);
			return ;
		}
	}
	for (int i = 0; i < n; i++)
		visit[path[i]] = true;
	for (int i = 1; i <= N; i++) {
		if (visit[i] == false) {
			printf("Path %d: %d (Not a TS cycle)\n", t, totaldis);
			return ;
		}
	}
	if (start != end) {
		printf("Path %d: %d (Not a TS cycle)\n", t, totaldis);
		return;
	}
	if (totaldis < shortestdis) {
		shortestdis = totaldis;
		index = t;
	}
	if (n != N + 1) {
		printf("Path %d: %d (TS cycle)\n", t, totaldis);
		return ;
	}
	printf("Path %d: %d (TS simple cycle)\n", t, totaldis);
}
int main()
{
	scanf("%d%d", &N, &M);
	fill(G[0], G[0] + 205 * 205, uplimit);
	int V1, V2, Dis;
	for (int i = 0; i < M; i++) {
		scanf("%d%d%d", &V1, &V2, &Dis);
		G[V1][V2] = G[V2][V1] = Dis;
	}
	int K;
	scanf("%d", &K);
	for (int t = 1; t <= K; t++)
		Judge(t);
	printf("Shortest Dist(%d) = %d", index, shortestdis);
	return 0;
}