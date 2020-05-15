#include<iostream>
#include<queue>
using namespace std;
typedef int Tree;
struct TreeNode {
	Tree left;
	Tree right;
}T[10];
Tree BuildTree(int num)//建树并返回树根
{
	char left, right;
	for (int i = 0; i < num; i++)
	{
		scanf(" %c %c", &left, &right);
		if (left == '-')
			T[i].left = -1;
		else
			T[i].left = left - '0';
		if(right=='-')
			T[i].right = -1;
		else
			T[i].right = right - '0';
	}
	bool a[10] = { false };
	for (int i = 0; i < num; i++)
	{
		if (T[i].left >= 0)
			a[T[i].left] = true;
		if (T[i].right >= 0)
			a[T[i].right] = true;
	}
	int root=-1;
	for (int i = 0; i < num; i++)
		if (a[i] == false)
			root = i;
	return root;
}
void Leveltraversal(int Root);
void Inordertraversal(int Root);
int main()
{
	int treenode_num;
	scanf("%d", &treenode_num);
	Tree Root = BuildTree(treenode_num);
	Leveltraversal(Root);
	Inordertraversal(Root);
	return 0;
}
void Leveltraversal(int Root)
{
	queue<int>Q;
	Q.push(Root);
	int flag = 0;//输出格式控制
	while (!Q.empty())//这里选择在出栈的时候输出
	{
		if (flag)
			printf(" ");
		flag++;
		int node = Q.front();
		Q.pop();
		printf("%d", node);
		if (T[node].right >= 0)
			Q.push(T[node].right);
		if (T[node].left >= 0)
			Q.push(T[node].left);
	}
	printf("\n");
}
int tag = 0;
void Inordertraversal(int Root)
{
	
	if (T[Root].right >= 0)
		Inordertraversal(T[Root].right);
	if (tag) 
		printf(" %d", Root); 
	else
	{
		printf("%d", Root); tag++;
	}
	if (T[Root].left >= 0)
		Inordertraversal(T[Root].left);
	
}