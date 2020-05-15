#include<iostream>
#include<vector>
using namespace std;
bool Isprime(int i)
{
	for (int j = 2; j * j <= i; j++)
		if (i % j == 0)
			return false;
	return true;
}
int main()
{
	int N;
	int temp;
	scanf("%d", &N);
	vector<int>a(10000,-1);//-1代表没输入，0代表检查过了，1代表my，2代表min，3代表cho
	for(int i=1;i<=N;i++)
	{
		scanf("%d", &temp);
		if (i == 1)
			a[temp] = 1;
		else if (Isprime(i))//是质数
			a[temp] = 2;
		else
			a[temp] = 3;
	}
	int K;
	scanf("%d", &K);
	while (K--)
	{
		scanf("%d", &temp);
		switch (a[temp])
		{
		case -1:printf("%04d: Are you kidding?\n", temp); break;
		case 0:printf("%04d: Checked\n",temp); break;
		case 1:printf("%04d: Mystery Award\n",temp); break;
		case 2:printf("%04d: Minion\n",temp); break;
		case 3:printf("%04d: Chocolate\n",temp); break;
		}
		if(a[temp]>0)a[temp] = 0;
	}
	return 0;
}
//利用整型数组不同的值代表多种状态，简单题