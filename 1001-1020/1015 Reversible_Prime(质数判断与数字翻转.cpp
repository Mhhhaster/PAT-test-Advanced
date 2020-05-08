#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<queue>
#include<stack>
using namespace std;
int GetreN(int N, int D);
bool Judge(int N);
int main()
{
    int N, D, reN;
    scanf("%d", &N);
    while (N > 0)
    {
        scanf("%d", &D);
        reN = GetreN(N, D);//转换进制并reverse、
        if (Judge(N) && Judge(reN))
            printf("Yes\n");
        else
            printf("No\n");
        scanf("%d", &N);
    }
    return 0;
}
int GetreN(int N, int D)
{
    stack<int>Q;
    while (N > 0)
    {
        Q.push(N % D);
        N /= D;
    }
    int sum = 0;
    int weight = 1;
    while (!Q.empty())
    {
        sum += Q.top() * weight;
        Q.pop();
        weight *= D;
    }
    return sum;
}
bool Judge(int N)
{
    if (N == 1)
        return true;
    for (int i = 2; i * i <= N; i++)
    {
        if (N % i == 0)//非质数
            return false;
    }
    return true;
}