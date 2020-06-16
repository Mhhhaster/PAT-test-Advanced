#include<iostream>
#include<vector>
using namespace std;
bool Isprime(int num)
{
	for (int i = 2; i * i <= num; i++)
		if (num % i == 0)
			return false;
	return true;
}
int nextprime(int num)
{
	if (num == 2 || num == 1)
		return 2;
	int start = (num % 2 == 0 ? num + 1 : num);
	while (1)
	{
		if (Isprime(start))
			return start;
		start += 2;
	}
}
int main()
{
	int Msize, N;
	scanf("%d%d", &Msize, &N);
	int tablesize = nextprime(Msize);
	vector<int>H(tablesize, -1);
	int item = -1, pos1;
	for (int i = 0; i < N; i++)
	{
		if (i != 0)
			printf(" ");
		scanf("%d", &item);
		pos1 = item % tablesize;//应该存放的位置
		for (int inc = 0; inc <= tablesize; inc++)
		{
			if (H[(pos1 + inc * inc) % tablesize] == -1)
			{
				H[(pos1 + inc * inc) % tablesize] = item;
				printf("%d", (pos1 + inc * inc) % tablesize);
				break;
			}
			if (inc == tablesize)
				printf("-");
		}
	}
}
/*
hashtable的应用,平方探测法
本题复习了nextprime的完整写法，要从1开始考虑
此外，平方探测法可以让增量从0开始，简化程序
*/