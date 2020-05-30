#include<iostream>
using namespace std;
bool Isprime(int N)//是质数返回true
{
	for (int i = 2; i * i <= N; i++)
		if (N % i == 0)
			return false;
	return true;
}
int main()
{
	int N;
	scanf("%d", &N);
	int maxcon = 0;
	int start, end;
	if (Isprime(N))
	{
		printf("1\n%d", N);
		return 0;
	}
	for (int i = 2; i * i <= N; i++)
	{
		if (N % i == 0)
		{
			int length = 1;
			int j = i + 1;
			int temp = N / i;
			while (temp % j == 0)
			{
				temp /= j;
				j++;
			}//j指示的位置为连续的非因子
			length = j - i;
			if (length > maxcon)
			{
				maxcon = length;
				start = i;
				end = j;
			}
		}
	}
	printf("%d\n", maxcon);
	printf("%d", start);
	for (int i = start + 1; i < end; i++)
		printf("*%d", i);
	return 0;
}