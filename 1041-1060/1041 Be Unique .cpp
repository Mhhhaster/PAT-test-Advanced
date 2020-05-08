#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
/*5 888 666 666 888 888
Sample Output 2:
None*/
//找到第一个不重复的数字

int main()
{
	int N;
	cin >> N;
	int a[10001] = { 0 };
	int* times = (int*)malloc(N * sizeof(int));
	int temp;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		times[i] = temp;
		a[temp]++;
	}
	for (int i = 0; i < N; i++)
	{
		if (a[times[i]] == 1)
		{
			printf("%d", times[i]);
			return 0;
		}
	}
	printf("None");
	return 0;
}