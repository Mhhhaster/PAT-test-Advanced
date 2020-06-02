#include<vector>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
	int N;
	long long p;
	cin >> N >> p;
	vector<long long>sorted(N);
	for (int i = 0; i < N; i++)
		scanf("%lld", &sorted[i]);
	if (p < 1)
	{
		printf("0");
		return 0;
	}
	if (p == 1)
	{
		printf("1");
		return 0;
	}
	sort(sorted.begin(), sorted.end());
	int k = N - 1;
	int kleft = 0, kright = N - 1;//kleft都是可以的，kright都是不行的
	if (N < 1000)
	{
		for (; k >= 0; k--)//每次比较的间隔
			for (int i = 0; i + k < N; i++)
			{
				if (sorted[i] * p >= sorted[i + k])//为k时找到了最大子序列
				{
					printf("%d", k + 1);
					return 0;
				}
			}
	}
	else
	{
		for (; k >= 0; )//每次比较的间隔
			for (int i = 0; i + k < N; i++)
			{
				if (sorted[i] * p >= sorted[i + k])//为k时找到了最大子序列
				{
					kleft = k;
					if ((k + kright) / 2 >= kright)//下一个遍历的也是不行的
					{
						printf("%d", k + 1);
						return 0;
					}
					else
					{
						k = (k + kright) / 2;
						break;
					}
				}
				if (i + k == N - 1)//说明k不符合要求，继续向下
				{
					kright = k;
					if ((k + kleft) / 2 <= kleft)
					{
						printf("%d", kleft + 1);
						return 0;
					}
					else
					{
						k = (k + kleft) / 2;
						break;
					}
				}
			}
	}
	return 0;
}
/*因为发现顺序上考虑问题会超时，所以加了个条件判断，如果数目够大采用二分法解题
和liuchuo不同的是，我每次循环都是区间相同，而她是只固定一边
还是我的速度快些hhh*/