#include<iostream>
#include<vector>
using namespace std;
typedef struct AVLNode* Tree;
struct AVLNode {
	int height;
	int value;
	Tree Left;
	Tree Right;
};
int getheight(Tree Root)
{
	if (Root == NULL)
		return -1;
	else
		return Root->height;
}
Tree Doubleleft(Tree Root)
{
	Tree A = Root->Left;
	Tree temp = A->Right;
	Root->Left = temp;
	A->Right = Root;
	A->height = 1 + (getheight(A->Left) > getheight(A->Right) ? getheight(A->Left) : getheight(A->Right));
	Root->height = 1 + (getheight(Root->Left) > getheight(Root->Right) ? getheight(Root->Left) : getheight(Root->Right));
	return A;
}
Tree Doubleright(Tree Root)
{
	Tree A = Root->Right;
	Tree temp = A->Left;
	Root->Right = temp;
	A->Left = Root;
	A->height = 1 + (getheight(A->Left) > getheight(A->Right) ? getheight(A->Left) : getheight(A->Right));
	Root->height = 1 + (getheight(Root->Left) > getheight(Root->Right) ? getheight(Root->Left) : getheight(Root->Right));
	return A;
}
Tree Leftright(Tree Root)
{
	Root->Left = Doubleright(Root->Left);
	return Doubleleft(Root);
}
Tree Rightleft(Tree Root)
{
	Root->Right = Doubleleft(Root->Right);
	return Doubleright(Root);
}
Tree Insert(Tree Root, int data)
{
	if (Root == NULL) {
		Root = new AVLNode();
		Root->value = data;
		Root->Left = Root->Right = NULL;
		Root->height = 0;
	}
	else {
		if (Root->value > data) {//加在左子树上
			Root->Left = Insert(Root->Left, data);
			if (getheight(Root->Left) - getheight(Root->Right) >= 2) {
				if (data > Root->Left->value)
					Root = Leftright(Root);//注意本句格式
				else
					Root = Doubleleft(Root);
			}
		}
		else {
			Root->Right = Insert(Root->Right, data);
			if (getheight(Root->Right) - getheight(Root->Left) >= 2) {
				if (data > Root->Right->value)
					Root = Doubleright(Root);
				else
					Root = Rightleft(Root);
			}
		}
		Root->height =1+ (getheight(Root->Left) > getheight(Root->Right) ? getheight(Root->Left) : getheight(Root->Right));
	}
	return Root;
}
Tree BuildTree(int nodenum)
{
	Tree Root = NULL;
	int data;
	for (int i = 0; i < nodenum; i++) {
		scanf("%d", &data);
		Root = Insert(Root, data);
	}
	return Root;
}
int main()
{
	int nodenum;
	scanf("%d", &nodenum);
	Tree Root = BuildTree(nodenum);
	printf("%d", Root->value);
	return 0;
}
/*7
88 70 61 96 120 90 65

88*/