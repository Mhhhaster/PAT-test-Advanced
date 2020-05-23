#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int N;
	scanf("%d", &N);
	vector<int>a(N);
	vector<bool>b(N,true);
	for (int i = 0; i < N; i++)
		scanf("%d", &a[i]);
	int times = 0;
	int start, temp;
	for (int i = 0; i < N; i++)
	{
		if (a[i] != i && b[i] == true)//a[i]的值不对且b[i]还没有被收录
		{
			int loopsize = 1;
			start = i;
			temp = a[i];
			b[i] = false;
			while (temp != start)
			{
				b[temp] = false;
				temp = a[temp];
				loopsize++;
			}
			if (start != 0)
				times += loopsize + 1;
			else
				times += loopsize - 1;
		}
	}
	printf("%d", times);
}