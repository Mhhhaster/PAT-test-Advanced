#include<iostream>
#include<string>
#include<map>
using namespace std;
int main()
{
	string  verse, result;
	getline(cin, verse);
	map<string, int>M;
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