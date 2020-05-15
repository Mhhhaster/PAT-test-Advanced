#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
bool cmp(int a, int b)
{
	return a > b;
}
int main()
{
	int N;
	scanf("%d", &N);
	vector<int>a(N);
	for (int i = 0; i < N; i++)
		scanf("%d", &a[i]);
	sort(a.begin(), a.end(), cmp);//sort函数可以以vector的begin和end作为参数
	int m,n;
	for (n = sqrt((double)N); n >= 1; n--) {
		if (N % n == 0) {
			m = N / n;
			break;
		}
	}
	//建立一个m*n矩阵
	vector<vector<int>>b(m, vector<int>(n));//二阶的向量b，然后对二阶分别赋长度
	//一圈为一次循环，4*3为2圈，m*n一共需要做m+1/2圈
	int times = (m + 1) / 2;
	int row = 0, col = 0;//从(0,0)开始
	int j = 0;//j是a数组的计数器
	for (int i = 1; i <= times; i++)//每一圈先向右赋值m-2*times+1,再下n-2*times，再左，再上
	{
		if(j<=N-1)
		b[row][col] = a[j];
		for (int k = 1; k <=n- 2 * i + 1&&j<=N-1; k++)
			b[row][col++] = a[j++];
		for (int k = 1; k <= m - 2 * i + 1 && j <= N - 1; k++)
			b[row++][col] = a[j++];
		for (int k = 1; k <= n - 2 * i + 1 && j <= N - 1; k++)
			b[row][col--] = a[j++];
		for (int k = 1; k <= m - 2 * i + 1 && j <= N - 1; k++)
			b[row--][col] = a[j++];
		row++; col++;//向内移动一圈
	}
	for (int r = 0; r < m; r++)
	{
		for (int q = 0; q < n; q++)
		{
			printf("%d", b[r][q]);
			if (q != n - 1) printf(" ");
		}
		printf("\n");
	}
	return 0;
}
//本题最重要的是弄清循环嵌套，模拟整个过程