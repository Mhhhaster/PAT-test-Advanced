#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
vector<unordered_set<int>>V;
int main()
{
	int setnum, M, temp, K;
	scanf("%d", &setnum);
	V.resize(setnum + 1);
	for (int i = 1; i <= setnum; i++) {
		scanf("%d", &M);
		for (int j = 0; j < M; j++) {
			scanf("%d", &temp);
			V[i].insert(temp);
		}
	}
	scanf("%d", &K);
	int s1, s2, samenum;
	for (int i = 0; i < K; i++) {
		samenum = 0;
		scanf("%d%d", &s1, &s2);
		for (auto it : V[s1])
			if (V[s2].find(it) != V[s2].end())
				samenum++;
		printf("%.1f%%\n", samenum * 100.0 / (V[s1].size() + V[s2].size() - samenum));
	}
	return 0;
}
/*
3
3 99 87 101
4 87 101 5 87
7 99 101 18 5 135 18 99
2
1 2
1 3*/