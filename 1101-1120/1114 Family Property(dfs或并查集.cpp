#include<iostream>
#include<unordered_map>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;
struct PerNode {
	int housenum = 0;
	int S = 0;
	unordered_set<int>relate;
};
vector<PerNode>G(10000);
int minID, memsum;
int housesum, Ssum;
unordered_map<int, int>M;
unordered_map<int, int>RM;
bool visited[10000] = { false };
void dfs(int index) {
	visited[index] = true;
	if (RM[index] < minID)
		minID = RM[index];
	memsum++;
	housesum += G[index].housenum;
	Ssum += G[index].S;
	for (auto it = G[index].relate.begin(); it != G[index].relate.end(); it++)
		if (visited[*it] == false)
			dfs(*it);
}
struct ResNode {
	int resID;
	int resmemsum;
	float avghouse;
	float avgS;
};
bool cmp(ResNode a, ResNode b)
{
	return (a.avgS != b.avgS) ? a.avgS > b.avgS:a.resID < b.resID;
}
int main()
{
	int N;
	scanf("%d", &N);
	int ID, Fa, Ma, k;
	int count = 1;
	for (int i = 0; i < N; i++) {
		scanf("%d%d%d%d", &ID, &Fa, &Ma, &k);
		if (!M[ID]) {
			M[ID] = count++;
			RM[count - 1] = ID;
		}
		if (Fa != -1) {
			if (!M[Fa]) {
				M[Fa] = count++;
				RM[count - 1] = Fa;
			}
			G[M[ID]].relate.insert(M[Fa]);
			G[M[Fa]].relate.insert(M[ID]);
		}
		if (Ma != -1) {
			if (!M[Ma]) {
				M[Ma] = count++;
				RM[count - 1] = Ma;
			}
			G[M[ID]].relate.insert(M[Ma]);//把映射后的下标加入该点的亲戚中
			G[M[Ma]].relate.insert(M[ID]);
		}
		int temp = -1;
		for (int j = 0; j < k; j++) {
			scanf("%d", &temp);
			if (!M[temp]) {
				M[temp] = count++;
				RM[count - 1] = temp;
			}
			G[M[ID]].relate.insert(M[temp]);
			G[M[temp]].relate.insert(M[ID]);
		}
		scanf("%d%d", &G[M[ID]].housenum, &G[M[ID]].S);
	}
	int familycount = 0;
	vector<ResNode>Res;
	for (int i = 1; i <= M.size(); i++) {
		if (visited[i] == false) {
			minID = 10000; memsum = 0;
			housesum = 0;  Ssum = 0;
			familycount++;
			dfs(i);
			Res.push_back({ minID,memsum,float(housesum) / memsum,float(Ssum) / memsum });
		}
	}
	sort(Res.begin(), Res.end(), cmp);
	printf("%d\n", familycount);
	for (auto it = Res.begin(); it != Res.end(); it++)
		printf("%04d %d %.3f %.3f\n", it->resID, it->resmemsum, it->avghouse, it->avgS);
	return 0;
}
/*本题采用图的dfs遍历方法
优点是主程序简单，函数使用较少
类似的题都可以分为三个部分：
1.保存全部输入
2.处理输入
3.提取出结果并输出
为了防止邻边重复保存，采用了unordered_set，事实证明程序速度还是相对较快


liuchuo：
采用并查集处理输入数据，
并且对并查集简化，father数组保存的是index，合并时比较index即可将所有的结点保存在编号最小的结点下

总结：
注意，当可以把相邻的结点信息全部集中在一点上是，采用并查集*/