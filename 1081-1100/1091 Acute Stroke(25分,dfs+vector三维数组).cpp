#include<iostream>
#include<vector>
using namespace std;
vector<vector<vector<bool>>>Visit, V;
int tempv;
int M, N, L, T;
void dfs(int i, int j, int k)
{
	Visit[i][j][k] = true;
	tempv++;//tempv每进行一次dfs就加一，当dfs全部结束时，相当于是存储的联通体积
	if (i>0)
		if(V[i - 1][j][k] )
			if( Visit[i - 1][j][k] == false)
				dfs(i - 1, j, k);//如果i不是第0层且它的上一层有问题还没有遍历
	if (i < L - 1 )
		if(V[i + 1][j][k] )
			if (Visit[i + 1][j][k] == false)
				dfs(i + 1, j, k);//不是最后一层
	if (j>0)
		if( V[i][j - 1][k] )
			if( Visit[i][j - 1][k] == false)
				dfs(i, j - 1, k);//不是第0行
	if (j < N - 1 )
		if(V[i][j + 1][k] )
			if( Visit[i][j + 1][k] == false)
				dfs(i, j + 1, k);//不是最后一行
	if (k>0)
		if(V[i][j][k - 1] )
			if( Visit[i][j][k - 1] == false)	
				dfs(i, j, k - 1);//不是第0列
	if (k <M - 1 )
		if( V[i][j][k + 1] )
			if(Visit[i][j][k+1] == false)
				dfs(i, j, k + 1);//不是最后一列
}
int main()
{
	scanf("%d%d%d%d", &N, &M, &L, &T);
	Visit.resize(L);//总共L层
	V.resize(L);
	for (int i = 0; i < L; i++)
	{
		Visit[i].resize(N, vector<bool>(M, false));//每层有N行，M列，全部初始化为false;
		V[i].resize(N, vector<bool>(M, false));
	}
	bool temp;
	for (int i = 0; i < L; i++)//i指示层数，相等于z
		for (int j = 0; j < N; j++)//j指示行数，相当于x
			for (int k = 0; k < M; k++)//k指示列数，相当于y
			{
				cin >> temp;
				V[i][j][k] = temp;
			}//至此完成存储任务
	int volume = 0;
	for (int i = 0; i < L; i++)
		for (int j = 0; j < N; j++)
			for (int k = 0; k < M; k++)//相当于遍历图的全部连通集
				if (Visit[i][j][k] == false && V[i][j][k])//如果这个像素还没有被遍历并且不正常
				{
					tempv = 0;
					dfs(i, j, k);//深度优先搜索，计算它所联通的像素数
					if(tempv>=T)
					volume += tempv;
				}
	printf("%d", volume);
}
//感觉自己写的程序越来越优美了。。。错觉一定是