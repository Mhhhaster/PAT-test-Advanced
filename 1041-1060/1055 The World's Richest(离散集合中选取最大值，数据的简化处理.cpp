#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<algorithm>
#include<set>
using namespace std;
struct Data {
	string id;
	int age, worth;
};
vector<Data>V;
bool cmp(Data a, Data b)
{
	return a.worth == b.worth ? a.id<b.id: a.worth>b.worth;
}
struct Node {
	string id;
	int worth;
};
vector<Node>Age[201];
int index[201] = { 0 };
struct resnode {
	string id;
	int worth, age;
	bool operator <(const resnode &a)const {
		if (worth == a.worth) {
			if (age == a.age)
				return id < a.id;
			else
				return age < a.age;
		}
		else return worth > a.worth;
	}
};
int main()
{
	int N, K;
	scanf("%d%d", &N, &K);
	V.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> V[i].id;
		scanf("%d %d", &V[i].age, &V[i].worth);
	}
	sort(V.begin(), V.end(), cmp);
	for (int i = 0; i < N; i++) {
		if (Age[V[i].age].size() > 100)
			continue;
		Node temp;
		temp.id = V[i].id;
		temp.worth = V[i].worth;
		Age[V[i].age].push_back(temp);
	}
	int num, Amin, Amax;
	for (int i = 1; i <= K; i++) {
		scanf("%d%d%d", &num, &Amin, &Amax);
		printf("Case #%d:\n", i);
		set<resnode>S;
		fill(index, index + 201, 0);
		int cnt = 0;
		bool flag = false;
		for (int i = Amin; i <= Amax; i++)
			if (Age[i].size())
				S.insert({ Age[i][index[i]].id,Age[i][index[i]].worth,i });//最上面一层加入集合
		while (1) {
			if (cnt == num)
				break;
			auto max = S.begin();
			if (max == S.end())
				break;
			printf("%s %d %d\n", max->id.c_str(), max->age, max->worth);
			flag = true;
			if (++index[max->age] < Age[max->age].size())
				S.insert({ Age[max->age][index[max->age]].id,Age[max->age][index[max->age]].worth,max->age });
			S.erase(max);//取出集合最前元素并输出及擦除，找到该元素同年龄段的下一个人并加入
			cnt++;
		}
		if (flag == false)
			printf("None\n");
	}
	return 0;
}
/*本题核心是注意到几个输入量大小的差异
从而通过忽略大部分数据得以精简程序
*/