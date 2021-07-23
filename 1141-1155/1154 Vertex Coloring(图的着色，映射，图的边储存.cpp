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
����ֻ��Ҫ�����ڽӵ��Ƿ���ɫ��ͬ�����Կ��Կ���ֻ����ÿ���ߵ���Ϣ
Ȼ�����ÿ���ߣ���ѯ�Ƿ��������������ͬ��ɫ����
���ƵĻ���1134 vertex cover
��ѯ�Ƿ����еı߶������������ļ���S*/