#include<iostream>
#include<string>
using namespace std;
int main()
{
    int bit;
    string A, B;
    cin >> bit >> A >> B;
    string RA, RB;//表示A,B的存储结果
    RA += "0.";
    RB += "0.";
    int dotA = 0;
    int dotB = 0;
    for (; dotA < A.length(); dotA++)
        if (A[dotA] == '.')
            break;
    for (; dotB < B.length(); dotB++)
        if (B[dotB] == '.')
            break;
    //dotA、B分别指示小数点的位置
    int iniA, iniB;
    for (iniA = 0; iniA < A.length(); iniA++)
        if (A[iniA] != '.' && A[iniA] != '0')
            break;
    for (iniB = 0; iniB < B.length(); iniB++)
        if (B[iniB] != '.' && B[iniB] != '0')
            break;
    //找到第一个有效数字到小数点的距离
    int exponA, exponB;
    if (dotA > iniA)//有整数
    {//iniA后面bit位不包括小数点
        exponA = dotA - iniA;
        int count = bit;
        for (int i = iniA; i < A.length(); i++)
        {
            if (count == 0)
                break;
            if (A[i] != '.')
            {
                RA += A[i];
                count--;
            }
        }
        while (count--)
            RA += '0';
    }
    else//无整数
    {
        exponA = dotA - iniA + 1;
        int count = bit;
        for (int i = iniA; i < A.length(); i++)
        {
            if (count == 0)
                break;
            RA += A[i];
            count--;
        }
        while (count--)
            RA += '0';
        if (iniA == A.length())
            exponA = 0;
    }
    if (dotB > iniB)
    {
        exponB = dotB - iniB;
        int count = bit;
        for (int i = iniB; i < B.length(); i++)
        {
            if (count == 0)
                break;
            if (B[i] != '.')
            {
                RB += B[i];
                count--;
            }
        }
        while (count--)
            RB += '0';
    }
    else
    {
        exponB = dotB - iniB + 1;
        int count = bit;
        for (int i = iniB; i < B.length(); i++)
        {
            if (count == 0)
                break;
            RB += B[i];
            count--;
        }
        while (count--)
            RB += '0';
        if (iniB == B.length())
            exponB = 0;
    }
    RA += '*'; RB += '*';
    RA += "10^"; RB += "10^";
    RA += to_string(exponA); RB += to_string(exponB);
    if (RA == RB)
        cout << "YES " << RA;
    else
        cout << "NO " << RA << " " << RB;
    return 0;
}
/*科学计数法，字符串处理大数字，结构化思维
采用substr函数和to_string函数*/