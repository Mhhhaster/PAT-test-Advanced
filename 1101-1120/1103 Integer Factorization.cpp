#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int n, k, p, maxFacSum = -1;//把N个数分解成K个数的p次方
vector<int> v, ans, tempAns;
void init() {
    int temp = 0, index = 1;
    while (temp <= n) {
        v.push_back(temp);
        temp = pow(index, p);
        index++;
    }
}//v:0,1,4,9.....
void dfs(int index, int tempSum, int tempK, int facSum) {//最直观的解法，对K个数的所有情况都遍历一次，记录总和，如果相等就存储答案
    if (tempK == k) {//
        if (tempSum == n && facSum > maxFacSum) {
            ans = tempAns;
            maxFacSum = facSum;
        }
        return;
    }
    for (; index >= 1;index--) {//index为加入的下一个底数，从最大开始递减
        if (tempSum + v[index] <= n) {
            tempAns[tempK] = index;
            dfs(index, tempSum + v[index], tempK + 1, facSum + index);
        }
        if (index == 1) return;//index不能为0
    }
}
int main() {
    scanf("%d%d%d", &n, &k, &p);
    init();
    tempAns.resize(k);//初始化tempAns的长度，因为不能用push，只能改变值
    dfs(v.size() - 1, 0, 0, 0);
    if (maxFacSum == -1) {
        printf("Impossible");
        return 0;
    }
    printf("%d = ", n);
    for (int i = 0; i < ans.size(); i++) {
        if (i != 0) printf(" + ");
        printf("%d^%d", ans[i], p);
    }
    return 0;
}