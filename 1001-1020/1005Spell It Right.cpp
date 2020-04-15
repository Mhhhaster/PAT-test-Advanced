#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<stack>
using namespace std;
void English(int i)
{
    switch (i)
    {
    case 1:cout << "one"; break;
    case 2:cout << "two"; break;
    case 3:cout << "three"; break;
    case 4:cout << "four"; break;
    case 5:cout << "five"; break;
    case 6:cout << "six"; break;
    case 7:cout << "seven"; break;
    case 8:cout << "eight"; break;
    case 9:cout << "nine"; break;
    case 0:cout << "zero"; break;
    }
}
int main()
{
    int sum=0;
    char temp;
    temp = getchar();
    int tag = 0;
    while (temp!='\n')
    {
        sum += int(temp) - 48;
        temp = getchar();
    }
    stack<int>S;
    if (sum == 0)
        cout << "zero";
    while(sum)
    {
        S.push(sum % 10);
        sum /= 10;
    }
    while (!S.empty())
    {
        if (tag == 0)
        {
            tag = 1;
            English(S.top());
        }
        else {
            cout << " ";
            English(S.top());
        }
        S.pop();
    }
    return 0;
}
conclude:可以把输入直接当成一个字符串读进来，再逐位相加（其实也差不多），这之后的逐位处理其实可以再转换成字符串。（之后又建立了一个字符串数组，不需要通过函数来判别输出，可以按顺序输出）
#include <iostream>
using namespace std;
int main() {
 string a;
 cin >> a;
 int sum = 0;
 for (int i = 0; i < a.length(); i++)
 sum += (a[i] - '0');
 string s = to_string(sum);
 string arr[10] = {"zero", "one", "two", "three", "four", "five", "six",
"seven", "eight", "nine"};
 cout << arr[s[0] - '0'];
 for (int i = 1; i < s.length(); i++)
 cout << " " << arr[s[i] - '0'];
 return 0;