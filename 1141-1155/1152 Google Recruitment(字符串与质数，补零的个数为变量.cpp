#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
int getnum(int start, int end, string s)//�������Kλ����
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
bool judge(int num)//����������true�����ж������������
{
	if (num == 0 || num == 1)
		return false;
	for (int i = 2; i * i <= num; i++)//�ܱ�2���ϵ��������Ͳ�������
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
}//����ʹ��s.substr(i,j)��ȡ�ַ�����һ���֣��Լ�ʹ��stoi(s)��ȡ�ַ������������
/*���S�ⷨ��
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
		string t = s.substr(i, k); ʹ������һ���ַ������s��һ����
		int num = stoi(t);    �������ַ�������������ִ�С�������Ͳ���Ҫgetnum����
		if (isPrime(num)) {
			cout << t;
			return 0;
		}
	}
	cout << "404\n";
	return 0;
}
*/