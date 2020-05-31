/*ppRYYGrrYBR2258
YrR8RrY
Yes 8*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
	string a, b;
	cin >> a >> b;
	int length = a.length();
	vector<bool>visit(length, false);
	int misscount = 0;
	bool flag = true;
	for (int i = 0; i < b.length(); i++)
	{
		for (int j = 0; j < a.length(); j++)
		{
			if (a[j] == b[i] && visit[j] == false)
			{
				visit[j] = true;
				break;
			}
			if (j == a.length()-1)//直到最后也没又找到
			{
				flag = false;
				misscount++;
			}
		}
	}
	if (flag)
	{
		int count = 0;
		for (int i = 0; i < length; i++)
			if (visit[i] == false)
				count++;
		printf("Yes %d", count);
	}
	else
		printf("No %d", misscount);
}
//本题也可以直接利用ASCII码值散列