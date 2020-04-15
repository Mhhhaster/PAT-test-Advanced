#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
int main()
{
	float a[4];//记录每一行每一个元素
	float b[4];//记录每一行元素最大值
	int i = 1;
	while(i<=3)
	{
		cin >> a[1] >> a[2] >> a[3];
		if (a[1] > a[2] && a[1] > a[3])
		{
			b[i] = a[1];
			cout << "W";
		}
		if (a[2] > a[1] && a[2] > a[3]) {
			b[i] = a[2];
			cout << "T";
		}
		if (a[3] > a[1] && a[3] > a[2]) {
			b[i] = a[3];
			cout << "L";
		}
		cout << " ";
		i++;
	}
	float sum=1;
	for (int i = 1; i <= 3; i++)
		sum *= b[i];
	sum = sum * 1.3 - 2;
	printf("%.2f", sum);
	return 0;
}