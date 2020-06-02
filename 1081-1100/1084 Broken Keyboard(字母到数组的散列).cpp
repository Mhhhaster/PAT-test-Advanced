#include<iostream>
#include<string>
using namespace std;
int main()
{
	int visit[160] = { 0 };//0代表没有输入，1代表输入了没有输出，2代表输出了
	string ori, act;
	cin >> ori >> act;
	for (int i = 0; i < ori.length(); i++)
		visit[ori[i]] = 1;
	for (int i = 0; i < act.length(); i++)
		visit[act[i]] = 2;
	//至此，值为1的就是没打印出来的字符
	for (int i = 0; i < ori.length(); i++)
	{
		if (visit[ori[i]] == 1)
		{
			visit[ori[i]] = 2;
			if (ori[i] >= 65 && ori[i] <= 90)//大写字符
			{
				printf("%c", ori[i]);
				visit[ori[i] + 32] = 2;
			}
			else if (ori[i] >= 97 && ori[i] <= 123)//小写字符
			{
				printf("%c", ori[i] - 32);
				visit[ori[i] - 32] = 2;
			}
			else
				printf("%c", ori[i]);//其他字符
		}
	}
	return 0;
}