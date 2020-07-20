#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<vector<int>>G;
int N, L, K, temp;
queue<int>Q, tempQ;
void Bfs(int index)
{//level==K时终止
	bool visit[1005] = { false };
	visit[index] = true;
	Q.push(index);
	int countnum = 0;
	for (int i = 0; i < L; i++) {
		while (!Q.empty()) {
			int next = Q.front();
			Q.pop();
			for (int i = 0; i < G[next].size(); i++)
				if (visit[G[next][i]] == false) {
					tempQ.push(G[next][i]);
					visit[G[next][i]] = true;
					countnum++;
				}
		}
		Q.swap(tempQ);
	}
	printf("%d\n", countnum);
}
void Judge()
{
	int test;
	scanf("%d", &test);
	Bfs(test);
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
/*采用两个队列一层一层地遍历，未使用结构体，总体上略快于liuchuo
bfs的精髓就在于不重复加入元素，所以在判别元素未加入之后要马上置visit为true，再加入*/