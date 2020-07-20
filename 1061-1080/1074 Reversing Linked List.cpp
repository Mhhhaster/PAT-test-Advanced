#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
struct Node {
	int data, nextadd;
};
struct Node2 {
	int address, data;
};
int main()
{
	int firstadd, nodenum, K, tempadd, tempdata, tempnext;
	scanf("%d%d%d", &firstadd, &nodenum, &K);
	unordered_map<int, Node>Map;
	vector<Node2>result, final;
	for (int i = 0; i < nodenum; i++) {
		scanf("%d%d%d", &tempadd, &tempdata, &tempnext);
		Map[tempadd] = { tempdata,tempnext };
	}
	while (firstadd != -1) {
		result.push_back({ firstadd,Map[firstadd].data });
		firstadd = Map[firstadd].nextadd;
	}
	for (int i = 0; i + K <= result.size(); i += K) {
		for (int j = i + K - 1; j >= i; j--)
			final.push_back(result[j]);
	}
	for (int i = result.size() / K * K; i < result.size(); i++)
		final.push_back(result[i]);
	for (int i = 0; i < final.size() - 1; i++)
		printf("%05d %d %05d\n", final[i].address, final[i].data, final[i + 1].address);
	printf("%05d %d -1", final[final.size() - 1].address, final[final.size() - 1].data);
	return 0;
}