#include<iostream>
#include<vector>
using namespace std;
vector<int>pre;
vector<int>post;
vector<int>in;
bool flag = true;//unique的标志
int temp[31] = { 0 };
void solve(int preleft, int postleft, int inleft, int length)//基本上遍历之间的转化都可以用这几个参数搞定
{
	int i, j;
	if (length == 1)
	{
		in[inleft] = pre[preleft]; return;
	}
	if (length < 1)//这两个都是终止条件
		return;
	for (i = 0;; i++)
	{
		temp[pre[preleft + 1 + i]]++;
		temp[post[postleft + i]]--;
		for (j = 1; j <= 30; j++)
		{
			if (temp[j] != 0)
				break;
		}
		if (j == 31)
			break;
	}//以上所有工作是为了得出左子树与右子树的分界
	int leftlength = i + 1;
	if (leftlength == length - 1)
		flag = false;
	solve(preleft + 1, postleft, inleft, leftlength);
	in[inleft + leftlength] = pre[preleft];//简单的两个递归调用
	solve(preleft + leftlength + 1, postleft + leftlength, inleft + leftlength + 1, length - leftlength - 1);
}

void Print(int N)
{
	printf("%d", in[1]);
	for (int i = 2; i <= N; i++)
		printf(" %d", in[i]);
}
int main()
{
	int N;
	scanf("%d", &N);
	pre.resize(N + 1);
	post.resize(N + 1);
	in.resize(N + 1);
	for (int i = 1; i <= N; i++)
		scanf("%d", &pre[i]);
	for (int i = 1; i <= N; i++)
		scanf("%d", &post[i]);
	solve(1, 1, 1, N);
	if (flag)
		printf("Yes\n");
	else
		printf("No\n");
	Print(N);//打印中序序列
	printf("\n");
	return 0;
}