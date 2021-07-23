#include<string>
#include<vector>
#include<iostream>
using namespace std;
vector<string>V({ "MON","TUE","WED","THU","FRI","SAT","SUN" });
int main()
{
	string str1, str2, str3, str4;
	cin >> str1 >> str2 >> str3 >> str4;
	int pos = 0;
	for (; pos < str3.length() && pos < str4.length(); pos++)
		if (str3[pos] == str4[pos]&&((str3[pos]>='a'&& str3[pos]<='z')||(str3[pos]>='A'&& str3[pos]<='Z')))
			break;
	int i = 0;
	for (; i < str1.length() && i < str2.length(); i++)
		if (str1[i] == str2[i] && str1[i] >= 'A' && str1[i] <= 'G')
			break;//相同的大写字母
	int j = i+1, hour = 0;
	for (; j < str1.length() && j < str2.length(); j++)
		if (str1[j] == str2[j] && i != j) {
			if (str1[j] >= 'A' && str1[j] <= 'N') {
				hour = str1[j] - 'A' + 10;
				break;
			}
			else if (str1[j] >= '0' && str1[j] <= '9') {
				hour = str1[j] - '0';
				break;
			}
		}//
	printf("%s %02d:%02d", V[str1[i]-'A'].c_str(), hour, pos);
	return 0;
}