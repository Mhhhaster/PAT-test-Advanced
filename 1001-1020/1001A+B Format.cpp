#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    int a;
    int b;
    int sum;
    cin >> a >> b;
    sum = a + b;
    if (sum < 0)
    {
        cout << "-";
        sum = 0 - sum;
    }//a,b=<1000000
    if (sum < 1000)
        cout << sum;
    else if (sum < 1000000)
    {
        printf("%d,%03d", sum / 1000, sum % 1000);
    }
    else
    {
        printf("%d,%03d,%03d", sum / 1000000, (sum % 1000000) / 1000, sum % 1000);
    }
    return 0;
}
结论：自己程序不够美观，对每一个数字的处理可以通过to_string（）函数转为字符串。此外，不需要非得从末尾开始判别条件，也可以通过研究字符串长度与逗号插入位置的关系。
#include <iostream>
using namespace std;
int main() {
 int a, b;
 cin >> a >> b;
 string s = to_string(a + b);
 int len = s.length();
 for (int i = 0; i < len; i++) {
 cout << s[i];
 if (s[i] == '-') continue;
 if ((i + 1) % 3 == len % 3 && i != len - 1) cout << ",";
 }
 return 0; }