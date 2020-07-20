#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<vector<int>>G;
bool visit[1005] = { false };
bool influ[1005] = { false };
int N, L, K, temp;
queue<int>Q, tempQ;
void Bfs(int index)
{//level==K时终止
	Q.push(index);
	for (int i = 0; i < L; i++) {
		while (!Q.empty()) {
			int next = Q.front();
			Q.pop();
			for (int i = 0; i < G[next].size(); i++)
				if (visit[G[next][i]] == false) {
					tempQ.push(G[next][i]);
					visit[G[next][i]] = true;
				}
		}
		Q = tempQ;
	}
	int count = 0;
	for (int i = 1; i <= N; i++)
		if (visit[i] == true)
			count++;
	printf("%d", count - 1);
}
void Judge()
{
	int test, nodecount = 0;
	scanf("%d", &test);
	fill(influ, influ + 1005, false);
	fill(visit, visit + 1005, false);
	Bfs(test);
	for (int i = 1; i <= N; i++)
		if (influ[i] == true)
			nodecount++;
	printf("%d\n", nodecount-1);
}
int main()
{
	scanf("%d%d", &N, &L);
	G.resize(N + 1);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &K);
		for (int j = 0; j < K; j++) {
			scanf("%d", &temp);
			G[temp].push_back(i);
		}
	}
	int querynum;
	scanf("%d", &querynum);
	for (int i = 0; i < querynum; i++)
		Judge();
	return 0;
}