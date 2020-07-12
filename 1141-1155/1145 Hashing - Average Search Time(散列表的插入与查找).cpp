#include<iostream>
#include<vector>
using namespace std;
int nextprime(int N)
{//1后为2，2后为3，3，5，7；除了为1时，都采用判断奇偶法
	if (N == 1)
		return 2;
	if (N % 2==0)//为偶数
		N++;
	while (1) {
		bool flag = true;
		for (int i = 2; i * i <= N; i++) 
			if (N % i==0) {
				flag = false;
				break;
			}
		if (flag == true)
			return N;
		N += 2;
	}
}
int main()
{
	int N, inputnum, testnum;
	scanf("%d%d%d", &N, &inputnum, &testnum);
	int Size = nextprime(N);
	vector<int>H(Size,-1);
	int pos, temp;
	for (int i = 0; i < inputnum; i++) {
		scanf("%d", &temp);
		bool flag = false;
		for (int inc = 0; inc <= Size; inc++) {
			pos = (temp + inc * inc) % Size;
			if (H[pos] == -1) {
				H[pos] = temp;
				flag = true;//插入成功
				break;
			}
		}
		if (flag == false)
			printf("%d cannot be inserted.\n", temp);
	}
	float count = 0;
	for (int i = 0; i < testnum; i++) {
		scanf("%d", &temp);
		for (int inc = 0; inc <= Size; inc++) {
			count++;
			pos = (temp + inc * inc) % Size;
			if (H[pos] == temp || H[pos] == -1)
				break;//查找成功或者查找失败
		}
	}
	printf("%.1f", count / testnum);
	return 0;
}
/*
和liuchuo基本一模一样
唯一不同的是她的nextprime是从2到根号n都取余一遍，看是否有为0的
本体的技巧主要体现在增量的设置从0开始，设立flag指示插入成功与否*/