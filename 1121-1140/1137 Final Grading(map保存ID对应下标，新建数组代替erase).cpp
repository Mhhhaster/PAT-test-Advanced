#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
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
	map<string, int>M;
	string ID;
	int proscore, midscore, finalscore;
	//由于必须编程了才有最终成绩，所以只需要保存编程了的人数
	vector<Stu>S;
	int cnt = 1;//保存ID的下标,从1开始避免混淆
	for (int i = 0; i < pronum; i++)
	{
		cin >> ID >> proscore;
		if (proscore >= 200)
		{
			S.push_back({ ID,proscore,-1,-1,0 });
			M.insert({ ID,cnt });
			cnt++;
		}
	}
	for (int i = 0; i < midnum; i++)
	{
		cin >> ID >> midscore;
		if(M[ID]!=0)
			S[M[ID]-1].midscore = midscore;//注意，此时ID不在map中也会M[ID]也会返回0，如何解决->cnt保存+1
	}
	for (int i = 0; i < finnum; i++)
	{
		cin >> ID >> finalscore;
		if(M[ID]!=0)
			S[M[ID] - 1].finalscore = finalscore;
	}
	vector<Stu>ans;
	for (int i = 0; i < cnt - 1;i++)//计算总成绩
	{
		if (S[i].finalscore >= S[i].midscore)
			S[i].lastscore = S[i].finalscore;
		else
			S[i].lastscore = int(0.4 * S[i].midscore + 0.6 * S[i].finalscore + 0.5);//如何进行四舍五入
		if (S[i].lastscore >= 60)
			ans.push_back(S[i]);
	}
	sort(ans.begin(), ans.end(), cmp);
	for (auto it = ans.begin(); it != ans.end(); it++)
		printf("%s %d %d %d %d\n", it->ID.c_str(), it->proscore, it->midscore, it->finalscore, it->lastscore);
	//%s只能输出char*类型，需要通过.c_str()转换string
	return 0;
}