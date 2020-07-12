#include<iostream>
#include<vector>
using namespace std;
struct TreeNode {
	int left=-1;
	int right=-1;
	int value;
};
vector<TreeNode>T;
void Insert(int root,int index)
{
	if (T[index].value > T[root].value) {
		if (T[root].right != -1)
			Insert(T[root].right, index);
		else
			T[root].right = index;
	}
	else
	{
		if (T[root].left != -1)
			Insert(T[root].left, index);
		else
			T[root].left = index;
	}
}
int maxlevel = 0;
int levelnum[1005] = { 0 };
void dfs(int index,int level)
{
	if (level > maxlevel)
		maxlevel = level;
	levelnum[level]++;
	if (T[index].left != -1)
		dfs(T[index].left, level + 1);
	if (T[index].right != -1)
		dfs(T[index].right, level + 1);
}
int main()
{
	int N;
	scanf("%d", &N);
	T.resize(N);
	for (int i = 0; i < N; i++) 
		scanf("%d", &T[i].value);
	for (int i = 1; i < N; i++)
		Insert(0,i);
	dfs(0,1);
	printf("%d + %d = %d", levelnum[maxlevel], levelnum[maxlevel - 1], levelnum[maxlevel] + levelnum[maxlevel - 1]);
	return 0;
}
/*如果采用结构指针作为参数当然看起来更简便，不需要索引数组的下标，但其实两者都很简单
通过输入的数组构造二叉搜索树并dfs*/