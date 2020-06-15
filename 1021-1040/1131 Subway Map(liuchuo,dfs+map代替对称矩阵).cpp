#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
vector<vector<int>> v(10000);
int visit[10000], minCnt, minTransfer, start, end1;
unordered_map<int, int> line;
vector<int> path, tempPath;
int transferCnt(vector<int> a) {
    int cnt = -1, preLine = 0;
    for (int i = 1; i < a.size(); i++) {
        if (line[a[i - 1] * 10000 + a[i]] != preLine) cnt++;
        preLine = line[a[i - 1] * 10000 + a[i]];
    }
    return cnt;
}
void dfs(int node, int cnt) {
    tempPath.push_back(node);//注意所得path为start指向endl
    visit[node] = 1;
    if (node == end1)
    {
        if (cnt < minCnt || (cnt == minCnt && transferCnt(tempPath) < minTransfer)) {
            minCnt = cnt;
            minTransfer = transferCnt(tempPath);
            path = tempPath;
        }
    }
    else {
        for (int i = 0; i < v[node].size(); i++) {
            if (visit[v[node][i]] == 0) 
                dfs(v[node][i], cnt + 1);
        }
    }
    visit[node] = 0;
    tempPath.pop_back();
}
int main() {
    int n, m, k, pre, temp;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &m, &pre);
        for (int j = 1; j < m; j++) {
            scanf("%d", &temp);
            v[pre].push_back(temp);
            v[temp].push_back(pre);
            line[pre * 10000 + temp] = line[temp * 10000 + pre] = i + 1;//不同处：存储两站之间是几号线
            pre = temp;
        }
    }
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        scanf("%d%d", &start, &end1);
        minCnt = 99999, minTransfer = 99999;
        tempPath.clear();
        visit[start] = 1;
        dfs(start, 0);
        visit[start] = 0;
        printf("%d\n", minCnt);
        int preLine = 0, preTransfer = start;
        for (int j = 1; j < path.size(); j++) {
            if (line[path[j - 1] * 10000 + path[j]] != preLine) {
                if (preLine != 0)
                    printf("Take Line#%d from %04d to %04d.\n", preLine, preTransfer, path[j - 1]);
                preLine = line[path[j - 1] * 10000 + path[j]];
                preTransfer = path[j - 1];
            }
        }
        printf("Take Line#%d from %04d to %04d.\n", preLine, preTransfer, end1);
    }
    return 0;
}
/*
区别大的有两点，
1.liuchuo直接采用dfs获得start到endl的最短距离(更适合等距离)，而我采用dijkstra+dfs
各结点访问时先入队+visit，退出时再pop+unvisit,这样做可以防止进入循环
2.存储每条边的归属信息，而不是每个站点的归属信息，合理利用了题目所给
对于查看是否换乘就相当简单了
此外，存储每条边用的是图而不是一个二维矩阵，或者是邻接表*/