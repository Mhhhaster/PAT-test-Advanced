#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int>in;
vector<int>post;
typedef struct TreeNode *Tree;
struct TreeNode {
	int index, depth;
	Tree left, right;
};
struct Node {
	int index, depth;
};
vector<int>deep[100];
int maxdepth = 0;
void bfs(Tree Root)
{
	queue<Tree>Q;
	Q.push(Root);
	while (!Q.empty()) {
		Tree Next = Q.front();
		if (Next->depth > maxdepth)
			maxdepth = Next->depth;
		deep[Next->depth].push_back(Next->index);
		Q.pop();
		if (Next->left)
			Q.push(Next->left);
		if (Next->right)
			Q.push(Next->right);
	}
}
Tree BuildTree(int inleft, int postleft, int length,int level)
{
	if (length < 1)
		return NULL;
	Tree T = new TreeNode();
	T->index = post[postleft + length - 1];
	T->depth = level;
	int pos = inleft;
	for (; pos < inleft + length; pos++)
		if (in[pos] == T->index)
			break;
	int leftlength = pos - inleft;
	T->left = BuildTree(inleft, postleft, leftlength, level + 1);
	T->right = BuildTree(inleft + leftlength + 1, postleft + leftlength, length - leftlength - 1, level + 1);
	return T;
}
int main()
{
	int N;
	scanf("%d", &N);
	in.resize(N); post.resize(N);
	for (int i = 0; i < N; i++)
		scanf("%d", &in[i]);
	for (int i = 0; i < N; i++)
		scanf("%d", &post[i]);
	Tree Root=BuildTree(0, 0, N,0);
	bfs(Root);
	printf("%d", deep[0][0]);
	for (int i = 1; i <= maxdepth; i++) {
		if (i % 2)
			for (int j = 0; j < deep[i].size(); j++) 
				printf(" %d", deep[i][j]);
		else
			for (int j = deep[i].size() - 1; j >= 0; j--)
				printf(" %d", deep[i][j]);
	}
	return 0;
}
/*
这题也可把赋深度移入bfs中，而不是dfs时
*/