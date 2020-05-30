#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Node {
	int value;
	int next;
};
vector < Node>Link(100000);
vector<bool>dup(100000, true);
vector<int>result;
vector<int>rem;
void sortanddump();
int main()
{
	int firstadd, num;
	scanf("%d%d", &firstadd, &num);
	int add, val, nex;
	for (int i = 0; i < num; i++)
	{
		scanf("%d%d%d", &add, &val, &nex);
		Link[add].next = nex;
		Link[add].value = val;
	}
	add = firstadd;
	while (add != -1)
	{//判断绝对值重复
		if (dup[abs(Link[add].value)])
		{//不重复
			dup[abs(Link[add].value)] = false;
			result.push_back(add);
			add = Link[add].next;
		}
		else
		{
			rem.push_back(add);
			add = Link[add].next;
		}
	}
	if (result.size())
	{
		printf("%05d %d ", result[0], Link[result[0]].value);
		for (int i = 1; i < result.size(); i++)
		{
			printf("%05d\n%05d %d ", result[i], result[i], Link[result[i]].value);
		}
		printf("-1\n");
	}
	if (rem.size())
	{
		printf("%05d %d ", rem[0], Link[rem[0]].value);
		for (int i = 1; i < rem.size(); i++)
		{
			printf("%05d\n%05d %d ", rem[i], rem[i], Link[rem[i]].value);
		}
		printf("-1\n");
	}
	return 0;
}
/*
conclude：没什么好说的，尽量在纸上把思路想清楚
速度又快又准
*/
