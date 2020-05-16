#include<iostream>
#include<vector>
#define Uplimit 1000
using namespace std;
vector<vector<int>>G;
int main()
{
	int vertexnum, edgenum;
	scanf("%d%d", &vertexnum, &edgenum);
	G.resize(vertexnum+1);//0到vertexnum行
	for (int i = 1; i <= vertexnum; i++)
		G[i].resize(vertexnum + 1,Uplimit);//对每一行初始化0到vertexnum列
	int row, col;
	while (edgenum--)
	{
		scanf("%d%d", &row, &col);
		G[row][col] = 1;
		G[col][row] = 1;
	}
	int testnum,cyclenum;
	scanf("%d", &testnum);
	while (testnum--)
	{
		bool flag = true;//标志，是否满足条件
		scanf("%d", &cyclenum);
		vector<int>cycle(cyclenum+1);
		vector<bool>pre(vertexnum+1,false);
		for (int i = 1; i <= cyclenum; i++)
		{
			scanf("%d", &cycle[i]);
			pre[cycle[i]] = true;//是否出现了的标志
		}
		//需要满足四个条件，首尾相等，N+1个顶点，路通，所有顶点都出现
		if (cyclenum != vertexnum + 1)
			flag = false;
		else if (cycle[1] != cycle[cyclenum])
			flag = false;
		else
		{
			for (int i = 1; i <= vertexnum; i++)
				if (pre[i] == false)
					flag = false;
		}
		if (flag)//最后再判断一下是否路通
		{
			int pathlength = 0;
			for (int i = 1; i < cyclenum; i++)
				pathlength += G[cycle[i]][cycle[i + 1]];
			if (pathlength > Uplimit)
				flag = false;
		}
		if (flag)printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
//没什么难度，练习一下二维向量的使用方法