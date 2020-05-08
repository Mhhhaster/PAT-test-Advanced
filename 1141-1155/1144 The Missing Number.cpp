//输出未出现的最小正整数
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
int main()
{
    int N;
    scanf("%d",&N);
    bool a[100001];//下标0~100000
    for(int i=1;i<100001;i++)
    a[i]=true;
    int temp;
    for(int i=0;i<N;i++)//N次输入
    {
        scanf("%d",&temp);
        if(temp>0&&temp<=100000)
        a[temp]=false;
    }
    for(int i=1;i<100001;i++)
    {
        if(a[i]!=false)
        {printf("%d",i);
        return 0;}
      if(i==100000)
      {
        printf("100001");
        return 0;
      }
    }
}