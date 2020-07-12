#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
bool G[205][205] = { false };
int Nv, Ne;
void Judge()
{
	int k;
	scanf("%d", &k);
	vector<int>input(k);
	for (int i = 0; i < k; i++)
		scanf("%d", &input[i]);
	for (int i = 0; i < k - 1; i++)
		for (int j = i + 1; j < k; j++)
			if (G[input[i]][input[j]] == false) {
				printf("Not a Clique\n");
				return;
			}
	unordered_set<int>adj;
	for (int i = 1; i <= Nv; i++)
		adj.insert(i);
	for (int i = 0; i < k; i++) {
		auto it = adj.find(input[i]);
		adj.erase(it);
	}
	for (auto it = adj.begin(); it != adj.end(); it++) //对每一个未加入的顶点
		for (int i = 0; i < k; i++) {
			if (!G[input[i]][*it])//但凡发现一条路走不通，试下一个顶点
				break;
			if (i == k - 1) {//说明有一个顶点可以加入进去
				printf("Not Maximal\n");
				return;
			}
		}
	printf("Yes\n");//遍历完所有未加入的顶点都不能加入，则为最大
}
int main()
{
	scanf("%d%d", &Nv, &Ne);
	int v1, v2;
	for (int i = 0; i < Ne; i++) {
		scanf("%d%d", &v1, &v2);
		G[v1][v2] = G[v2][v1] = true;
	}
	int M;
	scanf("%d", &M);
	for (int i = 0; i < M; i++) 
		Judge();
	return 0;
}
/*本题不一定需要用集合来存储，也可以使用数组来指示*/