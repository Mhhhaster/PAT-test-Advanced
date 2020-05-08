#include<iostream>
#include<string>
#include<string.h>
using namespace std;
bool Judge(string input)//用于判断输入是否合法，不合法则输出
{
    char a[50], b[50];
    strcpy(a, input.c_str());
    double temp = -9999;
    sscanf(a, "%lf", &temp);
    sprintf(b, "%.2f", temp);//将temp的初值赋给了b，同时还影响了a？
    /*结论：sscanf的策略是只把数字型字符赋值过去，否则就不赋值。temp初值太长，导致再赋值的时候溢出了b的范围，影响到了a*/
    /*处理方法对temp赋值一个短的初值*/
    int flag = 0;
    for (int j = 0; j < strlen(a); j++)
        if (a[j] != b[j])
            flag = 1;
    if (!flag && temp >= -1000 && temp <= 1000)
        return true;
    else
    {
        printf("ERROR: ");
        cout << input;
        printf(" is not a legal number\n");
        return false;
    }
}
int main()
{
    int N;
    scanf("%d", &N);
    string input;
    float sum = 0.00;
    int flag = 0;//用来指示读入的输入个数
    while (N--)
    {
        cin >> input;
        if (Judge(input))
        {
            sum += stof(input);
            flag++;
        }
    }
    if (flag == 0)
        printf("The average of 0 numbers is Undefined");
    if (flag == 1)
        printf("The average of 1 number is %.2f", sum);
    if (flag > 1)
        printf("The average of %d numbers is %.2f", flag, sum / flag);
    return 0;
}