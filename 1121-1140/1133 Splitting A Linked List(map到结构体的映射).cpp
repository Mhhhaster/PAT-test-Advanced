#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
struct Data {
	int value, next;
};
struct Node {
	int address, value;
};
int main()
{
	unordered_map<int, Data>M;
	int firstadd, nodenum, K;
	scanf("%d%d%d", &firstadd, &nodenum, &K);
	vector<Node>Link, Link2;
	int tempadd, tempval, tempnext;
	for (int i = 0; i < nodenum; i++) {
		scanf("%d%d%d", &tempadd, &tempval, &tempnext);
		Data tempnode;
		tempnode.next = tempnext; tempnode.value = tempval;
		M[tempadd] = tempnode;
	}
	int nextaddress = firstadd;
	while (nextaddress != -1) {
		Link.push_back({ nextaddress,M[nextaddress].value });
		nextaddress = M[nextaddress].next;
	}
	for (int i = 0; i < Link.size(); i++) {
		if (Link[i].value < 0)
			Link2.push_back(Link[i]);
	}//筛选出值为负的
	for (int i = 0; i < Link.size(); i++)
		if (Link[i].value <= K && Link[i].value >= 0)
			Link2.push_back(Link[i]);
	for (int i = 0; i < Link.size(); i++)
		if (Link[i].value > K)
			Link2.push_back(Link[i]);
	for (int i = 0; i < Link2.size()-1; i++) 
		printf("%05d %d %05d\n", Link2[i].address, Link2[i].value, Link2[i + 1].address);
	printf("%05d %d -1", Link2[Link2.size() - 1].address, Link2[Link2.size() - 1].value);
	return 0;
}
/*核心亮点在于map对应结构体，经典的链表问题：数据的保存与提取*/