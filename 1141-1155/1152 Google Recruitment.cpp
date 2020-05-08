#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
int getnum(int start, int end, string s)//返回这个K位数字
{
	int temp=0;
	int weight = 1;
	for (int i = end - 1; i >= start; i--)
	{
		temp += (s[i]-'0') * weight;
		weight *= 10;
	}
	return temp;
}
bool judge(int num)//是质数返回true，Δ判断质数经典程序
{
	if (num == 0 || num == 1)
		return false;
	for (int i = 2; i * i <= num; i++)//能被2以上的数整除就不是质数
		if (num % i == 0)
			return false;
	return true;
}
int main()
{
	int L, K;
	cin >> L >> K;
	string str;
	cin >> str;
	int start = 0;
	int end = start+K;
	int temp;
	while (end<L)
	{
		temp=getnum(start, end,str);
		if (judge(temp))
			break;
		start++;
		end = start + K;
	}
	if (end >= L)
		printf("404");
	else
		printf("%0*d",K,temp);
	return 0;
}//区别：使用s.substr(i,j)获取字符串的一部分；以及使用stoi(s)获取字符串代表的数字
/*柳婼解法：
#include <iostream>
#include <string>
using namespace std;
bool isPrime(int n) {
	if (n == 0 || n == 1) return false;
	for (int i = 2; i * i <= n; i++)
		if (n % i == 0) return false;
	return true;
}
int main() {
	int l, k;
	string s;
	cin >> l >> k >> s;
	for (int i = 0; i <= l - k; i++) {
		string t = s.substr(i, k); 使用另外一个字符串获得s的一部分
		int num = stoi(t);    获得这个字符串所代表的数字大小，这样就不需要getnum函数
		if (isPrime(num)) {
			cout << t;
			return 0;
		}
	}
	cout << "404\n";
	return 0;
}
*/