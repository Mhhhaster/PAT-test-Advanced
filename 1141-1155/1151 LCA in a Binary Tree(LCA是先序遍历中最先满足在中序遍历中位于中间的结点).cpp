#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int main()
{
    int N, M;
    scanf("%d%d", &N, &M);
    unordered_map<int, int>inpos;
    vector<int>in(M + 1);
    vector<int>pre(M + 1);
    for (int i = 1; i <= M; i++) {
        scanf("%d", &in[i]);
        inpos[in[i]] = i;
    }
    for (int i = 1; i <= M; i++)
        scanf("%d", &pre[i]);
    int u, v;
    for (int i = 0; i < N; i++) {
        scanf("%d%d", &u, &v);
        int posu = inpos[u];
        int posv = inpos[v];
        if (posu == 0 || posv == 0) {//说明有一个找不到
            if (posv == posu)
                printf("ERROR: %d and %d are not found.\n", u, v);
            else
                printf("ERROR: %d is not found.\n", posu == 0 ? u : v);
        }
        else {
            int a = -1;
            for (int i = 1; i <= M; i++) {
                a = inpos[pre[i]];//遍历一遍pre数组
                if ((a <= posv && a >= posu) || (a <= posu && a >= posv))
                    break;
            }
            if (a == posu || a == posv)
                printf("%d is an ancestor of %d.\n", in[a], a == posv ? u : v);
            else
                printf("LCA of %d and %d is %d.\n", u, v, in[a]);
        }
    }
}