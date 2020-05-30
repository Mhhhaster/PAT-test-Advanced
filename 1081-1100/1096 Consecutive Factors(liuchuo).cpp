#include <iostream>
#include <cmath>
using namespace std;
long int num, temp;
int main() {
    cin >> num;
    int first = 0, len = 0, maxn = sqrt(num);
    for (int i = 2; i <= maxn; i++) {
        int j; temp = 1;
        for (j = i; j <= maxn; j++) {
            temp *= j;
            if (num % temp != 0) break;
        }
        if (j - i > len) {
            len = j - i;
            first = i;
        }
    }
    if (first == 0) cout << 1 << endl << num;
    else {
        cout << len << endl;
        for (int i = 0; i < len; i++) {
            cout << first + i;
            if (i != len - 1) cout << '*';
        }
    }
    return 0;
}
/*conclude：
liuchuo：不断构造连乘，看连乘的积是否是N的因数，如果是，则看这部分连乘的数的个数是否⽐已记录的多。
我：遍历每个可以整除的数，找到它的最长连续因数长度，比较是否比记录的多
*/