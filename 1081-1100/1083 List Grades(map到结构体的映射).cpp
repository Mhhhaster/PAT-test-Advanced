/*4
Tom CS000001 59
Joe Math990112 89
Mike CS991301 100
Mary EE990830 95
60 100

Mike CS991301
Mary EE990830
Joe Math990112*/
#include<iostream>
#include<vector>
#include<map>
using namespace std;
struct Node
{
	string name, id;
};
int main()
{
	int N, tempgrade;
	scanf("%d", &N);
	string tempname, tempid;
	map<int, Node>M;
	vector<Node>result;
	for (int i = 0; i < N; i++) {
		cin >> tempname >> tempid >> tempgrade;
		M[tempgrade] = { tempname,tempid };
	}
	int grade1, grade2;
	scanf("%d%d", &grade1, &grade2);
	for (auto it : M) {
		if (it.first >= grade1 && it.first <= grade2)
			result.push_back(it.second);
	}
	for (int i = result.size() - 1; i >= 0; i--) 
		cout << result[i].name << " " << result[i].id << endl;
	if (result.empty())
		cout << "NONE";
	return 0;
}