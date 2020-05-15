#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
int times, mindepth = 100000, num = 1;//记录从零售商找到总生产者需要的次数
vector<int>a[100000];//建立十万个vector类型的容器，可按下标访问
void DFS(int node,int depth)//从a[0]开始dfs,记录当前结点和深度，深度的最小值为min
{
	if (a[node].size() == 0)//访问的节点为零售商
	{
		if (depth < mindepth)
		{
			mindepth = depth; num = 1;
		}
		else if (depth == mindepth)
			num++;
	}
	for (int i = 0; i < a[node].size(); i++)//dfs该节点的所有下家
		DFS(a[node][i], depth + 1);
}
int main()
{
	int N;
	double rawprice, incpercent;
	scanf("%d%lf%lf", &N, &rawprice, &incpercent);
	
	int downnum, temp;
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &downnum);//输入下家的数量
		while (downnum--)
		{
			scanf("%d", &temp);
			a[i].push_back(temp);
		}
	}//直接形成了一个类似不等列的二维数组结构
	DFS(0,0);
	printf("%.4lf %d", rawprice * pow(1 + incpercent / 100, mindepth), num);
	return 0;
}
//最大的收获是学会了使用vector<int>a[maxsize]的结构，相当于一个动态二维数组
//学会了DFS的标准思考方式，正常来说至少需要两个参数，当前访问节点和深度。
//本题还可以进行剪枝，如果当前深度已经大于mindepth了其实就没有意义不用做了

