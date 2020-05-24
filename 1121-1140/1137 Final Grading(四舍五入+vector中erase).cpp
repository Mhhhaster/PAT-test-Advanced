#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Stu {
	string ID;
	int proscore = -1;
	int midscore = -1;
	int finalscore = -1;
	int lastscore;
};
bool cmp(Stu a, Stu b)
{
	return (a.lastscore != b.lastscore) ? a.lastscore > b.lastscore:a.ID < b.ID;
}
int main()
{
	int pronum, midnum, finnum;
	scanf("%d%d%d", &pronum, &midnum, &finnum);
	string ID;
	int proscore, midscore, finalscore;
	//由于必须编程了才有最终成绩，所以只需要保存编程了的人数
	vector<Stu>S;
	for (int i = 0; i < pronum; i++)
	{
		cin >> ID >> proscore;
		if (proscore >= 200)
			S.push_back({ ID,proscore,-1,-1,-1 });
	}
	for (int i = 0; i < midnum; i++)
	{
		cin >> ID >> midscore;
		for (auto it = S.begin(); it != S.end(); it++)
			if (it->ID == ID)
				it->midscore = midscore;
	}
	for (int i = 0; i < finnum; i++)
	{
		cin >> ID >> finalscore;
		for (auto it=S.begin();it!=S.end();it++)
			if (it->ID == ID)
				it->finalscore = finalscore;
	}
	for (auto it = S.begin(); it != S.end();)//计算总成绩
	{
		if (it->finalscore >= it->midscore)
			it->lastscore = it->finalscore;
		else
			it->lastscore = int(0.4 * it->midscore + 0.6 * it->finalscore + 0.5);//如何进行四舍五入
		if (it->lastscore < 60)
			it = S.erase(it);//如何删除vector中指定元素：需要if-else语句，并且需要赋予erase返回的值
		else
			it++;
	}
	sort(S.begin(), S.end(), cmp);
	for (auto it = S.begin(); it != S.end(); it++)
		printf("%s %d %d %d %d\n",it->ID.c_str(), it->proscore, it->midscore, it->finalscore, it->lastscore);
	//%s只能输出char*类型，需要通过.c_str()转换string
	return 0;
}
//要想更快，不能遍历查找名字，应用map