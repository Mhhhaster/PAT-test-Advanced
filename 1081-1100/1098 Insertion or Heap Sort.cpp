#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void downAdjust(vector<int>& b, int low, int high) {
    int i = 1, j = i * 2;
    while (j <= high) {
        if (j + 1 <= high && b[j] < b[j + 1]) j = j + 1;
        if (b[i] >= b[j]) break;
        swap(b[i], b[j]);
        i = j; j = i * 2;
    }
}
int main() {
    int n, p = 2;
    scanf("%d", &n);
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
    while (p <= n && b[p - 1] <= b[p]) p++;
    int index = p;
    while (p <= n && a[p] == b[p]) p++;
    if (p == n + 1) {
        printf("Insertion Sort\n");
        sort(b.begin() + 1, b.begin() + index + 1);
    }
    else {
        printf("Heap Sort\n");
        p = n;
        while (p > 2 && b[p] >= b[1]) p--;
        swap(b[1], b[p]);
        downAdjust(b, 1, p - 1);
    }
    printf("%d", b[1]);
    for (int i = 2; i <= n; i++)
        printf(" %d", b[i]);
    return 0;
}
/*
conclude:对于插入排序，后面全是一样的，前面全是升序
对于堆排序(最大堆)，后面全是最大值，前面是个最大堆
收获：
1.对vector的部分使用sort排序：sort(a.begin()+i,a.begin()+j)
2.堆排序的pecdown写法：
要传入容量大小，循环【parent从0开始，退出条件为parent没有子树或者parent比左右子树大者还大】
child指向左右子树更大者；看看能不能退出，不能的话把孩子提到父亲，父亲下来；
退出后parent就是首元素的位置
3.插入排序思路：从1开始，每次与前面的元素比较，移位，赋值。
*/