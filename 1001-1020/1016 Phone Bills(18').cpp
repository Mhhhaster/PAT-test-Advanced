#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
#include<string>
using namespace std;
int price[25];
struct Node {
	string time;
	bool status;
};
vector<Node>peo[1005];
bool cmp(Node a, Node b)
{
	return a.time < b.time;
}
struct Node2 {
	string start;
	string end;
};
vector<Node2>result[1005];
int Countmin(Node2 a)
{
	int starttime = stoi(a.start.substr(0, 2)) * 24 * 60 + stoi(a.start.substr(3, 2)) * 60 + stoi(a.start.substr(6, 2));
	int endtime = stoi(a.end.substr(0, 2)) * 24 * 60 + stoi(a.end.substr(3, 2)) * 60 + stoi(a.end.substr(6, 2));
	return endtime - starttime;
}
double Count(string a)
{
	int h = stoi(a.substr(3, 2));
	double sum = stoi(a.substr(0, 2)) * price[24] * 60.0 + stoi(a.substr(6, 2)) * price[h];
	for (int i = 0; i < h; i++)
		sum += price[i] * 60.0;
	return sum / 100;
}
double Countmoney(Node2 a)
{
	return Count(a.end) - Count(a.start);
}
int main()
{
	for (int i = 0; i < 24; i++) {
		scanf("%d", &price[i]);
		price[24] += price[i];
	}
	int N;
	scanf("%d", &N);
	string name, time, status;
	int count = 1;
	map<string, int>M;
	map<int, string>Month;
	for (int i = 0; i < N; i++) {
		cin >> name >> time >> status;
		if (M[name] == 0)//没有出现过
			M[name] = count++;
		Month[M[name]] = time.substr(0, 2);
		if (status[1] == 'n')
			peo[M[name]].push_back({ time.substr(3),true });
		else
			peo[M[name]].push_back({ time.substr(3),false });
	}
	//得到的新结构体按顺序送入函数求解金额
	for (auto it = M.begin(); it != M.end(); it++) {//排序+过滤
		sort(peo[it->second].begin(), peo[it->second].end(), cmp);
		for (int i = 1; i < peo[it->second].size(); i++)
			if (peo[it->second][i - 1].status == true && peo[it->second][i].status == false)
				result[it->second].push_back({ peo[it->second][i - 1].time,peo[it->second][i].time });
	}
	for (auto it : M) {
		double tempfee, total = 0.0;
		cout << it.first << " " << Month[it.second] << endl;
		for (int i = 0; i < result[it.second].size(); i++) {
			Node2 temp = result[it.second][i];
			cout << temp.start << " " << temp.end;
			tempfee = Countmoney(temp); total += tempfee;
			printf(" %d $%.2f\n", Countmin(temp), tempfee);
		}
		printf("Total amount: $%.2f\n", total);
	}
	return 0;
}
/*
CYLL 01
01:06:01 01:08:03 122 $24.40
28:15:41 28:16:05 24 $3.85
Total amount: $28.25
*/