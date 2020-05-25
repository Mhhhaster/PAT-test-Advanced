#include <iostream>
#include<string>
using namespace std;
struct node {
    int l, r;
}a[100];
int maxn = -1, ans;
void dfs(int root, int index) {
    if (index > maxn) {
        maxn = index;
        ans = root;
    }
    if (a[root].l != -1) dfs(a[root].l, index * 2);
    if (a[root].r != -1) dfs(a[root].r, index * 2 + 1);
}
int main() {
    int n, root = 0, have[100] = { 0 };
    cin >> n;
    for (int i = 0; i < n; i++) {
        string l, r;
        cin >> l >> r;
        if (l == "-") {
            a[i].l = -1;
        }
        else {
            a[i].l = stoi(l);
            have[stoi(l)] = 1;
        }
        if (r == "-") {
            a[i].r = -1;
        }
        else {
            a[i].r = stoi(r);
            have[stoi(r)] = 1;
        }
    }
    while (have[root] != 0) root++;
    dfs(root, 1);
    if (maxn == n)
        cout << "YES " << ans;
    else
        cout << "NO " << root;
    return 0;
}
/*本题采用dfs的方式检查树是否为完全二叉树，方法如下：
每次递归记录根节点和根节点的index，
index的更新方式为：根节点为0或1，左子树2*i，右子树2*i+1
index的最大值就是二叉树的最深最右结点，如果与结点数相等，那么为完全二叉树
与之前的方法(如果一个结点缺少子树，那么它后面的结点全都没有子树)相比，判断条件更加简单
不存在需要对异常输入进行判断
*/