#include<iostream>
#include<vector>
#define uplimit 10000
using namespace std;    
bool component = true;
vector<bool>visit;
vector<vector<int>>G;
void DFS(int index )//从下标为1的顶点开始遍历，每次递归到i的所有没有访问过的邻接点
{
    visit[index] = true;
    for (int i = 1; i < visit.size(); i++)
        if (G[index][i] == 1&&visit[i]==false)
            DFS(i);
}
int main()
{
    int vertexnum, edgenum;
    scanf("%d%d", &vertexnum, &edgenum);
    G.resize(vertexnum + 1, vector<int>(vertexnum + 1,uplimit));
    int row, col;
    visit.resize(vertexnum + 1,false);
    while (edgenum--)
    {
        scanf("%d%d", &row, &col);
        G[row][col] = 1;
        G[col][row] = 1;
    }
    vector<int>D(vertexnum + 1,0);
    for (int i = 1; i <= vertexnum; i++)
    {
        for (int j = 1; j <= vertexnum; j++)
            if (G[i][j] == 1)//说明i到j有路径
                D[i]++;
    }
    int oddnum = 0;
    for (int i = 1; i <= vertexnum; i++)
    {
        printf("%d", D[i]);
        if (D[i] % 2 == 1)
            oddnum++;
        if (i != vertexnum)
            printf(" ");
        /* if (D[i] == 0)
             component = false;
     以上程序答案不全对，因为图的连通性不能只凭是否有节点的度为0判断，可能两两相连之类，要用dfs判断连通性*/
    }
    
    DFS(1);
    for (int i = 1; i <= vertexnum; i++)
        if (visit[i] == false)//只要有一个节点没有被访问过就说明图不连通
            component = false;
    if (oddnum == 0&&component==true)
        printf("\nEulerian");
    else if (oddnum == 2&&component==true)
        printf("\nSemi-Eulerian");
    else
        printf("\nNon-Eulerian");
    return 0;
}