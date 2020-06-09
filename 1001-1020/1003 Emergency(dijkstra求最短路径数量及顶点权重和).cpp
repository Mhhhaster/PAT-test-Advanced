#include<iostream>
#include<vector>
#define Uplimit 65535
using namespace std;
vector<int>resnum;
vector<vector<int>>G;

int main()
{
    int N, M, C1, C2;
    scanf("%d%d%d%d", &N, &M, &C1, &C2);
    int rescuenum;
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &rescuenum);
        resnum.push_back(rescuenum);
    }
    int c1, c2, length;
    G.resize(N, vector<int>(N, Uplimit));
    for (int i = 0; i < M; i++)
    {
        scanf("%d%d%d", &c1, &c2, &length);
        G[c1][c2] = length;
        G[c2][c1] = length;
    }
    for (int i = 0; i < N; i++)
        G[i][i] = 0;
    vector<bool>Visit(N, false);
    vector<int>num(N, 0);
    vector<int>Length(N, Uplimit);
    num[C1] = resnum[C1];
    vector<int>same(N, 1);
    for (int i = 0; i < N; i++)
    {
        if (G[C1][i] < Uplimit)//如果之间有路
        {
            Length[i] = G[C1][i];//更新距离与救援队数量
            if (i != C1)
                num[i] = resnum[C1] + resnum[i];
        }
    }
    Visit[C1] = true;
    while (1)
    {
        int position = -1;
        int min = Uplimit;
        for (int i = 0; i < N; i++)
        {
            if (!Visit[i])
                if (Length[i] < min)
                {
                    min = Length[i];
                    position = i;
                }
        }
        if (position == -1||position==C2)
            break;
        Visit[position] = true;
        for (int i = 0; i < N; i++)//对所有邻接点
        {
            if (position != i)//排除掉自身
            {
                if (G[position][i] + Length[position] < Length[i])//发现了到i的更短路径
                {
                    Length[i] = G[position][i] + Length[position];
                    num[i] = num[position] + resnum[i];
                    same[i] = same[position];
                }
                else if (G[position][i] + Length[position] == Length[i])//发现了长度相等的路径
                {
                    same[i] += same[position];
                    if (num[position] + resnum[i] > num[i])//发现可以更新救援队数量
                    {
                        num[i] = num[position] + resnum[i];
                    }
                }
            }
        }
    }
    printf("%d %d", same[C2], num[C2]);
    return 0;
}
/*
注意，当找到新的最短路径时，路径数量不是初始化为1，而是上一结点的路径数量
*/