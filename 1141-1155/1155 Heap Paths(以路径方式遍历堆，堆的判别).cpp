#include<iostream>
#include<vector>
using namespace std;
int N;
int flag;
vector<int>heap;
vector<int>temppath;
void Printpath()
{
	printf("%d", heap[temppath[0]]);
	for (int i = 1; i < temppath.size(); i++) {
		printf(" %d", heap[temppath[i]]);
		if (flag == 1 && heap[temppath[i]] > heap[temppath[i - 1]])
			flag = 0;
		if (flag == -1 && heap[temppath[i]] < heap[temppath[i - 1]])
			flag = 0;
	}
	printf("\n");
}
void Print(int index)
{
	temppath.push_back(index);
	if (index * 2 + 1 >= N) {//左子树已经超出范围了，这是个叶子节点
		Printpath();
	}
	else{
		if (index * 2 + 2 < N)
			Print(index * 2 + 2);
		Print(index * 2 + 1);
	}
	temppath.pop_back();
}
void Solve()
{
	if (heap[1] > heap[0])
		flag = -1;
	if (heap[1] < heap[0])
		flag = 1;
	Print(0);
	if(flag==1)
		printf("Max Heap\n");
	if (flag == -1)
		printf("Min Heap\n");
	if (flag == 0)
		printf("Not Heap\n");
	return;
}
int main()
{
	scanf("%d", &N);
	heap.resize(N);
	for (int i = 0; i < N; i++)
		scanf("%d", &heap[i]);
	Solve();
}
/*
liuchuo判别堆类别的方式还是遍历每个结点与它的父亲比较，其实都没什么太大区别
本题类似于dijkstra算法，得到路径的二维数组然后dfs及回溯
注意pop的位置*/