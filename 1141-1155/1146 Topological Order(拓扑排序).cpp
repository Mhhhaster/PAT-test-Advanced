#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
vector<int>G[1001];
vector<int>Indegree(1001);
void Judge(int index);
int Nv;
int main()
{
	int Ne, start, end, k;
	scanf("%d%d", &Nv, &Ne);
	for (int i = 0; i < Ne; i++) {
		scanf("%d%d", &start, &end);
		G[start].push_back(end);
		Indegree[end]++;
	}
	scanf("%d", &k);
	for (int i = 0; i < k; i++) 
		Judge(i);
	return 0;
}
bool flag = true;
void Judge(int index)
{
	vector<int>tempin = Indegree;
	unordered_set<int>S;
	for (int i = 1; i <= Nv; i++) {
		if (tempin[i] == 0)
			S.insert(i);
	}
	vector<int>input(Nv);
	for (int i = 0; i < Nv; i++)
		scanf("%d", &input[i]);
	for (int i = 0; i < Nv; i++) {
		auto it = S.find(input[i]);
		if (it == S.end()) {
			if (flag) {
				printf("%d", index);
				flag = false;
			}
			else
				printf(" %d", index);
			return;
		}
		S.erase(it);
		for (int j = 0; j < G[input[i]].size(); j++) {
			int adj = G[input[i]][j];
			tempin[adj]--;
			if (tempin[adj] == 0)
				S.insert(adj);
		}
	}
}
/*
最最简单的拓扑排序
注意，拓扑排序用一个二维数组记录每个点的后序结点，方便在消除路径的时候找到后序结点
用一个一维数组记录出度，消除路径的时候可以直接找到
其实根本不用维护集合，看输入是否在入读为0的集合里，直接判断入读是否为0即可
*/
/*略微改进*/
/*
#include<iostream>
#include<vector>
using namespace std;
vector<int>G[1001];
vector<int>Indegree(1001);
bool flag = true;
int Nv;
void Judge(int index) {
	vector<int>tempin = Indegree;
	vector<int>input(Nv);
	for (int i = 0; i < Nv; i++)
		scanf("%d", &input[i]);
	for (int i = 0; i < Nv; i++) {
		if (tempin[input[i]] != 0) {
			if (flag) {
				printf("%d", index);
				flag = false;
			}
			else
				printf(" %d", index);
			return;
		}
		for (int j = 0; j < G[input[i]].size(); j++) {
			int adj = G[input[i]][j];
			tempin[adj]--;
		}
	}
}
int main()
{
	int Ne, start, end, k;
	scanf("%d%d", &Nv, &Ne);
	for (int i = 0; i < Ne; i++) {
		scanf("%d%d", &start, &end);
		G[start].push_back(end);
		Indegree[end]++;
	}
	scanf("%d", &k);
	for (int i = 0; i < k; i++)
		Judge(i);
	return 0;
}
*/