#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;
int Tosec(string a)
{
	return stoi(a.substr(0, 2)) * 3600 + stoi(a.substr(3, 2)) * 60 + stoi(a.substr(6, 2));
}
vector<int>endtime;
int Findmin()
{
	int index = 0,early=99999999;
	for(int i=0;i<endtime.size();i++)
		if (endtime[i] < early) {
			index = i;
			early = endtime[i];
		}
	return index;
}
int main()
{
	int num, win, last;
	scanf("%d%d", &num, &win);
	endtime.resize(win, 8 * 60 * 60);
	map<int, int>M;
	string time;
	for (int i = 0; i < num; i++) {
		cin >> time >> last;
		int sec = Tosec(time);
		if (sec <= 17 * 3600)
			M[sec] = last * 60;
	}
	double waitsum = 0.0;
	for (auto it : M) {
		int index = Findmin();
		if (endtime[index] > it.first) {
			waitsum += endtime[index] - it.first;
			endtime[index] += it.second;
		}
		else//注意两种情况的窗口更新服务时间不一样
		endtime[index] = it.second+it.first;
	}
	printf("%.1f", waitsum /60.0 / M.size());
	return 0;
}
