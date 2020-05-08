#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
bool compare(string a, string b)//判断时间a是否比b晚
{//xx:xx:xx
    if (a[0] == b[0] && a[1] == b[1])
    {
        if (a[3] == b[3] && a[4] == b[4])
            return (a[6] > b[6] || (a[6] == b[6] && a[7] > b[7]));
        else
            return (a[3] > b[3] || (a[3] == b[3] && a[4] > b[4]));
    }
    else
        return (a[0] > b[0] || (a[0] == b[0] && a[1] > b[1]));
}
int main()//本题也可将时间转化为秒
{
    int N;
    cin>>N;
    string open, close;//记录第一个人和最后一个人名字
    string t1 = "24:00:00";
    string t2 = "00:00:00";//记录最早和最晚时间
    string name, tempt1, tempt2;
    while (N--)
    {
        cin >> name >> tempt1 >> tempt2;
        if (compare(t1, tempt1))//t1大于tempt1,close需要更新
        {
            open = name;
            t1 = tempt1;
        }
        if (!compare(t2, tempt2))//t2晚于tempt2
        {
            close = name;
            t2 = tempt2;
        }
    }
    cout << open << " " << close;
}
/*3
CS301111 15:30:28 17:00:10
SC3021234 08:00:00 11:25:25
CS301133 21:45:00 21:58:40*/