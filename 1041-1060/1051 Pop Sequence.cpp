/*Sample Input:
5 7 5
1 2 3 4 5 6 7
3 2 1 7 5 6 4
7 6 5 4 3 2 1
5 6 4 3 7 2 1
1 7 6 5 4 3 2
Sample Output:
YES
NO
NO
YES
NO*/
#include<iostream>
#include<stack>
using namespace std;
void Judge(int maxsize, int seqlength)
{//输入分两种情况，第一种是需要pop第二种是需要push
	int* a = (int*)malloc((seqlength + 1) * sizeof(int));
	stack<int>S;
	for (int i = 1; i <= seqlength; i++)
		cin >> a[i];
	int cur = 1;//指示序列号
	for (int i = 1; i <= seqlength; i++) {//模拟从1开始进栈
		S.push(i);
		if (S.size() > maxsize)
			break;
		while (!S.empty() && S.top() == a[cur]) {//如果S不为空并且序列与栈顶元素相同
			S.pop();
			cur++;
		}
	}
	if (cur == seqlength + 1)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}
int main()
{
	int M, N, K;
	scanf("%d%d%d", &M, &N, &K);
	while (K--)
		Judge(M, N);
	return 0;
}