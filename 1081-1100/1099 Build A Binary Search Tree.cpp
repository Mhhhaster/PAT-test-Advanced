#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
struct Node
{
	int left;
	int right;
	int value;
	int leftnum;
	int rightnum;
};
vector<Node>T;
vector<int>a;
int Countnum(int i);//返回树根加子树个数
void getvalue(int i,int start,int end);
void leveltraversal(int root);
int main()
{
	int num;
	scanf("%d", &num);
	int left, right;
	T.resize(num);
	for (int i = 0; i < num; i++)
	{
		scanf("%d%d", &left, &right);
		T[i].left = left;
		T[i].right = right;
	}
	Countnum(0);//每个节点知道左右两边的结点数
	a.resize(num);
	for (int i = 0; i < num; i++)
		scanf("%d", &a[i]);
	sort(a.begin(),a.end());
	getvalue(0,0,num-1);
	leveltraversal(0);
	return 0;
}
void getvalue(int i,int sl,int sr)//根据输入的数列，减而治之赋值value
{
	int leftnum = T[i].leftnum;
	int rightnum = T[i].rightnum;
	T[i].value = a[sl + leftnum];
	if (T[i].left != -1)
		getvalue(T[i].left, sl, sl + leftnum - 1);
	if (T[i].right != -1)
		getvalue(T[i].right, sl + leftnum + 1, sr);
}
int Countnum(int i)//根据树形状递归赋值leftnum、rightnum
{
	if (T[i].left == -1)
		T[i].leftnum = 0;
	else
		T[i].leftnum = Countnum(T[i].left);
	if (T[i].right == -1)
		T[i].rightnum = 0;
	else
		T[i].rightnum=Countnum(T[i].right);//分别计算左右子树的个数
	return T[i].leftnum + T[i].rightnum + 1;
}
void leveltraversal(int root)//层序遍历
{
	queue<int>Q;
	Q.push(root);
	while (!Q.empty())
	{
		int temp = Q.front();
		printf("%d", T[temp].value);
		Q.pop();
		if (T[temp].left != -1)
			Q.push(T[temp].left);
		if (T[temp].right != -1)
			Q.push(T[temp].right);
		if (!Q.empty())
			printf(" ");
	}
}
/*conclude：
我：根据搜索树的特性（大于左小于右），递归赋值
liuchuo：根据搜索树中序遍历结果的有序性来赋值
收获：sort对STL排序记得使用.begin()和.end()
*/