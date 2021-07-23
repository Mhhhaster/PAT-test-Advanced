#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
bool cmp(int a, int b) {
	return a > b;
}
int getinc(int origin)
{
	string temp = to_string(origin);
	int zeronum = 4 - temp.length();
	for (int i = 0; i < zeronum; i++)
		temp += '0';
	sort(temp.begin(), temp.end());
	return stoi(temp);
}
int getdec(int origin)
{
	string temp = to_string(origin);
	int zeronum = 4 - temp.length();
	for (int i = 0; i < zeronum; i++)
		temp += '0';
	sort(temp.begin(), temp.end(), cmp);
	return stoi(temp);
}
int main()
{
	int origin;
	cin >> origin;
	if (origin == 6174) {
		printf("7641 - 1467 = 6174");
		return 0;
	}
	while (origin != 0 && origin != 6174) {
		int inc = getinc(origin), dec = getdec(origin);
		printf("%04d - %04d = %04d\n", dec, inc, dec - inc);
		origin = dec - inc;
	}
	return 0;
}