/*5
88 70 61 63 65
Sample Output 1:
70 63 88 61 65
YES*/
#include<iostream>
#include<queue>
using namespace std;
typedef struct TreeNode* Tree;
struct TreeNode {
	Tree Left;
	Tree Right;
	int value;
	int height;//空指针高度为0
};
Tree Insert(Tree Root, int n);
Tree BuildTree();
void Traversal(Tree Root);//层序遍历的同时判断是否为完全二叉树
bool flag = true;
int main()
{
	Tree Root=BuildTree();//建立一颗平衡二叉树
	Traversal(Root);//指示是否为完全二叉树
	if (flag)
		printf("\nYES");
	else
		printf("\nNO");
	return 0;
}
Tree BuildTree()
{
	int TreeNodenum,tempnode;
	scanf("%d", &TreeNodenum);
	Tree Root = (Tree)malloc(sizeof(struct TreeNode));
	scanf("%d", &tempnode);
	Root->value = tempnode;
	Root->height = 0;
	Root->Left = NULL;
	Root->Right = NULL;
	while (--TreeNodenum)
	{
		scanf("%d", &tempnode);
		Root = Insert(Root, tempnode);
	}
	return Root;
}

int Getheight(Tree T)//NULL没有height，所以需要写一个函数方便判别
{
	if (!T)
		return -1;
	else
		return T->height;
}
Tree SingleLeftRotation(Tree T)//单旋要更新树高
{//!!!!!!注意，要先更新下面的子树才能更新上面的父亲节点的高度
	Tree A = T->Left;
	T->Left = A->Right;
	A->Right = T;
	T->height= Getheight(T->Left) > Getheight(T->Right) ? Getheight(T->Left) + 1 : Getheight(T->Right) + 1;
	A->height= Getheight(A->Left) > Getheight(A->Right) ? Getheight(A->Left) + 1 : Getheight(A->Right) + 1;
	return A;
}
Tree SingleRightRotation(Tree T)
{
	Tree A = T->Right;
	T->Right = A->Left;
	A->Left = T;
	T->height = Getheight(T->Left) > Getheight(T->Right) ? Getheight(T->Left) + 1 : Getheight(T->Right) + 1;
	A->height = Getheight(A->Left) > Getheight(A->Right) ? Getheight(A->Left) + 1 : Getheight(A->Right) + 1;
	return A;//返回当前的根节点A
}
Tree DoubleLeftRightRotation(Tree T)//左右旋转=左子树右旋，根节点左旋
{
	T->Left = SingleRightRotation(T->Left);//注意，高度并没有改变，不需要更新
	return SingleLeftRotation(T);
}
Tree DoubleRightLeftRotation(Tree T)
{
	T->Right = SingleLeftRotation(T->Right);
	return SingleRightRotation(T);
}
Tree Insert(Tree T, int n)//空指针？左走or右走？更新树高
{
	if (!T)//把NULL指针情况集合起来，不需要分别在左走右走的情况中判别
	{
		T = (Tree)malloc(sizeof(struct TreeNode));
		T->value = n;
		T->height = 0;
		T->Left = NULL;
		T->Right = NULL;
	}
	else if (n > T->value)//右走
	{
		T->Right = Insert(T->Right, n);
		if (Getheight(T->Right) - Getheight(T->Left) == 2)
		{
			if (n > T->Right->value)//右子树的右子树上
				T = SingleRightRotation(T);
			else
				T = DoubleRightLeftRotation(T);
		}
	}
	else if (n < T->value)
	{
		T->Left = Insert(T->Left, n);
		if (Getheight(T->Left) - Getheight(T->Right) == 2)
		{
			if (n > T->Left->value)//左子树的右子树
				T = DoubleLeftRightRotation(T);
			else
				T = SingleLeftRotation(T);
		}
	}
	T->height = Getheight(T->Left) > Getheight(T->Right) ? Getheight(T->Left) + 1 : Getheight(T->Right) + 1;
	return T;
}
int tag = 0;
int p = 0;
void Traversal(Tree Root)//传入树根，层序遍历并返回是否为完全二叉树
{//完全二叉树的条件：如果一个节点缺子树，那么在它后面遍历的节点都不会有子树
	queue<Tree>Q;
	Q.push(Root);
	while (!Q.empty())
	{
		Tree T = Q.front();
		if (T->Right && !T->Left)
			flag = false;
		if (p == 0)
		{
			printf("%d", T->value); p++;
		}
		else
			printf(" %d", T->value);
		Q.pop();
		if (T->Left)Q.push(T->Left);
		if (T->Right)Q.push(T->Right);
		if (tag == 1 && (T->Left || T->Right))
			flag = false;
		if (!T->Left || !T->Right)//如果左子树或者右子树为空
			tag = 1;
	}
}
/*作为复习平衡二叉树非常好
1.NULL节点为0，有值节点>=1；
2.buildtree都是先newnode再n-1次insert
3.insert注意在开头判断NULL情况，最后记得更新树高。
4.单旋注意更新树高从下至上
5.左右=左子树右旋，根节点左旋
6.所有的insert都要被赋值，返回值都是当前递归的根节点
*/
