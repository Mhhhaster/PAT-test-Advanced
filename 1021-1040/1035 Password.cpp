#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
typedef struct CodeNode Code;
struct CodeNode
{
	string name;
	string password;
	int tag = 0;
}Stu[1000];
bool Modify(char *a)
{
	if (*a == '1')
	{
		*a = '@';
		return true;
	}
	if (*a == '0')
	{
		*a = '%';
		return true;
	}
	if (*a == 'l')
	{
		*a = 'L';
		return true;
	}
	if (*a =='O')
	{
		*a = 'o';
		return true;
	}
	return false;
}
bool Judge(int i)
{
	int tag = 0;
	int length = Stu[i].password.length();
	for (int j = 0; j < length; j++)
	{
		if (Modify(&Stu[i].password[j]))
			tag++;
	}
	if (tag)
		return true;
	return false;
}
int main()
{
	int N;
	cin >> N;
	int times = 0;
	for(int i=0;i<N;i++)
	{
		cin >> Stu[i].name >> Stu[i].password;
		if (Judge(i))
		{
			times++;
			Stu[i].tag = 1;
		}
	}
	if (times == 0)
	{
		if (N > 1)
			printf("There are %d accounts and no account is modified", N);
		else
			printf("There is 1 account and no account is modified");
	}
	else
		printf("%d\n", times);
	for (int i = 0; i < N; i++)
	{
		if (Stu[i].tag == 1)
			cout << Stu[i].name <<" "<< Stu[i].password << endl;
	}
	return 0;
}
/*
3
Team000002 Rlsp0dfa
Team000003 perfectpwd
Team000001 R1spOdfa

Sample Output 1:
2
Team000002 RLsp%dfa
Team000001 R@spodfa
*/