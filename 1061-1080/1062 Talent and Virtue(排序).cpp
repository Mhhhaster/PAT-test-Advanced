#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
struct Node
{
	string id;
	int vir, tal;
};
using namespace std;
bool cmp(Node a, Node b)
{
	int totala = a.vir + a.tal;
	int totalb = b.vir + b.tal;
	if (totala == totalb) {
		if (a.vir == b.vir)
			return a.id < b.id;
		else
			return a.vir > b.vir;
	}
	else
		return totala > totalb;
}
int main()
{
	int N, L, H;
	scanf("%d%d%d", &N, &L, &H);
	vector<Node>sage, nobleman, foolman, other;
	string id;
	int vir, tal;
	for (int i = 0; i < N; i++) {
		cin >> id;
		scanf("%d%d", &vir, &tal);
		if (vir < L || tal < L)
			continue;
		else if (vir >= H && tal >= H)
			sage.push_back({ id,vir,tal });
		else if (vir >= H)
			nobleman.push_back({ id,vir,tal });
		else if (vir >= tal)
			foolman.push_back({ id,vir,tal });
		else other.push_back({ id,vir,tal });
	}
	printf("%d\n", sage.size() + nobleman.size() + foolman.size() + other.size());
	sort(sage.begin(), sage.end(), cmp);
	for (auto it : sage)
		printf("%s %d %d\n", it.id.c_str(), it.vir, it.tal);
	sort(nobleman.begin(), nobleman.end(), cmp);
	for (auto it : nobleman)
		printf("%s %d %d\n", it.id.c_str(), it.vir, it.tal);
	sort(foolman.begin(), foolman.end(), cmp);
	for (auto it : foolman)
		printf("%s %d %d\n", it.id.c_str(), it.vir, it.tal);
	sort(other.begin(), other.end(), cmp);
	for (auto it : other)
		printf("%s %d %d\n", it.id.c_str(), it.vir, it.tal);
}