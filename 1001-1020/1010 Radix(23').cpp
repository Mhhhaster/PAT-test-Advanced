#include<iostream>
#include<string>
using namespace std;
long long Get(string a, int radix)//转化为十进制
{
	long long asum = 0;
	long long weight = 1;
	for (int i = a.length() - 1; i >= 0; i--)//从最后开始
	{
		asum += weight * (a[i] - '0' < 10 ? a[i] - '0' : a[i] - 'a' + 10);
		weight *= radix;
	}
	return asum;
}
void Judge(long long a, string b)//判断什么进制能够使b==a
{//从b的最大数开始，如果超过了a的大小或者循环到了35还没有找到相等进制，impossible
	long long minradix = 1;
	for (int i = 0; i < b.length(); i++)
		if ((b[i] - '0' < 10 ? b[i] - '0' : b[i] - 'a' + 10 )> minradix)
			minradix = b[i] - '0' < 10 ? b[i] - '0' : b[i] - 'a' + 10;
	for (int i = minradix; ; i++)
	{
		long long temp = Get(b, i);
		if (temp == a)
		{
			printf("%d", i);
			return;
		}
		if (temp > a)
			break;
	}
	printf("Impossible");
	return;
}
int main()
{
	string a, b;
	int tag;
	long long radix;
	cin >> a >> b >> tag >> radix;//用一个longlong存储十进制结果
	if (tag == 1)
	{
		long long asum = Get(a, radix);
		Judge(asum, b);
	}
	else
	{
		long long bsum = Get(b, radix);
		Judge(bsum, a);
	}
	return 0;
}