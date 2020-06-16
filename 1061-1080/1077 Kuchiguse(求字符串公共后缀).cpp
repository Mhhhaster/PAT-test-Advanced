/*3
Itai nyan~
Ninjin wa iyadanyan~
uhhh nyan~*/
#include<iostream>
#include<string>
using namespace std;
int difstart = -1;//记录从什么位置开始就不相同了
void Judge(string module)
{
	string temp;
	getline(cin, temp);
	int tempdif = -1;
	int i = module.length(), j = temp.length();
	for (; i >= 0 && j >= 0; i--, j--)
	{
		if (module[i] != temp[j])
		{
			tempdif = i;
			break;
		}
	}
	if (tempdif > difstart)
		difstart = tempdif;
	return;
}
int main()
{
	string Ku;
	int N;
	scanf("%d", &N);
	getchar();
	getline(cin, Ku);
	for (int i = 1; i < N; i++)
	{
		Judge(Ku);
	}
	if (difstart == Ku.length() - 1)//最后一位也不相同
		cout << "nai";
	else
		cout << Ku.c_str() + difstart+1;
	return 0;
}
/*本题求的是共同后缀
需要熟悉的是获得一行输入的方法：getline(cin,str),别忘了读取前一个空格
也可以采用reverse(s.begin(),s.end())的方法，使一个字符串逆序翻转。
*/