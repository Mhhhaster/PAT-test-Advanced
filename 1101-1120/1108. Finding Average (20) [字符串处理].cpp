#include<iostream>
#include<string>
using namespace std;
bool Judge(string input)//用于判断输入是否合法，不合法则输出
{
    char a[50], b[50];
    strcpy(a, input.c_str());
    double temp;
    sscanf(a, "%lf", &temp);
    sprintf(b, "%.2f", temp);
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
        printf("The average of 1 number is %f", sum);
    if (flag > 1)
        printf("The average of K numbers is %.2f", sum / flag);
    return 0;
}