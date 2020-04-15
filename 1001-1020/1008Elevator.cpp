#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
int main()
{
    int pf=0;//记录当前楼层数
    int N;//输入总数
    int sum=0;//需要的时间
    int temp;//楼层
    scanf("%d",&N);
    while(N--)
    {
        scanf("%d",&temp);
        sum+=(temp>pf?(temp-pf)*6:(pf-temp)*4);
        sum+=5;
        pf=temp;
    }
    printf("%d",sum);
    return 0;
}