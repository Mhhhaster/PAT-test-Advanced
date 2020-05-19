#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int>fre;//用来记录所有元素出现的次数
vector<int>temp;
int Getmax()//获得数组中fre最大的元素
{
	int max = 0;
	int position;
	for (int i = 1; i < temp.size(); i++)
		if (temp[i] > max)
		{
			max = temp[i]; position = i;
		}
	if (max)
	{
		temp[position] = 0;
		return position;
	}
	else
		return 0;
}
void Printmax(int K)//输出fre中最大的K个
{
	temp.resize(fre.size());
	for (int i = 1; i < fre.size(); i++)
		temp[i] = fre[i];//全部复制到临时数组内
	while (K--)
	{
		int max = Getmax();
		if(max)
		printf(" %d", max);
	}
	printf("\n");
}
int main()
{
	int N, K;
	scanf("%d%d", &N, &K);
	fre.resize(N + 1);
	int temp;
	scanf("%d" ,& temp);
	fre[temp]++;//fre[3]=1;
	for (int i = 1; i < N; i++)//循环N-1次
	{
		scanf("%d", &temp);
		printf("%d:", temp);
		Printmax(K);//输出fre中最大的K个
		fre[temp]++;
	}
	return 0;
}