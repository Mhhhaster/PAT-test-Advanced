#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int N;
    scanf("%d", &N);
    vector<int>a(N);
    int max = 0;
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &a[i]);
        if (a[i] > max)
            max = a[i];
    }
    vector<int>result(max);
    for (int i = 1; i < max; i++)
    {
        int biggernum = 0;
        for (int j = 0; j < N; j++)
            if (a[j] > i)
                biggernum++;
        result[i] = biggernum;//result存储大于i的天数
    }
    int i;
    for (i = 1; i < max; i++)//result[i]减小，i增大，找到最大i保证relust[i]>=i
        if (result[i] < i)//不满足条件了
            break;
    printf("%d", i-1);
}