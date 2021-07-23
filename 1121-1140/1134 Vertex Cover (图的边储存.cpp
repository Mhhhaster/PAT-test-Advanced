#include <iostream>
#include <vector>
using namespace std;
struct EdgeNode {
	int v1, v2;
};
vector<EdgeNode>Edge;
void Judge() {
	int p;
	bool H[10000] = { false };
	scanf("%d", &p);
	vector<int>test(p);
	for (int i = 0; i < p; i++) {
		scanf("%d", &test[i]);
		H[test[i]] = true;
	}
	for (int i = 0; i < Edge.size(); i++)
		if (!H[Edge[i].v1] && !H[Edge[i].v2]) {
			printf("No\n");
			return;
		}
	printf("Yes\n");
	return;
}
int main() {
	int N, M;
	scanf("%d%d", &N, &M);
	Edge.resize(M);
	for (int i = 0; i < M; i++)
		scanf("%d %d", &Edge[i].v1, &Edge[i].v2);
	int K;
	scanf("%d", &K);
	for (int i = 0; i < K; i++)
		Judge();
}