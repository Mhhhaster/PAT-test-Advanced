#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Node {
    int num;
    double sumprice;
};
bool cmp(Node a, Node b)
{
    return a.sumprice / a.num < b.sumprice / b.num;
}
int main()
{
    int N, D;
    scanf("%d%d", &N, &D);
    double profit = 0.0;
    vector<Node>type(N);
    for (int i = 0; i < N; i++)
        scanf("%d", &type[i].num);
    for (int i = 0; i < N; i++) 
        scanf("%lf",&type[i].sumprice);
    sort(type.begin(), type.end(), cmp);
    /*目前单价最贵的都在后面，优先选择*/
    while (D) {
        int number = type[type.size() - 1].num;
        if (number < D) {
            D -= number;
            profit += type[type.size() - 1].sumprice;
            type.pop_back();
        }
        else {
            profit += type[type.size() - 1].sumprice * (D*1.0 / type[type.size() - 1].num);
            D = 0;
        }
    }
    printf("%.2lf", profit);
    return 0;
}
/*
3 200
180 150 100
7.5 7.2 4.5

9.45*/