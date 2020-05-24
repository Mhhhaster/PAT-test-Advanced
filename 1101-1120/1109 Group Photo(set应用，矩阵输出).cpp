#include<iostream>
#include<vector>
#include<string>
#include<set>
using namespace std;
struct Node {
	string name;
	int height;
	bool operator <(const Node& a)const {
		return (height != a.height) ? height > a.height:name < a.name;
	}
};
set<Node>S;
void Print(int col)//打印出col个名字
{
	vector<string>V(col+1);
	int median = col / 2 + 1;
	auto it = S.begin();
	V[median] = it->name;
	S.erase(it);
	for (int i = 1;i<(col+1)/2; i++)
	{
		auto it = S.begin();
		V[median - i] = it->name;
		S.erase(it);
		auto ti = S.begin();
		V[median + i] = ti->name;
		S.erase(ti);
	}
	if (!(col % 2))
	{
		V[1] = S.begin()->name;
		S.erase(S.begin());
	}
	cout << V[1];
	for (int i = 2; i < V.size(); i++)
		cout <<" "<< V[i];
	cout << endl;
}
int main()
{
	int num, row,col;
	scanf("%d%d", &num, &row);
	col = num / row;
	string name;
	int height;
	for (int i = 0; i < num; i++)
	{
		cin >> name >> height;
		S.insert({ name,height });
	}//获得一个按身高降序名字升序的序列
	Print( num - (row - 1) * col);//打印最后一行
	for(int i=1;i<row;i++)Print(col);//打印前row-1行
	return 0;
}
/*
此题不一定非要用set进行排序，也可以使用sort进行排序
vector<Node>V;
sort(V.begin(),V.end(),cmp);

*/