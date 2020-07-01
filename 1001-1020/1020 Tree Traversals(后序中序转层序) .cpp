#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int post[40], in[40];
int son[100000][2];//指示左右孩子
vector<int>result;
int BuildTree(int postleft, int inleft, int N)//通过两个数组建立树
{
    if (N < 1)
        return -1;
    if (N == 1)
        return post[postleft];
    int temproot = post[postleft + N - 1];
    int pos = inleft, count = 0;
    for (int temppos = inleft; count < N; temppos++) {
        count++;
        if (in[temppos] == temproot) {
            pos = temppos;
            break;
        }
    }
    int leftlength = pos - inleft;
    son[temproot][0] = BuildTree(postleft, inleft, leftlength);
    son[temproot][1] = BuildTree(postleft + leftlength, inleft + 1 + leftlength, N - 1 - leftlength);
    return temproot;
}
void levelTraversal(int Root)
{
    queue<int>Q;
    Q.push(Root);
    while (!Q.empty()) {
        int root = Q.front();
        result.push_back(root);
        Q.pop();
        int left = son[root][0];
        int right = son[root][1];
        if (left != -1)Q.push(left);
        if (right != -1)Q.push(right);
    }
}
int main()
{
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", &post[i]);
    for (int i = 0; i < N; i++)
        scanf("%d", &in[i]);
    fill(son[0], son[0] + 100000 * 2, -1);
    BuildTree(0, 0, N);
    levelTraversal(post[N - 1]);
    printf("%d", result[0]);
    for (int i = 1; i < result.size(); i++)
        printf(" %d", result[i]);
    return 0;
}
/*注意fill函数初始化二维数组的方法：algorithm头文件，数组名需要带上[0]
本题坑在没有告诉你结点名称是由1拍到N-1，没关系，数组取大一点就好
或者说使用键值对

liuchuo：采用后序遍历+中序遍历转先序遍历的思路，每次找到根节点进行递归时，当前根节点以及它的index压入结果数组，然后index加一*/