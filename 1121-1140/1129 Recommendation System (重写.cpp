#include<set>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Node
{
	int id, fre;
	bool operator <(const Node& a)const {
		return fre == a.fre ? id<a.id : fre>a.fre;
	}
};
int main()
{
	set<Node>S;
	int N, K, temp;
	scanf("%d%d", &N,&K);
	vector<int>times(N + 1);
	for (int i = 0; i < N; i++) {
		scanf("%d", &temp);
		if (i != 0) {
			int countnum = 0;
			printf("%d:", temp);
			for (auto it : S) {
				if (countnum == K)
					break;
				printf(" %d", it.id);
				countnum++;
			}
			printf("\n");
		}
		auto it = S.find({ temp,times[temp] });
		if (it != S.end())
			S.erase(it);
		times[temp]++;
		S.insert({ temp,times[temp] });
	}
}