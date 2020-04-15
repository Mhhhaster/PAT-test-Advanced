#include<iostream>
#include<stack>
#include<stdlib.h>
#include<stdio.h>
#include<queue>
using namespace std;
int main()
{
	int N;int b;
	int tag = 0;
	scanf_s("%d%d", &N, &b);
	if (N == 1)
	{
		printf("Yes\n1");
		return 0;
	}
	stack<int>S;
	queue<int>Q;
	int native = N;
	int modi=0;
	while (N > 0)
	{
		S.push(N % b);
		N /= b;
	}//栈里存储元素自顶向下为原数据自前向后
	int weight = 1;
	while (!S.empty())
	{
		modi += S.top()*weight;
		Q.push(S.top());
		S.pop();
		weight *= b;
	}
	if (modi == native)
		printf("Yes\n");
	else
		printf("No\n");
	while (!Q.empty())
	{
		if (tag == 0)
		{
			printf("%d", Q.front());
			Q.pop();
			tag = 1;
		}
		else
		{
			printf(" %d", Q.front());
			Q.pop();
		}
	}
	return 0;
}