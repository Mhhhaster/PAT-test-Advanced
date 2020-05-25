#include<iostream>
#include<vector>
#include<set>
#define boy 1
#define girl 0
using namespace std;
struct Stu {
	bool gender;
	set<int>fri;//保存朋友的集合
};
void Print(vector<Stu>V);
vector<pair<int, int >>P;
int main()
{
	int N, M;
	scanf("%d%d", &N, &M);
	int ID1, ID2;
	vector<Stu>V(10000);
	for (int i = 0; i < M; i++)
	{
		scanf("%d%d", &ID1, &ID2);
		if (ID1 < 0)
		{
			V[-ID1].gender = girl;
			ID1 = -1 * ID1;
		}
		else
			V[ID1].gender = boy;
		if (ID2 < 0)
		{
			V[-ID2].gender = girl;
			ID2 = -1 * ID2;
		}
		else
			V[ID2].gender = boy;
		V[ID2].fri.insert(ID1);
		V[ID1].fri.insert(ID2);
	}
	int K;
	scanf("%d", &K);
	for (int i = 0; i < K; i++)
		Print(V);
	return 0;
}
bool Judgeclosefriend(int a, int b, vector<Stu>V)//判断a和b是不是朋友,
{
	for(auto temp = V[a].fri.begin();temp!= V[a].fri.end();temp++)
	{
		if (*temp == b)
			return true;
	}
	return false;
}
void Judgefriend(int id1, int ID2, vector<Stu>V)//判断id1是不是ID2朋友的朋友
{
	bool gender;
	if (ID2 < 0)
	{
		gender = girl;
		ID2 = -ID2;
	}
	else
		gender = boy;
	for(auto close= V[ID2].fri.begin();close!= V[ID2].fri.end();it++)//对于ID2的每一个朋友
	{
		if (V[*close].gender == gender)//性别与ID2相同
			if (Judgeclosefriend(id1, *close, V))//判断id1和close是否为朋友
				P.push_back({ id1,*close });
		continue;
	}
}

void Print(vector<Stu>V)
{
	int ID1, ID2;
	scanf("%d%d", &ID1, &ID2);
	//对于每一个ID1的同性朋友，如果和ID2的同性朋友是朋友，则打印
	//先遍历ID1的每一个同性朋友
	bool gender;
	if (ID1 < 0)
	{
		gender = girl;
		ID1 = -ID1;
	}
	else
		gender = boy;
	for (auto it = V[ID1].fri.begin(); it != V[ID1].fri.end();it++)//遍历每一个ID1的同性朋友
	{
		if (V[*it].gender == gender)//对于id1的同性朋友
			Judgefriend(*it, ID2, V);//判断这个人是不是ID2的朋友的朋友
	}
	printf("%d\n", P.size());
	for(auto it = P.begin();it!=P.end(); it++)
	{
		printf("%04d %04d\n", it->first, it->second);
	}
}
/*
总结：程序逻辑上大体还行，但是要想ac慎用erase，对于此题,如果要求一个遍历有序的序列，还是使用vector+sort组合代替map,除非是
要求每次插入元素都有序的情况
*/