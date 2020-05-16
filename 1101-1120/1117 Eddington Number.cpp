#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int a[100000];
int main()
{
    int n, e = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    sort(a, a + n, greater<int>());//降序
    while (e < n && a[e] > e + 1) e++;//e天数递增，a[e]公里数递减。骑车天数要小于骑车公里数
    printf("%d", e);
    return 0;
}
/*10
6 7 6 9 3 10 8 2 7 8*/
//输出最大的E保证有至少有E个数比E大，排序，有i-1个数比第i个数小，