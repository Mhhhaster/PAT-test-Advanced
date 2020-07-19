#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
int T[2047];
void Insert(int data, int index)
{
	if (T[index] == 0)
		T[index] = data;
	else {
		if (abs(T[index]) < abs(data))
			Insert(data, index * 2 + 2);
		else
			Insert(data, index * 2 + 1);
	}
	return;
}
int Countblack(int index)//统计该节点出发到叶子结点的路径经过的黑节点的个数，如果相同则返回，不同则返回-999
{
	if (T[index] == 0)
		return 0;
	int leftnode = Countblack(index * 2 + 1);
	int rightnode = Countblack(index * 2 + 2);
	if (T[index] > 0)
		return leftnode == rightnode ? leftnode + 1 : -999;
	if(T[index]<0)
		return leftnode == rightnode ? leftnode : -999;
}
void Judge()
{
	int N, temp;
	fill(T, T + 2047, 0);
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &temp);
		Insert(temp, 0);
	}
	if (T[0] <= 0) {
		printf("No\n");
		return;
	}
	for(int i=0;i<2047;i++)
		if(T[i]<0)
			if (T[i * 2 + 2] < 0 || T[i * 2 + 1] < 0) {
				printf("No\n");
				return;
			}
	if (Countblack(0) <0) {
		printf("No\n");
		return;
	}
	printf("Yes\n");
	return;
}
int main()
{
	int testnum;
	scanf("%d", &testnum);
	for (int i = 0; i < testnum; i++)
		Judge();
	return 0;
}
/*简单的数组表示，可以看出pat有意卡了数据
本题重点在于采用递归思路解决路径问题*/