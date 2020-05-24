/*6 6 7
01234 880
a1903 199
ydjh2 200
wehu8 300
dx86w 220
missing 400
ydhfu77 99
wehu8 55
ydjh2 98
dx86w 88
a1903 86
01234 39
ydhfu77 88
a1903 66
01234 58
wehu8 84
ydjh2 82
missing 99
dx86w 81
Sample Output:
missing 400 -1 99 99
ydjh2 200 98 82 88
dx86w 220 88 81 84
wehu8 300 55 84 84*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Stu {
	string ID;
	int proscore = -1;
	int midscore=-1;
	int finalscore=-1;
	bool OK = true;
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
	int proscore,midscore, finalscore;
	//由于必须编程了才有最终成绩，所以只需要保存编程了的人数
	vector<Stu>S(pronum);
	for (int i = 0; i < pronum; i++)
	{
		cin >> ID;
		S[i].ID = ID;
		scanf("%d", &proscore);
		S[i].proscore = proscore;
		if (proscore < 200)
			S[i].OK = false;
	}
	for (int i = 0; i < midnum; i++)
	{
		cin >> ID;
		scanf("%d", &midscore);
		for (int i = 0; i < pronum; i++)
			if (S[i].ID == ID)
				S[i].midscore = midscore;
	}
	for (int i = 0; i < finnum; i++)
	{
		cin >> ID;
		scanf("%d", &finalscore);
		for (int i = 0; i < pronum; i++)
			if (S[i].ID == ID)
				S[i].finalscore = finalscore;
	}
	for(int i=0;i<pronum;i++)//计算总成绩
		if (S[i].OK)
		{
			if (S[i].finalscore >= S[i].midscore)
				S[i].lastscore = S[i].finalscore;
			else
				S[i].lastscore = int(0.4 * S[i].midscore + 0.6 * S[i].finalscore+0.5);
			if (S[i].lastscore < 60)
				S[i].OK = false;
		}
	sort(S.begin(), S.end(), cmp);
	for (int i = 0; i < pronum; i++)
	{
		if (S[i].OK)
			cout << S[i].ID << " " <<S[i].proscore<<" "<< S[i].midscore << " " << S[i].finalscore << " " << S[i].lastscore << endl;
	}
	return 0;
}