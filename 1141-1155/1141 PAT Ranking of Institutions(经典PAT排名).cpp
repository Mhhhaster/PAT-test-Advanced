#include<iostream>
#include<unordered_map>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
struct Data {
	char level;
	float score;
	int indexsch;//从1到N
};
vector<Data>Stu;
struct School {
	string schoolname;
	int scoresum = 0.0;
	int stusum = 0;
};
vector<float>tempscoresum;
vector<School>Res;
bool cmp(School a,School b){
	if (a.scoresum == b.scoresum) {
		if (a.stusum == b.stusum)
			return a.schoolname < b.schoolname;
		else
			return a.stusum < b.stusum;
	}
	else
		return a.scoresum > b.scoresum;
};
unordered_map<string, int>M;
unordered_map<int, string>RM;
int main()
{
	int N;
	scanf("%d", &N);
	string id, school;
	Stu.resize(N);
	float score;
	int count = 1;
	for (int i = 0; i < N; i++) {
		cin >> id >> score >> school;
		for (int j = 0; j < school.length(); j++)
			school[j] = tolower(school[j]);
		if (!M[school]) {
			M[school] = count++;//将学校都映射为编号，为1~N
			RM[count - 1] = school;
		}
		Stu[i].level = id[0];
		Stu[i].score = score;
		Stu[i].indexsch = M[school];
	}
	int schoolnum = M.size();
	Res.resize(schoolnum); 
	tempscoresum.resize(schoolnum);
	for (int i = 0; i < N; i++) {
		Res[Stu[i].indexsch-1].stusum++;
		float weight = 1.0;
		if (Stu[i].level == 'T')
			weight *= 1.5;
		if (Stu[i].level == 'B')
			weight /= 1.5;
		tempscoresum[Stu[i].indexsch-1] += weight*Stu[i].score;
	}
	for (int i = 0; i < schoolnum; i++) {
		Res[i].scoresum = int(tempscoresum[i]);
		Res[i].schoolname = RM[i + 1];
	}
	printf("%d\n", schoolnum);
	sort(Res.begin(), Res.end(), cmp);
	int rank = 1,pre=-1;
	for (int i = 0; i < schoolnum; i++) {
		if (pre != Res[i].scoresum)
			rank = i + 1;
		printf("%d %s %d %d\n", rank, Res[i].schoolname.c_str(), Res[i].scoresum, Res[i].stusum);
		pre = Res[i].scoresum;
	}
	return 0;
}
/*排序，本题可以直接采用map创建string到int的数组，不需要先映射到int在计算
可见map在统计总数方面十分简便。*/