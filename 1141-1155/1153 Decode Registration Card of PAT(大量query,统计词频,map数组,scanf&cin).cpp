#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
#include<algorithm>
using namespace std;
struct Stu {
	string id;
	int score;
};
struct Node {
	unordered_map<int, int>M;
};
struct Node2 {
	int num = 0;
	int scoresum = 0;
};
vector<Stu>level[3];
vector<Node2>site(1000);
vector<Node>date(10001);//存储经过映射后的日期当天的考场信息和人数
bool cmp(Stu a, Stu b) {
	return a.score != b.score ? a.score > b.score:a.id < b.id;
}
bool cmp2(pair<int, int>a, pair<int, int>b)
{
	return  a.second != b.second ? a.second > b.second : a.first < b.first;
}
void Judge1(char lev)
{
	if (lev == 'A') {
		for (int i = 0; i < level[0].size(); i++)
			printf("%s %d\n", level[0][i].id.c_str(), level[0][i].score);
		if (level[0].size() == 0)
			printf("NA\n");
	}
	else if (lev == 'B') {
		for (int i = 0; i < level[1].size(); i++)
			printf("%s %d\n", level[1][i].id.c_str(), level[1][i].score);
		if (level[1].size() == 0)
			printf("NA\n");
	}
	else {
		for (int i = 0; i < level[2].size(); i++)
			printf("%s %d\n", level[2][i].id.c_str(), level[2][i].score);
		if (level[2].size() == 0)
			printf("NA\n");
	}
	return;
}
void Judge2(int sitename)
{
	if (site[sitename].num == 0) {
		printf("NA\n"); return;
	}
	printf("%d %d\n", site[sitename].num, site[sitename].scoresum);
}
unordered_map<string, int>dateto;
void Judge3(int datename)
{
	if (date[datename].M.size() == 0) {
		printf("NA\n"); return;
	}
	vector<pair<int, int>>temp;
	for (auto it = date[datename].M.begin(); it != date[datename].M.end(); it++)
		temp.push_back({ it->first,it->second });
	sort(temp.begin(), temp.end(), cmp2);
	for (int i = 0; i < temp.size(); i++)
		printf("%d %d\n", temp[i].first, temp[i].second);
	return;
}
int main()
{
	int cardnum, querynum;
	int count = 1;
	scanf("%d%d", &cardnum, &querynum);
	string id; int score;
	for (int i = 1; i <= cardnum; i++) {
		cin >> id >> score;
		if (id[0] == 'A')
			level[0].push_back({ id,score });
		else if (id[0] == 'B')
			level[1].push_back({ id,score });
		else
			level[2].push_back({ id,score });
		int testsite = stoi(id.substr(1, 3));
		site[testsite].num++; site[testsite].scoresum += score;
		string testdate = id.substr(4, 6);
		if (dateto[testdate] == 0) {
			dateto[testdate] = count;
			date[count++].M[testsite]++;
		}
		else
			date[dateto[testdate]].M[testsite]++;
	}
	for (int i = 0; i < 3; i++)
		sort(level[i].begin(), level[i].end(), cmp);//按输出要求排序
	int type;
	for (int i = 1; i <= querynum; i++) {
		scanf("%d", &type);
		printf("Case %d: %d ", i, type);
		if (type == 1) {
			char lev;
			scanf(" %c", &lev);
			printf("%c\n", lev);
			Judge1(lev);
		}
		else if (type == 2) {
			int sitename;
			scanf("%d", &sitename);
			printf("%d\n", sitename);
			Judge2(sitename);
		}
		else {
			string datename;
			cin >> datename;
			printf("%s\n", datename.c_str());
			Judge3(dateto[datename]);
		}
	}
	return 0;
}
/*
liuchuo:
先把所有考⽣的准考证和分数记录下来～
1、按照等级查询，枚举选取匹配的学⽣，然后排序即可
2、按照考场查询，枚举选取匹配的学⽣，然后计数、求和
3、按⽇期查询每个考场⼈数，⽤unordered_map存储，最后排序汇总～
me:
在输入的时候就处理好所有的数据，方便输出；
优点是处理大量的query会很有优势(快了3倍)
本题的思路还是可以延续：简化处理query时的操作步骤，最好提前将数据处理好(比如说排序)，而不是需要查询的时候再排序
此外，注意到使用scanf和printf的速度要比cin和cout快了4倍，今后一定能用scnaf和printf就用
本题剩下的记录还有substr的用法和pair及sort
本题采用vector+map代替map数组，采用map统计词频是个省事的好方法*/