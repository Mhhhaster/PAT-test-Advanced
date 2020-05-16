#include<iostream>
#include<vector>
using namespace std;
vector<int>a(10002, -1);//a[0]不编号
int FindRoot(int n)//找到树根(负的那个)
{
	if (a[n] < 0)
		return n;
	else
		return a[n]=FindRoot(a[n]);//路径压缩
}
void Union(int n, int m)
{
	int R1 = FindRoot(n);
	int R2 = FindRoot(m);
	if (R1 != R2)
	{
		if (R1 < R2)//R1树更大
		{
			a[R1]+= a[R2];
			a[R2] = R1; 
		}
		else
		{
			a[R2] += a[R1];
			a[R1] = R2; 
		}
	}
	return;
}
int main()
{
	int N;
	scanf("%d", &N);
	int picbirdnum;
	bool pre[10001] = { false };
	while (N--)
	{
		scanf("%d", &picbirdnum);
		if (picbirdnum == 0)
			continue;
		int temproot,temp;
		scanf("%d",&temproot);
		pre[temproot] = true;
		while (--picbirdnum)
		{
			scanf("%d", &temp);
			pre[temp] = true;
			Union(temproot, temp);
		}
	}//输出鸟的总数(!=-1)，以及集合的总数(负数个数)
	int birdnum,treenum = 0;
	for (birdnum = 1; pre[birdnum] != false; birdnum++)//等于-1时说明已出范围
		if (a[birdnum] < 0)
			treenum++;
	printf("%d %d\n", treenum,birdnum - 1);
	int Q;
	scanf("%d", &Q);
	int temp1, temp2;
	while (Q--)
	{
		scanf("%d%d", &temp1, &temp2);
		if (FindRoot(temp1) == FindRoot(temp2))
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}