/*Sample Input :
8
12 11 20 17 1 15 8 5
12 20 17 11 15 8 5 1
Sample Output :
1 11 5 8 17 12 20 15*/
#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
vector<int>in;
vector<int>post;
typedef struct TreeNode* Tree;
struct TreeNode {
	Tree Left;
	Tree Right;
	int depth;
	int data;
};
Tree BuildTree(int inleft,int postleft,int length,int depth);
void Zigzagtraversal(Tree Root);
int main()
{
	int Treenodenum;
	scanf("%d", &Treenodenum);
	in.resize(Treenodenum);
	post.resize(Treenodenum);
	for (int i = 0; i < in.size(); i++)
		scanf("%d", &in[i]);
	for (int i = 0; i < post.size(); i++)
		scanf("%d", &post[i]);
	Tree Root = BuildTree(0,0,Treenodenum,0);//根据in和post建树，需要四个参数，分别指示数组头和长度以及深度
	Zigzagtraversal(Root);//遍历
	return 0;
}

Tree BuildTree(int inleft, int postleft, int length,int depth)//depth指示当前深度，根节点为0
{
	if (length == 0)
		return NULL;
	if (length == 1)
	{
		Tree Root = (Tree)malloc(sizeof(struct TreeNode));
		Root->Left = NULL;
		Root->Right = NULL;
		Root->depth = depth;
		Root->data = in[inleft];
		return Root;
	}
	int Rootpos=inleft;//找到后续遍历中的最后一个元素在中序遍历中的位置
	for (int i = inleft; i < inleft + length; i++)
		if (in[i] == post[postleft + length - 1])
		{
			Rootpos = i; break;
		}
	int leftlength = Rootpos - inleft;
	Tree Root = (Tree)malloc(sizeof(struct TreeNode));
	Root->Left = BuildTree(inleft, postleft, leftlength, depth + 1);
	Root->Right = BuildTree(Rootpos + 1, postleft + leftlength, length-leftlength-1,depth + 1);
	Root->depth = depth;
	Root->data = in[Rootpos];
	return Root;
}

void Zigzagtraversal(Tree Root)
{
	queue<Tree>Q;
	Q.push(Root);
	stack<int>S;
	vector<int>output;//用于输出
	Tree tempRoot;
	while (!Q.empty())
	{
		tempRoot = Q.front();
		Q.pop();
		if (tempRoot->depth == 0)//如果深度为0
			output.push_back(tempRoot->data);
		else if (tempRoot->depth % 2)//如果深度为奇数
		{
			while (!S.empty())//先检查栈里面是不是有元素
			{
				output.push_back(S.top());//有则全部压入待输出数组
				S.pop();
			}
			output.push_back(tempRoot->data);
		}
		else
			S.push(tempRoot->data);//深度为偶数全部压入栈中
		if (tempRoot->Left)Q.push(tempRoot->Left);
		if (tempRoot->Right)Q.push(tempRoot->Right);
	}
	if (!S.empty())
	{
		output.push_back(S.top());
		S.pop();
	}
	printf("%d", output[0]);
	for (int i = 1; i < output.size(); i++)
		printf(" %d", output[i]);
	return;
}