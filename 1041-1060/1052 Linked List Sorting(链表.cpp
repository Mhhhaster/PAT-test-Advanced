#include<unordered_map>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
struct Node {
	int value, nextadd;
};
struct Node2 {
	int address, value;
};
bool cmp(Node2 a, Node2 b)
{
	return a.value < b.value;
}
int main()
{
	int nodenum, firstadd;
	scanf("%d%d", &nodenum, &firstadd);
	int tempadd, tempval, tempnext;
	unordered_map<int, Node>M;
	vector<Node2>V;
	for (int i = 0; i < nodenum; i++) {
		scanf("%d%d%d", &tempadd, &tempval, &tempnext);
		M[tempadd] = { tempval,tempnext };
	}
	while (firstadd != -1) {
		V.push_back({ firstadd,M[firstadd].value });
		firstadd = M[firstadd].nextadd;
	}
	sort(V.begin(), V.end(), cmp);
	if (!V.empty()) {
		printf("%d %05d\n", V.size(), V[0].address);
		for (int i = 0; i < V.size() - 1; i++)
			printf("%05d %d %05d\n", V[i].address, V[i].value, V[i + 1].address);
		printf("%05d %d -1", V[V.size() - 1].address, V[V.size() - 1].value);
	}
	else
		printf("0 -1");
	return 0;
}
