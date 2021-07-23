#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<unordered_map>
using namespace std;
void Print(set<int>M)
{
	if (M.empty())
		printf("Not Found\n");
	else
		for (auto it : M)
			printf("%07d\n", it);
}
int main()
{
	unordered_map<string, set<int>>title, author, keyword, publisher,year;
	int N;
	scanf("%d", &N);
	int id; 
	string temptitle, tempauthor, tempkeyword, temppublisher, tempyear;
	for (int i = 0; i < N; i++) {
		scanf("%d", &id);
		getchar();
		getline(cin, temptitle); title[temptitle].insert(id);
		getline(cin, tempauthor); author[tempauthor].insert(id);
		getline(cin, tempkeyword);
		string temp;
		for (int j = 0; j < tempkeyword.length(); j++) {
			if (tempkeyword[j] != 32)
				temp += tempkeyword[j];
			if(tempkeyword[j]==32|| j == tempkeyword.length() - 1) {
				keyword[temp].insert(id);
				temp.clear();
			}
		}
		getline(cin, temppublisher); publisher[temppublisher].insert(id);
		cin >> tempyear; year[tempyear].insert(id);
	}
	int querynum, type;
	string search;
	scanf("%d", &querynum);
	for (int i = 1; i <= querynum; i++) {
		scanf("%d: ", &type);
		getline(cin,search);
		printf("%d: %s\n", type, search.c_str());
		if (type == 1)
			Print(title[search]);
		else if (type == 2)
			Print(author[search]);
		else if (type == 3)
			Print(keyword[search]);
		else if (type == 4)
			Print(publisher[search]);
		else
			Print(year[search]);
	}
	return 0;
}