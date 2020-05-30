#include<iostream>
#include<string>
using namespace std;
bool isprime(long long a)//大于等于4的质数或者3、2、1、、、、都返回1，所以需要对1及1以下的输入讨论
{
	for (long long i = 2; i * i <= a; i++)//大于等于四才循环
		if (a % i == 0)
			return false;
	return true;
}
int main()
{
	long long input;
	string output;
	scanf("%lld", &input);
	if (input == 1)
	{
		printf("1=1");
		return 0;
	}
	output += to_string(input);
	output += '=';
	for (long long i = 2; i <= input; i++)
	{
		if (input % i == 0 && isprime(i))
		{
			int expon = 1;
			input /= i;
			while (input % i == 0)
			{
				expon++;
				input /= i;
			}
			if (expon > 1)
			{
				output += to_string(i);
				output += "^";
				output += to_string(expon);
			}
			else
				output += to_string(i);
			if (input != 1)
				output += '*';
		}
	}
	cout << output;
	return 0;
}
/*
conclude：构造输出字符串是个好想法，对于这种题
首先在纸上演算，最后记得边界条件0或1等
*/