#include<iostream>
#include<vector>
using namespace std;
void solve(int N, int P, int K, int sum, int level);
int maxsum = 0;
vector<int>a;
vector<int>b;
double times = 0;
int main()//递归解决
{
    int N, P, K;
    scanf("%d%d%d", &N, &P, &K);//数字N分解为P个K次方的数之和
    a.resize(P);//为a和b分配大小
    b.resize(P);//b为结果数组
    solve(N, P, K, 0, 0);
    if (maxsum == 0)
        printf("Impossible");
    else
    {
        printf("%d = ", N); //169 = 6 ^ 2 + 6 ^ 2 + 6 ^ 2 + 6 ^ 2 + 5 ^ 2
        printf("%d^%d", b[0], K);
        for (int i = 1; i < P; i++)
            printf(" + %d^%d", b[i], K);
    }
    printf("\n%lf\n", times);
    return 0;
}
int pow(int a, int b)
{
    while (--b)
        a *= a;
    return a;
}
void solve(int N, int P, int K, int sum, int level)//数字N分解为P个K次方的数之和,sum为当前的和,level记录层数
{//递归终止条件：P=1;N<=0;P>N
    times++;
    if (N <= 0)
        return;
    int i;
    for (i = 1;; i++)
        if (pow(i, K) > N)//找到最大的factor,169的最大factor为13，168为14
            break;
    if (P == 1)//数字N分解为1个数
    {
        if (pow(i - 1, K) == N)//分解成功的终止条件
        {
            if (i - 1 + sum > maxsum)
            {
                maxsum = i - 1 + sum;//更新最小factor和
                for (int k = 0; k < level; k++)
                {
                    b[k] = a[k];
                }
                b[level] = i - 1;
            }
        }
        return;
    }
    int j;
    if (level)//每个数要比上一层的数小或者相等
        j = i - 1 > a[level - 1] ? a[level - 1] : i - 1;
    else
        j = i - 1;
    for (; j >= 1; j--)
    {
        a[level] = j;//第level层的数为j
        if (N - pow(j, K) >= P - 1)
            solve(N - pow(j, K), P - 1, K, sum + j, level + 1);//递归为数字N'分解为P-1个K次方的数之和,由大至小方便满足最大因子
    }
}
/*K=2时跑得很慢
结论：采用临时数组和结果数组的思路很好。
两种方法：1.对于P个底数都从N开K次方根到1遍历一遍，类似于循环
2.递归为一个更小规模的问题
递归次数已经少了很多但还是用时多
*/