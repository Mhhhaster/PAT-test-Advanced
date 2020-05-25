#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct TreeNode {
	int left = -1;
	int right = -1;
}T[100];
int main()
{
	int Nodenum;
	scanf("%d", &Nodenum);
	bool root[100] = { false };
	char left, right;
	for (int i = 0; i < Nodenum; i++)
	{
		cin >> left >> right;
		if (left == '-')
			T[i].left = -1;
		else {
			T[i].left = left - '0'; root[left - '0'] = true;
		}
		if (right == '-')
			T[i].right = -1;
		else {
			T[i].right = right - '0'; root[right - '0'] = true;
		}
	}
	int Root = 0;
	for (int i = 0; i < Nodenum; i++)
		if (!root[i] && (T[i].left != -1 || T[i].right != -1))
			Root = i;//找到根节点，就是没有出现在其他节点的子树位置上的节点
	queue<int>Q;
	Q.push(Root);
	int temp = Root;
	bool tag = true;
	bool flag = true;
	while (!Q.empty())
	{
		temp = Q.front();
		Q.pop();
		int left = T[temp].left;
		int right = T[temp].right;
		if (left == -1 && right != -1)
		{
			tag = false;
			Q.push(right);
		}
		else if (left != -1 && right != -1)
		{
			Q.push(left);
			Q.push(right);
			if (!flag)
				tag = false;
		}
		else if (left != -1 && right == -1)
		{
			if (!flag)
				tag = false;
			flag = false;
			Q.push(left);
		}
		else if (left == -1 && right == -1)
			flag = false;
	}
	if (tag)
		printf("YES %d", temp);
	else
		printf("NO %d", Root);
	return 0;
}

//判断是否为完全二叉树的方法：层序遍历当一个结点没有左或者右孩子时，它后面所有结点都没孩子。需排除一捺的情况