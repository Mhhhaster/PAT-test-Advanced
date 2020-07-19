#include<vector>
#include<iostream>
using namespace std;
vector<int>G[10001];
vector<int>Indegree(10001);
void Judge()
{
	int num;
	scanf("%d", &num);
	vector<int>tempIn=Indegree;
	vector<int>test(num);
	for (int i = 0; i < num; i++)
		scanf("%d", &test[i]);
	for (int i = 0; i < num; i++) {
		tempIn[test[i]] = 0;
		for (int j = 0; j < G[test[i]].size(); j++)
			tempIn[G[test[i]][j]]--;
	}
	for(int i=0;i<10001;i++)
		if (tempIn[i] > 0) {
			printf("No\n");
			return ;
		}
	printf("Yes\n");
	return;
}
int main()
{
	int Nv, Ne, v1, v2, K;
	scanf("%d%d", &Nv, &Ne);
	for (int i = 0; i < Ne; i++) {
		scanf("%d%d", &v1, &v2);
		G[v1].push_back(v2);
		Indegree[v1]++;
		G[v2].push_back(v1);
		Indegree[v2]++;
	}
	scanf("%d", &K);
	for (int i = 0; i < K; i++)
		Judge();
	return 0;
}
/*我的思路：
统计所有点的入度，如果在删去集合中的点之后还有入度大于0的，说明还有边未被删去
liuchuo的思路：
换一种方式表示图
统计每个顶点相关的边
在处理以边为主要对象的题中有奇效*/