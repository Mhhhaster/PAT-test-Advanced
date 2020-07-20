#include<iostream>
#include<string>
using namespace std;
int main()
{
	string a, result;
	cin >> a;
	if (a[0] == '-')
		result += '-';
	int dotpos = 2, signalpos = 0, expon = 0;
	for (int i = dotpos + 1; i < a.length(); i++)
		if (a[i] == '+' || a[i] == '-')
			signalpos = i;
	expon = stoi(a.substr(signalpos));
	if (expon == 0)
		result += a.substr(1, signalpos - 2);
	else if (expon > 0) {
		if (expon >= signalpos - dotpos - 2) {//说明小数点已经被移走了
			result += a[1];
			result += a.substr(3, signalpos - dotpos - 2);
			for (int i = 0; i < expon - (signalpos - dotpos - 2); i++)
				result += '0';
		}
		else {
			result += a[1];
			result += a.substr(3, expon);
			result += '.';
			result += a.substr(dotpos + expon + 1, signalpos - (dotpos + expon + 2));
		}
	}
	else {
		result += '0';
		result += '.';
		for (int i = 0; i < (-expon) - 1; i++)
			result += '0';
		result += a[1];
		result += a.substr(3, signalpos - dotpos - 2);
	}
	cout << result;
}
/*
科学计数法到常规计数法的转换，
一、分离部分
二、根据指数情况分类讨论
*/