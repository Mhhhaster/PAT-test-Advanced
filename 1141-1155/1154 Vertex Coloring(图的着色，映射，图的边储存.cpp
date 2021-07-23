#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
bool G[10001][10001] = { false };
int Nv, Ne;
void Judge()
{
	int temp1, temp2;
	unordered_map<int, vector<int>>T;
	for (int j = 0; j < Nv; j++) {
		scanf("%d", &temp1);
		T[temp1].push_back(j);
	}
	for (auto it : T) {
		for (int i = 0; i < it.second.size() - 1; i++) {
			for (int j = i+1; j < it.second.size(); j++) {
				temp1 = it.second[i];
				temp2 = it.second[j];
				if (G[temp1][temp2] == true) {
					printf("No\n");
					return;
				}
			}
		}
	}
	printf("%d-coloring\n", T.size());
	return;
}
int main()
{
	int  v1, v2, K;
	scanf("%d%d", &Nv, &Ne);
	for (int i = 0; i < Ne; i++) {
		scanf("%d%d", &v1, &v2);
		G[v1 ][ v2] = G[v2 ][v1] = true;
	}
	scanf("%d", &K);
	for (int i = 0; i < K; i++) 
		Judge();
}
/*
由于只需要考虑邻接点是否颜色相同，所以可以考虑只保存每条边的信息
然后遍历每条边，查询是否两个顶点具有相同颜色即可
类似的还有1134 vertex cover
查询是否所有的边都出自于所给的集合S*/