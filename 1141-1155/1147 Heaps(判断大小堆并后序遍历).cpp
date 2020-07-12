#include<iostream>
#include<vector>
using namespace std;
int N, M;
vector<int>heap;
bool flag = true;
void posttraverse(int index)
{
	if (index >= M)
		return;
	posttraverse(index * 2 + 1);
	posttraverse(index * 2 + 2);
	if (flag) {
		printf("%d", heap[index]);
		flag = false;
	}
	else
		printf(" %d", heap[index]);
}
void Judge()
{
	flag = true;
	for (int i = 0; i < M; i++)
		scanf("%d", &heap[i]);
	int flag=0;//1为大顶堆，-1为小顶堆，0不是堆
	if (heap[1] > heap[0]) {
		flag = -1;
		for(int i=2;i<M;i++)
			if (heap[i] < heap[(i - 1) / 2]) {
				flag = 0;
				break;
			}
	}
	if (heap[1] < heap[0]) {
		flag = 1;
		for (int i = 2; i < M; i++)
			if (heap[i] > heap[(i - 1) / 2]) {
				flag = 0;
				break;
			}
	}
	if (flag == 1)
		printf("Max Heap\n");
	else if (flag == -1)
		printf("Min Heap\n");
	else
		printf("Not Heap\n");
	posttraverse(0);
	printf("\n");
}
int main()
{
	scanf("%d%d", &N, &M);
	heap.resize(M);
	for (int i = 0; i < N; i++)
		Judge();
}
/*liuchuo几乎和我一样的程序，都是采用先判断前两个结点的大小关系暂时判别堆的种类*/