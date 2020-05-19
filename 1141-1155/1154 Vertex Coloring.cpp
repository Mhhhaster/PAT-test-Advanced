#include<iostream>
#include<vector>
#include<set>
using namespace std;
#define Max 10005
int main()
{
    int vertexnum, edgenum;
    scanf("%d%d", &vertexnum, &edgenum);
    vector<int>G[Max];//二维,G[i]存储i的所有邻接点
    vector<int>Color(vertexnum);
    int node1, node2;
    for (int i = 0; i < edgenum; i++)
    {
        scanf("%d%d", &node1, &node2);
        G[node1].push_back(node2);
        G[node2].push_back(node1);
    }
    //枚举所有边，保证它的邻接点和它不共色
    int testnum;
    scanf("%d", &testnum);
    while (testnum--)
    {
        bool flag = true;//是否正确着色的标志
        int max = 0;
        set<int>S;
        for (int i = 0; i < vertexnum; i++)
        {
            scanf("%d", &Color[i]); 
            auto it = S.find(Color[i]);
            if (it == S.end())//没有找到
            {
                max++;
                S.insert(Color[i]);
            }
        }
        for (int i = 0; i < vertexnum; i++)
            for (int j = 0; j < G[i].size(); j++)
                if (Color[i] == Color[G[i][j]])
                    flag = false;
        if (!flag)
        {
            printf("No\n");
            continue;
        }
        printf("%d-coloring\n", max);
    }
}
/*注意到本题我们需要统计出现了多少个不同的数，由于范围较大，我们可以使用hash函数进行存储和查找工作，也可以使用
set集合，直接存入，用find来查找(set应用：排序，存储，查找)*/