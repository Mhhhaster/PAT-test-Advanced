#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
typedef struct TreeNode* Tree;
struct TreeNode {
	int left = -1, right = -1, value;
};//left和right分别保存的是在pre中的下标
vector<TreeNode>T;
unordered_map<int, bool>Map;
int BuildTree(int left, int length)
{
	if (length < 1)
		return -1;
	if (length == 1)
		return left;
	int leftlength = -1;
	int root = T[left].value;
	for (int i = left + 1; i < left + length; i++)
		if (T[i].value > root) {//说明该点为右子树开头
			leftlength = i - left - 1;
			break;
		}
	if (leftlength == -1)
		leftlength = length - 1;
	T[left].left = BuildTree(left + 1, leftlength);
	T[left].right = BuildTree(left + leftlength + 1, length - leftlength - 1);
	return left;
}

vector<int>temppath;
void findpath(int index, int data)
{
	if (index == -1) {
		return;
	}
	temppath.push_back(index);
	if (T[index].value > data)//需要往左子树走
		findpath(T[index].left, data);
	else if (T[index].value < data)
		findpath(T[index].right, data);
	else
		return;
}
vector<int> Find(int data)//找到从根节点到data的路径
{
	temppath.clear();
	findpath(0, data);
	return temppath;
}
void Judge()
{
	int u, v;
	scanf("%d%d", &u, &v);
	bool flagu = true, flagv = true;
	vector<int>pathu = Find(u);
	flagu = Map[u];
	vector<int>pathv = Find(v);
	flagv = Map[v];
	if (!flagv && !flagu)
		printf("ERROR: %d and %d are not found.\n", u, v);
	else if (!flagv && flagu)
		printf("ERROR: %d is not found.\n", v);
	else if (flagv && !flagu)
		printf("ERROR: %d is not found.\n", u);
	else {
		for (int i = 0; i < pathu.size() && i < pathv.size(); i++)
			if (pathu[i] != pathv[i]) {
				printf("LCA of %d and %d is %d.\n", u, v, T[i - 1].value);
				return;
			}
		if (pathu.size() > pathv.size())//说明u包含v
			printf("%d is an ancestor of %d.\n", v, u);
		else
			printf("%d is an ancestor of %d.\n", u, v);
	}
	return;
}
int M, N;
int main()
{
	scanf("%d%d", &M, &N); T.resize(N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &T[i].value);
		Map[T[i].value] = true;
	}
	BuildTree(0, N);
	for (int i = 0; i < M; i++)
		Judge();
	return 0;
}
/*
本题经验：运用到查找的地方其实可以用map来实现
观察可以得到，LCA的特征就是值在两子孙之间，并且唯一。对每一个结点遍历，看是否满足条件
最后根据查找结果输出
启示：注意近年题目的风格，在下笔前逻辑思考可能会找到简单很多的解法。*/