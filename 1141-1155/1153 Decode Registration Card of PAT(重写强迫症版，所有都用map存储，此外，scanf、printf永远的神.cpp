#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
#include<algorithm>
using namespace std;
struct Node1
{
	string cardid;
	int score;
};
struct Node2
{
	int scoresum = 0, peosum = 0;
};
struct Node3
{
	int site, num;
};
bool cmp(Node1 a, Node1 b)
{
	return a.score == b.score ? a.cardid<b.cardid : a.score>b.score;
}
bool cmp2(Node3 a, Node3 b)
{
	return a.num == b.num ? a.site<b.site : a.num>b.num;
}
int main()
{
	int N, M;
	scanf("%d%d", &N, &M);
	string card;
	int score;
	unordered_map<char, vector<Node1>>M1;
	unordered_map<int, Node2>M2;
	unordered_map<int, unordered_map<int, int>>M3temp;
	unordered_map<int, vector<Node3>> M3;
	for (int i = 0; i < N; i++) {
		cin >> card >> score;
		M1[card[0]].push_back({ card,score });
		M2[stoi(card.substr(1, 3))].peosum++;
		M2[stoi(card.substr(1, 3))].scoresum += score;
		M3temp[stoi(card.substr(4, 6))][stoi(card.substr(1, 3))]++;
	}
	int type;
	for (auto it : M1)
		sort(M1[it.first].begin(), M1[it.first].end(), cmp);
	for (auto it : M3temp)
		for (auto next : M3temp[it.first])
			M3[it.first].push_back({ next.first,next.second });
	for (auto it : M3)
		sort(M3[it.first].begin(), M3[it.first].end(), cmp2);
	for (int i = 0; i < M; i++) {
		scanf("%d", &type);
		printf("Case %d: %d ", i + 1, type);
		if (type == 1) {
			char temp; scanf(" %c",&temp); printf("%c\n",temp);
			if (M1[temp].size())
				for (auto it : M1[temp])
					printf("%s %d\n",it.cardid.c_str(),it.score);
			else
				printf("NA\n");
		}
		else if (type == 2) {
			int sitenum;scanf("%d",&sitenum); printf("%03d\n", sitenum);
			if (M2[sitenum].peosum != 0)
				printf("%d %d\n", M2[sitenum].peosum, M2[sitenum].scoresum);
			else
				printf("NA\n");
		}
		else {
			int date; scanf("%d",&date); printf("%06d\n", date);
			if (M3[date].size())
				for (auto it : M3[date])
					printf("%03d %d\n", it.site, it.num);
			else
				printf("NA\n");
		}
	}
}
/*
8 4
B123180908127 99
B102180908003 86
A112180318002 98
T107150310127 62
A107180908108 100
T123180908010 78
B112160918035 88
A107180908021 98
1 A
2 107
3 180908
2 999*/