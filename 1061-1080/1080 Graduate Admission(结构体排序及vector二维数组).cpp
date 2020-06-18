#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
vector<int>enroll[100];//保存每所学校录取的人的ID
vector<int>quota;//保存每所学校的招生人数
struct StuNode {
	float finalgrade;
	float examgrade;
	int ID;
	vector<int>preschool;
};
bool cmp(StuNode a,StuNode b)
{
	return a.finalgrade != b.finalgrade ? a.finalgrade > b.finalgrade:a.examgrade > b.examgrade;
}
int main()
{
	int Stunum, schoolnum, choice;
	unordered_map<int, int>rank;
	scanf("%d%d%d", &Stunum, &schoolnum, &choice);
	quota.resize(schoolnum);
	for (int i = 0; i < schoolnum; i++)
		scanf("%d", &quota[i]);
	vector<StuNode>Stu(Stunum);
	float Ge, Gi;
	int prefer;
	for (int i = 0; i < Stunum; i++){
		scanf("%f%f", &Ge, &Gi);
		Stu[i].examgrade = Ge;
		Stu[i].finalgrade = 0.5 * (Ge + Gi);
		Stu[i].ID = i;
		for (int j = 0; j < choice; j++){
			scanf("%d", &prefer);
			Stu[i].preschool.push_back(prefer);
		}
	}
	sort(Stu.begin(), Stu.end(), cmp);
	for (int i = 0; i < Stunum; i++)
		rank[Stu[i].ID] = i;
	for (int i = 0; i < Stunum; i++) {
		for (int j = 0; j < choice; j++) {
			int tempsch = Stu[i].preschool[j];//代表第i名学生当前想去的学校
			if (enroll[tempsch].size() < quota[tempsch]){//该校没招满
				enroll[tempsch].push_back(Stu[i].ID); break;
			}
			else {
				int sunshan = enroll[tempsch][quota[tempsch] - 1];//找到该校最后一名的ID
				if (Stu[i].examgrade == Stu[rank[sunshan]].examgrade && Stu[i].finalgrade == Stu[rank[sunshan]].finalgrade) {//由于Stu已经拍了序，要从ID反求排名
					enroll[tempsch].push_back(Stu[i].ID); break;
				}//成绩相等那么也招进去
			}
		}
	}
	for (int i = 0; i < schoolnum; i++) {
		sort(enroll[i].begin(), enroll[i].end());
		for (int j = 0; j < enroll[i].size(); j++) {
			if (j != 0) printf(" ");
			printf("%d", enroll[i][j]);
		}
		printf("\n");
	}
	return 0;
}
/*巧用map指引ID和名次，使得不必存储两个数组。
本题使用的sort排序及其cmp为最基本要求，不适宜采用set等，因为不能存储重复元素
*/