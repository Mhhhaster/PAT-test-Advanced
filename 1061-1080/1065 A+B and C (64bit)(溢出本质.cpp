#include <cstdio>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        long long a, b, c;
        scanf("%lld %lld %lld", &a, &b, &c);
        if (a > 0 && b > 0 && a+b < 0) {//正溢出
            printf("Case #%d: true\n", i + 1);
        }
        else if (a < 0 && b < 0 && a+b >= 0) {//负溢出
            printf("Case #%d: false\n", i + 1);
        }
        else if (a+b > c) {//常规情况
            printf("Case #%d: true\n", i + 1);
        }
        else {
            printf("Case #%d: false\n", i + 1);
        }
    }
    return 0;
}
/*本题并没有取到右边界的情况，否则需要用高精度运算
考察内容为溢出的判定和理解
此外，输入数据是不会溢出的，只会保存为边界值*/