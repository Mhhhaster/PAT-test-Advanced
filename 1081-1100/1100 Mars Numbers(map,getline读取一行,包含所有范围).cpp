#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;
string a[13] = { "tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug","sep", "oct", "nov", "dec" };
string b[13] = { "####", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo","syy", "lok", "mer", "jou" };
unordered_map<string, int>M1toE;//字符指向数字
unordered_map<string, int>M2toE;
void Judge()
{
    string input;
    getline(cin,input);
    if (input[0] - '0' >= 0 && input[0] - '0' <= 9)
    {//0-169
        int num;
        sscanf(input.c_str(), "%d", &num);
        if (num <= 12)//
        {
            cout << a[num % 13]<<endl;
        }
        else
        {
            cout << b[num / 13];
            if (num % 13)
                cout << " " << a[num % 13];
            cout << endl;
        }
    }
    else
    {//3or4or7字符
        int num;
        if (input.length() == 4)
            cout << "0" << endl;
        else if (input.length() == 3)
        {
            num = M2toE[input] * 13 + M1toE[input];//找不到对应的就为0，不影响结果
            cout << num << endl;
        }
        else
        {
            num = M2toE[input.substr(0, 3)] * 13 + M1toE[input.substr(4, 3)];
            cout << num << endl;
        }
    }
}
int main()
{
    int N;
    scanf("%d", &N);
    getchar();
    for (int i = 0; i <= 12; i++)
    {
        M1toE[a[i]] = i;
        M2toE[b[i]] = i;
    }
    for (int i = 0; i < N; i++)
    {
        Judge();
    }
    return 0;
}
/*
conclude:
1.string 和int 类型的对应，采用map结构
2.读取一行输入采用getline(cin,str)，注意getline之间是不用getchar来读取换行符的
3.运用了sscanf和c_str()及substr函数。
4.同样的，先在纸上计算好所有的取值范围和情况
*/