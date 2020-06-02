#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
int n, k;
const int inf = 999999999;
int e[205][205], weight[205], dis[205];
bool visit[205];
vector<int> pre[205], temppath, path;
map<string, int> m;
map<int, string> m2;
int maxvalue = 0, mindepth, cntpath = 0;
double maxavg;
void dfs(int v) {//对每个结点，递归它的上一个结点
    temppath.push_back(v);//临时路径，倒着走
    if (v == 1) {//找到起点了
        int value = 0;
        for (int i = 0; i < temppath.size(); i++) {
            value += weight[temppath[i]];
        }
        double tempavg = 1.0 * value / (temppath.size() - 1);
        if (value > maxvalue) {//如果当前的路径要更happy，就更新
            maxvalue = value;
            maxavg = tempavg;
            path = temppath;//temppath转正
        }
        else if (value == maxvalue && tempavg > maxavg) {
            maxavg = tempavg;
            path = temppath;
        }
        temppath.pop_back();
        cntpath++;
        return;
    }
    for (int i = 0; i < pre[v].size(); i++) {
        dfs(pre[v][i]);//对每一个上一步结点递归
    }
    temppath.pop_back();//这个结点所有的上一步结点都递归完之后，这个结点也出栈
}
int main() {
    fill(e[0], e[0] + 205 * 205, inf); fill(dis, dis + 205, inf);
    scanf("%d %d", &n, &k);
    string s;
    cin >> s;
    m[s] = 1;
    m2[1] = s;
    for (int i = 1; i < n; i++) {
        cin >> s >> weight[i + 1];
        m[s] = i + 1;
        m2[i + 1] = s;
    }
    string sa, sb;
    int temp;
    for (int i = 0; i < k; i++) {
        cin >> sa >> sb >> temp;
        e[m[sa]][m[sb]] = temp;
        e[m[sb]][m[sa]] = temp;
    }
    /*以上输入存储和我一样*/
    dis[1] = 0;
    for (int i = 0; i < n; i++) {
        int u = -1, minn = inf;
        for (int j = 1; j <= n; j++) {
            if (visit[j] == false && dis[j] < minn) {
                u = j;
                minn = dis[j];
            }
        }//相当于findmin
        if (u == -1) break;
        visit[u] = true;
        for (int v = 1; v <= n; v++) {
            if (visit[v] == false && e[u][v] != inf) {
                if (dis[u] + e[u][v] < dis[v]) {
                    dis[v] = dis[u] + e[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                }
                else if (dis[v] == dis[u] + e[u][v]) {
                    pre[v].push_back(u);
                }
            }
        }
    }//仅仅只是把pre[v]中存储所有最短路径中上一步结点(可以通过递归找到所有最短路径的路线)
    int rom = m["ROM"];
    dfs(rom);
    printf("%d %d %d %d\n", cntpath, dis[rom], maxvalue, (int)maxavg);
    for (int i = path.size() - 1; i >= 1; i--) {
        cout << m2[path[i]] << "->";
    }
    cout << "ROM";
    return 0;
}
/*
dijkstra+dfs
避免了在dijkstra内部进行大规模的判定与更新，直接通过dijkstra得到路径图，路径图就可以存储所有路径信息
所以我还是不知道自己的程序到底哪个部分出了问题
*/