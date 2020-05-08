#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
int dis[100000];
void Print(int a, int b,int N)
{
    int Cdis = 0;
    int Rdis = 0;
    int start, end;
    if (a > b)
    {
        start = b - 1;
        end = a - 1;
    }
    else
    {
        start = a - 1;
        end = b - 1;
    }
    for (int i = start; i < end; i++)
        Cdis += dis[i];
    for (int i = 0; i < start; i++)
        Rdis += dis[i];
    for (int i = end; i < N; i++)
        Rdis += dis[i];
    if (Cdis > Rdis)
        printf("%d\n", Rdis);
    else
        printf("%d\n", Cdis);
    return;
}
int main()
{
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", &dis[i]);
    int M;
    scanf("%d", &M);
    int exit1, exit2;
    while (M--)
    {
        scanf("%d%d", &exit1, &exit2);
        Print(exit1, exit2,N);
    }
    return 0;
}