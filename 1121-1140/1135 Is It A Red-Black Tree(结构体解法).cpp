#include<iostream>
#include<math.h>
using namespace std;
typedef struct TreeNode* Tree;
struct TreeNode {
	int value;
	Tree left;
	Tree right;
};
Tree Insert(int data, Tree Root)
{
	if (Root == NULL) {
		Root = new TreeNode();
		Root->left = Root->right = NULL;
		Root->value = data;//new替代malloc，记住要带上结构体+()
		/*
		Tree Root = (Tree)malloc(sizeof(struct TreeNode));
		Root->value = data;
		Root->left = NULL;
		Root->right = NULL;*/
	}
	else if (abs(Root->value) > abs(data))
		Root->left=Insert(data, Root->left);
	else
		Root->right=Insert(data, Root->right);
	return Root;
}
bool Judge1(Tree Root)//对于每一个红结点，其儿子不能是红
{
	if (Root == NULL)
		return true;
	if (Root->value < 0) {
		if (Root->right != NULL && Root->right->value < 0)
			return false;
		if (Root->left != NULL && Root->left->value < 0)
			return false;
	}
	return Judge1(Root->left) && Judge1(Root->right);
}
int Countblack(Tree Root)//统计该节点出发到叶子结点的路径经过的黑节点的个数，如果相同则返回，不同则返回-999
{
	if (Root == NULL)
		return 0;
	int leftnode = Countblack(Root->left);
	int rightnode = Countblack(Root->right);
	if (Root->value > 0)
		return leftnode == rightnode ? leftnode + 1 : -999;
	else
		return leftnode == rightnode ? leftnode : -999;
}
void Judge()
{
	int N, temp;
	scanf("%d", &N);
	Tree Root = NULL;
	for (int i = 0; i < N; i++) {
		scanf("%d", &temp);
		Root=Insert(temp, Root);
	}
	if (Root->value <= 0||Judge1(Root)==false||Countblack(Root)<0) {
		printf("No\n");
		return;
	}
	printf("Yes\n");
	return;
}
int main()
{
	int testnum;
	scanf("%d", &testnum);
	for (int i = 0; i < testnum; i++)
		Judge();
	return 0;
}
/*首先，注意建树的时候要时刻让Root=Insert，Insert函数也是一定要返回根的值，保证指针的连接
其次是new代替malloc
比数组解法稍慢一点*/