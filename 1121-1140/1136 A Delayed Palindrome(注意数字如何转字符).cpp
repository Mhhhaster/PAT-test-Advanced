/*97152
Sample Output 1:
97152 + 25179 = 122331
122331 + 133221 = 255552
255552 is a palindromic number.
Sample Input 2:
196
Sample Output 2:
196 + 691 = 887
887 + 788 = 1675
1675 + 5761 = 7436
7436 + 6347 = 13783
13783 + 38731 = 52514
52514 + 41525 = 94039
94039 + 93049 = 187088
187088 + 880781 = 1067869
1067869 + 9687601 = 10755470
10755470 + 07455701 = 18211171
Not found in 10 iterations.*/
#include<iostream>
#include<string>
using namespace std;
bool Judge(string str)
{
	for (int i = 0; i < str.length()/2; i++)
		if (str[i] != str[str.length() - 1 - i])
			return false;
	return true;
}
string Reverse(string ori)
{
	string rev;
	for (int i = ori.length() - 1; i >= 0; i--)
		rev += ori[i];
	return rev;
}
string Add(string ori,string rev)
{
	int length = ori.length();
	//从最后一位向前累加
	int acc = 0;
	string revsum;
	for (int i = length - 1; i >= 0; i--)
	{
		int tempsum = ori[i] - '0' + rev[i] - '0' + acc;
		if (tempsum >= 10)
		{
			tempsum = tempsum % 10;
			acc = 1;
		}
		else
			acc = 0;
		revsum += tempsum+'0';
	}
	if (acc)
		revsum += '1';
	return Reverse(revsum);
}
int main()
{
	string origin;
	cin >> origin;
	if (Judge(origin))
	{
		cout << origin << " is a palindromic number.";
		return 0;
	}
	string rev, sum;
	for (int i = 0; i < 10; i++)
	{
		rev = Reverse(origin);
		sum = Add(origin, rev);
		cout << origin << " + " << rev << " = " << sum << endl;
		origin = sum;
		if (Judge(origin))
		{
			cout << origin << " is a palindromic number.";
			return 0;
		}
	}
	cout << "Not found in 10 iterations.";
	return 0;
}