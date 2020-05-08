#include<queue>
#include<iostream>
using namespace std;
int main()
{
	priority_queue<int>Q;
	int N;
	scanf("%d", &N);
	int a[1000];
	bool b[1000];
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &a[i]);
		if (a[i] >= 0)
			Q.push(a[i]);
	}
	while (!Q.empty())
	{
		printf("%d\n", Q.top());
		Q.pop();
	}
	return 0;
}