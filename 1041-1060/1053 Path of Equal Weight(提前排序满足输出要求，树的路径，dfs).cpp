#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>T[100];
vector<int>weight;
int S;
bool cmp(int a, int b)
{
	return weight[a] > weight[b];
}
vector<int>temppath;
void dfs(int index,int weightsum)
{
	temppath.push_back(weight[index]);
	weightsum += weight[index];
	if (weightsum >= S) //不用再下一层了
	{
		if (weightsum == S&&T[index].size()==0) {
			for (int i = 0; i < temppath.size() - 1; i++)
				printf("%d ", temppath[i]);
			printf("%d\n", temppath[temppath.size() - 1]);
		}
	}
	else 
		for (int i = 0; i < T[index].size(); i++)
			dfs(T[index][i], weightsum);//再下一层
	temppath.pop_back();//返回上一层
}
int main()
{
	int nodenum, noleaf, tempnode, subnum, subid;
	scanf("%d%d%d", &nodenum, &noleaf, &S);
	weight.resize(nodenum);
	for (int i = 0; i < nodenum; i++)
		scanf("%d", &weight[i]);
	for (int i = 0; i < noleaf; i++) {
		scanf("%d%d", &tempnode, &subnum);
		for (int j = 0; j < subnum; j++) {
			scanf("%d", &subid);
			T[tempnode].push_back(subid);
		}
		sort(T[tempnode].begin(), T[tempnode].end(), cmp);
	}
	dfs(0, 0);
	return 0;
}
/*20 9 24
10 2 4 3 5 10 2 18 9 7 2 2 1 3 12 1 8 6 2 2
00 4 01 02 03 04
02 1 05
04 2 06 07
03 3 11 12 13
06 1 09
07 2 08 10
16 1 15
13 3 14 16 17
17 2 18 19

10 5 2 7
10 4 10
10 3 3 6 2
10 3 3 6 2*/