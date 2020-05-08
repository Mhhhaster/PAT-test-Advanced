#include<iostream>
using namespace std;
int main()
{
    int N;
    scanf("%d", &N);
    double sum = 0.0;
    double temp;
    for (int i = 0; i < N; i++)
    {
        scanf("%lf", &temp);
        sum = sum + temp * (i + 1) * (N - i);//注意，此处用(i + 1) * (N - i)*temp会出错！！！
    }
    printf("%.2f", sum);
    return 0;
}