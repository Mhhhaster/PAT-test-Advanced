#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
vector<int>Cscore(2005), Escore(2005), Mscore(2005), Ascore(2005);
int stunum, querynum;
void Getbestrank(int codename)//获得这个序号的最好排名并输出
{
	int bestrank = stunum;
	char tempcourse = 'P';//初始化错误标记
	int temprank = 1;
	for (int i = 1; i <= stunum; i++)
		if (Ascore[i] > Ascore[codename])
			temprank++;
	if (temprank < bestrank) {
		bestrank = temprank;
		tempcourse = 'A';
	}
	temprank = 1;
	for (int i = 1; i <= stunum; i++)
		if (Cscore[i] > Cscore[codename])
			temprank++;
	if (temprank < bestrank) {
		bestrank = temprank;
		tempcourse = 'C';
	}
	temprank = 1;
	for (int i = 1; i <= stunum; i++)
		if (Mscore[i] > Mscore[codename])
			temprank++;
	if (temprank < bestrank) {
		bestrank = temprank;
		tempcourse = 'M';
	}
	temprank = 1;
	for (int i = 1; i <= stunum; i++)
		if (Escore[i] > Escore[codename])
			temprank++;
	if (temprank < bestrank) {
		bestrank = temprank;
		tempcourse = 'E';
	}
	printf("%d %c\n", bestrank, tempcourse);
	return;
}
int main()
{
	scanf("%d%d", &stunum, &querynum);
	unordered_map<string, int>M;
	string id;
	int cs, es, ms, as, count = 1;
	for (int i = 0; i < stunum; i++) {
		cin >> id;
		scanf("%d%d%d", &cs, &ms, &es);
		if (M[id] == 0)
			M[id] = count++;//ID映射范围从1到N
		as = float(cs + es + ms) / 3 + 0.5;
		Cscore[M[id]] = cs; Escore[M[id]] = es; Mscore[M[id]] = ms; Ascore[M[id]] = as;
	}
	for (int i = 0; i < querynum; i++) {
		cin >> id;
		if (M[id] == 0)
			printf("N/A\n");
		else
			Getbestrank(M[id]);
	}
	return 0;
}
/*
他思路简单一直可以的：
本题采用map将学号转化为序号做法，甚至都不需要map，直接用一个数组就行
注意四舍五入的方法：+0.5即可*/