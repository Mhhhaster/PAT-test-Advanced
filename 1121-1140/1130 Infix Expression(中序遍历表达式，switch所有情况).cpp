#include<iostream>
#include<vector>
#include<string>
using namespace std;
struct TreeNode {
	string data;
	int left;
	int right;
};
vector<TreeNode>Tree;
string Inordertraversal(int root);
int trueroot;
int main()
{
	int N;
	scanf("%d", &N);
	Tree.resize(N + 1);
	vector<bool>Root(N + 1, false);
	string data;
	int left, right;
	for (int i = 1; i <= N; i++)
	{
		cin >> data >> left >> right;
		Tree[i].data = data;
		Tree[i].left = left;
		if (left != -1)
			Root[left] = true;
		Tree[i].right = right;
		if (right != -1)
			Root[right] = true;
	}
	int root = -1;
	for (int i = 1; i <= N; i++)
		if (!Root[i])
			root = i;
	trueroot = root;
	//现在找到了根节点以及建立一个树，采用中序遍历方式输出
	//1.左子树为字符时输出左括号，右子树为字符时输出右括号
	//2.字符没有左子树时输出左括号及右括号
	string ans = Inordertraversal(root);

	cout << ans;
}
bool Judgeoperator(int i)//判断Tree[i]的内容是不是运算符，是运算符返回false
{
	if (Tree[i].data[0] == '+' || Tree[i].data[0] == '-' || Tree[i].data[0] == '*' || Tree[i].data[0] == '/' || Tree[i].data[0] == '%' || Tree[i].data[0] == '^')
		return false;
	return true;
}

string Inordertraversal(int root)
{
	int left = Tree[root].left;
	int right = Tree[root].right;
	if (left == -1 && right == -1)//左右都空,为字符
	{
		return Tree[root].data;
	}
	if (left == -1 && right != -1)//左空右不空
	{
		return root != trueroot ? "(" + Tree[root].data + Inordertraversal(right) + ")" : Tree[root].data + Inordertraversal(right);
	}
	if (left != -1 && right != -1)//左右都不空
	{
		string ans;
		if (root != trueroot)
			ans += '(';
		ans += Inordertraversal(left) + Tree[root].data + Inordertraversal(right);
		if (root != trueroot)
			ans += ')';
		return ans;
	}
}
/*
每一个运算符对应一次运算，我们都考虑把他左右两边括起来
情况1：左右两边都有，说明结点为运算符，左右两边为字符或者运算符，'('+左+root+右+')'即可
情况2：左右两边都无，说明为字符节点，输出即可
情况3：左无右有，说明为单个负号取反的情况，'('+root+右+')'即可
但是此时，主要到因为我们每次都添加一个括号，而最后一次添加时是不需要括号的，所以要去掉最外层的括号
要么使用substr函数指示需要保存的范围，要么在递归的时候增加判断条件
*/