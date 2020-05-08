/*
15 43 71 
Sample Output:
#123456
*/
#include<iostream>
#include<string>
#include<stack>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
void Print(int n)
{
	if (n <= 10)
		printf("%d", n);
	else
	{
		switch (n)
		{
			10:printf("A"); break;
			11:printf("B"); break;
			12:printf("C"); break;
		}
	}
	return;
}
int main()//十进制转换为十二进制
{
	int sum;
	int j = 3;
	printf("#");
	int b[2];
	int i = 0;
	while (j--)
	{
		cin >> sum;
		b[0] = sum / 13;
		b[1] = sum % 13;
		Print(b[0]);
		Print(b[1]);
	}
	return 0;
}