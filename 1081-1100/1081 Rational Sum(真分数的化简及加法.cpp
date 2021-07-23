#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
struct rational {
	long long up, down;
};
long long gcd(long long a, long long b)//最大公因子
{
	return b == 0 ? abs(a) : gcd(b, a % b);
}
rational getsimple(rational a)
{
	if (a.up == 0)
		return { 0,1 };
	long long g = gcd(abs(a.up), abs(a.down));
	return { a.up / g,a.down / g };
}
rational Add(rational a, rational b)
{
	long long up = a.up * b.down + a.down * b.up;//可能为0
	long long down = a.down * b.down;
	return getsimple({ up,down });
}
int main()
{
	int N;
	scanf("%d", &N);
	vector<rational>V(N);
	for (int i = 0; i < N; i++)
		scanf("%lld/%lld", &V[i].up, &V[i].down);
	rational sum = V[0];
	for (int i = 1; i < N; i++)
		sum = Add(sum, V[i]);
	long long integer = sum.up / sum.down;
	sum.up = abs(sum.up) - abs(integer * sum.down);
	if (integer)
		printf("%lld ", integer);
	if (sum.up == 0)
		printf("0");
	else
		printf("%lld/%lld", sum.up, sum.down);
	return 0;
}
/*
经验及教训：
符号同一放分子，怕正数和负数的运算就直接全部转为绝对值之间的运算
比如说求最大公因数
*/