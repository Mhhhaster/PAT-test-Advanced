#include<iostream>
#include<string>
#include<map>
using namespace std;
int main()
{
	string origin, verse, result;
	getline(cin, origin);
	map<string, int>M;
	for (int i = 0; i < origin.length(); i++) {
		if (origin[i] == '"') {
			verse = origin.substr(i + 1, origin.length() - i - 2);
			break;
		}
		if (i == origin.length() - 1)
			verse = origin;
	}
	for (int i = 0; i < verse.length(); i++) {
		if (verse[i] >= 'A' && verse[i] <= 'Z')
			verse[i] += 32;
		if ((verse[i] >= 'a' && verse[i] <= 'z')||(verse[i]>='0'&&verse[i]<='9')) 
			result += verse[i];
		else if (result.length()) {
				M[result]++;
				result.clear();
		}
	}
	if (result.length())
		M[result]++;
	int max = 0;
	string most;
	for (auto it : M) {
		if (it.second > max) {
			max = it.second;
			most = it.first;
		}
	}
	cout << most << " " << max;
	return 0;
}