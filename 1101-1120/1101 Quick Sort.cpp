#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int N;
	scanf("%d", &N);
	vector<double>a(N);
	vector<bool>b(N, true);
	double* c = (double*)malloc(N * sizeof(double));
	for (int i = 0; i < N; i++)
	{
		scanf("%lf", &a[i]);
		c[i] = a[i];
	}
	sort(c, c + N);
	int num = 0;//表示不能作为pivot的数量
	int max = 0;
	for (int i = 0; i < N; i++)
		if (a[i] != c[i] || a[i] < max)//位置相同是必要条件，位置相同且大于左max是充要条件(可以推出小于右min)
		{
			b[i] = false; num++;
			if (a[i] > max)
				max = a[i];
		}
	printf("%d\n", N - num);
	int flag = 1;
	for (int i = 0; i < N; i++)
		if (b[i])
		{
			if (flag == 1)
			{
				printf("%d", int(a[i]));
				flag++;
			}
			else
				printf(" %d", int(a[i]));
		}
	printf("\n");
	return 0;
}
/*和柳神差别不大，不同的是她是将待输出pivot新建一个数组放入，而我是另开一个bool指示哪些是待输出pivot
倒数第二行的printf("\n")说明如果没有输出的话要额外输出一个换行
*/