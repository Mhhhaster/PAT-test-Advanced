#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
vector<vector<int>>son;
int levelnum[100000] = { 0 };
void dfs(int root, int level)
{
	levelnum[level]++;
	for (int i = 0; i < son[root].size(); i++)
		dfs(son[root][i], level + 1);
}

int main()
{
	int N;
	double price, rate;
	scanf("%d%lf%lf", &N, &price, &rate);
	son.resize(N);
	int root;
	for (int i = 0; i < N; i++)
	{
		int up;
		scanf("%d", &up);
		if (up == -1)
			root = i;
		else
			son[up].push_back(i);
	}
	//son[i]包含了第i号供应商的下属
	dfs(root, 0);
	//现在levelnum包含了每一层的结点数量
	int i = 0;
	for (; i < 100000; i++)
		if (!levelnum[i])
			break;//也可以在dfs过程中不断更新最大level
	printf("%.2lf %d", pow((1+rate/100), i - 1)*price, levelnum[i - 1]);
	return 0;
}
//没什么好说的，树形题经典liuchuo式dfs