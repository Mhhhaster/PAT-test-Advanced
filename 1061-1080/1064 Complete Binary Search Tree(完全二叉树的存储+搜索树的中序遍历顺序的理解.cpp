#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
vector<int>Data;
vector<int>T;
int N, countnum = 0;
void dfs(int index)
{
	if (index * 2 + 1 < N)
		dfs(index * 2 + 1);
	T[index] = Data[countnum++];
	if (index * 2 + 2 < N)
		dfs(index * 2 + 2);
}
int main()
{
	scanf("%d", &N);
	T.resize(N);
	Data.resize(N);
	for (int i = 0; i < N; i++)
		scanf("%d", &Data[i]);
	sort(Data.begin(), Data.end());
	dfs(0);
	printf("%d", T[0]);
	for (int i = 1; i < N; i++)
		printf(" %d", T[i]);
	return 0;
}