#include<iostream>
#include<vector>
using namespace std;
vector<int>V[100001];
void Judge()
{
	int k;
	scanf("%d", &k);
	vector<int>input(k);
	for (int j = 0; j < k; j++)
		scanf("%d", &input[j]);
	for (int j = 0; j < k - 1; j++)
		for (int p = j + 1; p < k; p++) {
			for (int m = 0; m < V[input[j]].size(); m++)
				if (V[input[j]][m] == input[p]) {//找到了危险
					printf("No\n");
					return;
				}
		}
	printf("Yes\n");
	return;
}
int main()
{
	int pairnum, testnum, stuff1, stuff2;
	scanf("%d%d", &pairnum, &testnum);
	for (int i = 0; i < pairnum; i++) {
		scanf("%d%d", &stuff1, &stuff2);
		V[stuff1].push_back(stuff2);
		V[stuff2].push_back(stuff1);
	}
	for (int i = 0; i < testnum; i++)
		Judge();
	return 0;
}
/*事实证明
简单的数组使用在效率上是明显更快的
虽然浪费了更多的空间，但确实是解决程序超时的好方法
又是经典的二维vector数组简化问题
又是手工遍历代替stl函数*/