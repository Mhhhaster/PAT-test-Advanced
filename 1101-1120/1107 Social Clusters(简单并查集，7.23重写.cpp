#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>hobby[1001];
vector<int>F;
int FindRoot(int i)
{
	if (F[i] > 0)
		return F[i]=FindRoot(F[i]);
	else
		return i;
}
void Union(int i, int j)//将这两个集合合并
{
	int R1 = FindRoot(i);
	int R2 = FindRoot(j);
	if (F[R1] < F[R2]) {
		F[R1] += F[R2];
		F[R2] = R1;
	}
	else {
		F[R2] += F[R1];
		F[R1] = R2;		
	}
}
int main()
{
	int N, K, temp;
	scanf("%d", &N);
	F.resize(N + 1, -1);
	for (int i = 1; i <= N; i++) {
		scanf("%d:", &K);
		for (int j = 0; j < K; j++) {
			scanf("%d", &temp);
			hobby[temp].push_back(i);
		}
	}
	for (int i = 1; i <= 1000; i++) {
		if (hobby[i].size()>=2) {
			int temp1 = hobby[i][0];
			for (int j = 1; j < hobby[i].size(); j++) {
				Union(temp1, hobby[i][j]);
				temp1 = hobby[i][j];
			}
		}
	}
	int setcount = 0;
	for (int i = 1; i <= N; i++)
		if (F[i] < 0)
			setcount++;
	printf("%d\n", setcount);
	sort(F.begin(), F.end());
	printf("%d", -F[0]);
	for (int i = 1; i < setcount; i++)
		printf(" %d", -F[i]);
	return 0;
}
/*8
3: 2 7 10
1: 4
2: 5 3
1: 4
1: 3
1: 4
4: 6 8 1 5
1: 4

Sample Output:

3
4 3 1*/