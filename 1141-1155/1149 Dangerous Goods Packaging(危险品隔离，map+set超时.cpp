#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
using namespace std;
struct Node {
	unordered_set<int>S;
};
vector<Node>V(2001);
unordered_map<int, int>M;
void Judge()
{
	int k;
	scanf("%d", &k);
	vector<int>input(k);
	for (int j = 0; j < k; j++)
		scanf("%d", &input[j]);
	for (int j = 0; j < k - 1; j++)
		for (int p = j + 1; p < k; p++) {
			if (V[M[input[j]]].S.find(M[input[p]]) != V[M[input[j]]].S.end()) {//找到了危险
				printf("No\n");
				return;
			}
		}
	printf("Yes\n");
	return;
}
int main()
{
	int pairnum, testnum, stuff1, stuff2, count = 1;
	scanf("%d%d", &pairnum, &testnum);
	for (int i = 0; i < pairnum; i++) {
		scanf("%d%d", &stuff1, &stuff2);
		if (M[stuff1] == 0)
			M[stuff1] = count++;
		if (M[stuff2] == 0)
			M[stuff2] = count++;
		V[M[stuff1]].S.insert(M[stuff2]);
		V[M[stuff2]].S.insert(M[stuff1]);
	}
	for (int i = 0; i < testnum; i++) 
		Judge();
	return 0;
}
/*6 3
20001 20002
20003 20004
20005 20006
20003 20001
20005 20004
20004 20006
4 00001 20004 00002 20003
5 98823 20002 20003 20006 10010
3 12345 67890 23333*/