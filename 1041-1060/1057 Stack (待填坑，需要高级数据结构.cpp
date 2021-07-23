#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	int N;
	scanf("%d", &N);
	string op;
	vector<int>S;
	for (int i = 0; i < N; i++) {
		cin >> op;
		if (op[1] == 'o') {//pop
			if (S.size() == 0)
				printf("Invalid\n");
			else {
				printf("%d\n", S[S.size() - 1]);
				S.pop_back();
			}
		}
		else if (op[1] == 'e') {//peek
			if (S.size() == 0)
				printf("Invalid\n");
			else {
				vector<int>temp = S;
				sort(temp.begin(), temp.end());
				printf("%d\n", temp[(temp.size() - 1) / 2]);
			}
		}
		else {
			int temp;
			scanf("%d", &temp);
			S.push_back(temp);
		}
	}
}