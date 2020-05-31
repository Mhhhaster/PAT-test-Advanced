#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
	string str;
	cin >> str;
	int length = str.length();
	int np = 0, nt = 0;//分别指示当前位置之前的P数量和之后的T数量
	for (int i = 0; i < length; i++)
		if (str[i] == 'T')
			nt++;//统计所有的T
	long long sum = 0;
	for (int i = 0; i < length; i++)
	{
		if (str[i] == 'P')
			np++;
		if (str[i] == 'T')
			nt--;
		if (str[i] == 'A')
			sum += np * nt;
		if (sum >= 1000000007)
			sum %= 1000000007;
	}
	printf("%lld", sum);
}