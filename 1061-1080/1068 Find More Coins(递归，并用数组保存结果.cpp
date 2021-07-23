#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
bool cmp(int a, int b) {
	return a > b;
}
vector<int>face;
vector<int>result;
int N;
vector<vector<int>>F;//指示该递归点是否已经调用过
bool Judge(int index, int need) //face[index]参不参与组合成need
{
	if (index <= 0 || need < 0)
		return 0;
	if (need == 0)
		return 1;
	if (need < face[index]) {
		F[index][need] = 0;
		return 0;
	}
	/*递归终止条件*/

	/*查看F[][]的值，若未初始化则更新*/
	if (F[index][need] != -1)
		return F[index][need];

	/*更新方式1：从该节点向下递归，并标记该节点能组合为need*/
	if (Judge(index - 1, need - face[index])) {
		F[index][need] = 1;
		result.push_back(face[index]);
		return true;
	}
	else//更新方式2：向该节点后递归，同时标记该结点不能组合为need
		F[index][need] = 0;
	return Judge(index - 1, need);
}
int main()
{
	int M;
	scanf("%d%d", &N, &M);
	F.resize(N + 1, vector<int>(M +1, -1));
	face.resize(N);
	for (int i = 0; i < N; i++)
		scanf("%d", &face[i]);
	sort(face.begin(), face.end(), cmp);
	if (Judge(N - 1, M)) {
		reverse(result.begin(), result.end());
		printf("%d", result[0]);
		for (int i = 1; i < result.size(); i++)
			printf(" %d", result[i]);
	}
	else
		printf("No Solution");
	return 0;
}
/*程序思想：
递归
从小数枚举到大数，Judge(index,need)判断组成need的序列中是否有face[index]
其结果显然与Judge(index-1,need-face[index])一致，若为真，则加入result；若为非，那么置0，index向前移位寻找更大的数
F用来保存递归结果，防止多次重复计算
该程序是如何保证结果为最小序列：
从最小的数开始加入，并且每次向后递归的位置靠后，因此加入的数一定是最小的
递归方式：1，2，3，4；1，2，4，5；1，2，4，6；....1，3，4，5；1，3，5
*/