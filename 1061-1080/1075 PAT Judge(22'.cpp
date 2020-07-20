#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct UserNode {
	vector<int>score;
	int totalmark, fullnum, id;
};
bool cmp(UserNode a, UserNode b) {
	if (a.totalmark != b.totalmark)
		return a.totalmark > b.totalmark;
	else {
		if (a.fullnum != b.fullnum)
			return a.fullnum > b.fullnum;
		else
			return a.id < b.id;
	}
}
void Printscore(vector<int>a) {
	for (int i = 1; i < a.size(); i++) {
		if (a[i] == -1)
			printf(" -");
		else
			printf(" %d", a[i]);
	}
	printf("\n");
}
int main()
{
	int usernum, pronum, subnum;
	scanf("%d%d%d", &usernum, &pronum, &subnum);
	vector<UserNode>User(usernum + 1);
	vector<UserNode>result;
	vector<int>fullmark(pronum + 1);
	for (int i = 1; i <= pronum; i++)
		scanf("%d", &fullmark[i]);
	int uid, pid, scoreget;
	for (int i = 0; i < subnum; i++) {
		scanf("%d%d%d", &uid, &pid, &scoreget);
		if (scoreget != -1) {
			if (User[uid].score.size() == 0) 
				User[uid].score.resize(pronum + 1,-1);//-1表示没有输入
			if(scoreget>User[uid].score[pid])
				User[uid].score[pid] = scoreget;
		}
		else {
			if (User[uid].score.size() && User[uid].score[pid] == -1)
				User[uid].score[pid] = 0;
		}
	}
	for (int i = 1; i <= usernum; i++) {
		User[i].id = i;
		if (User[i].score.size())
			result.push_back(User[i]);
	}
	for (int i = 0; i < result.size(); i++) {
		result[i].totalmark = 0;
		result[i].fullnum = 0;
		for (int j = 1; j <= pronum; j++)
			if (result[i].score[j] != -1) {
				result[i].totalmark += result[i].score[j];
				if (result[i].score[j] == fullmark[j])
					result[i].fullnum++;
			}
	}
	sort(result.begin(), result.end(),cmp);
	int rank = 1, prescore;
	printf("1 %05d %d",result[0].id,result[0].totalmark);
	prescore = result[0].totalmark;
	Printscore(result[0].score);
	for (int i = 1; i < result.size(); i++) {
		if (prescore != result[i].totalmark)
			rank = i + 1;
		printf("%d %05d %d", rank, result[i].id, result[i].totalmark);
		Printscore(result[i].score);
		prescore = result[i].totalmark;
	}
	return 0;
}
/*
错误原因：当输入为-1时自然而然的将其忽略，但没有考虑到还有后续的输入
总而言之，不要用到的数据别着急丢，先保存起来，到时候一起丢~
设置输出标志flag即可
*/