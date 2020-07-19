#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int main()
{
	int M, N, temp;
	scanf("%d%d", &M, &N);
	unordered_map<int, int>Map;
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++) {
			scanf("%d", &temp);
			Map[temp]++;
		}
	int max = -1, maxcolor = -1;
	for (auto it : Map) {
		if (it.second > max) {
			maxcolor = it.first;
			max = it.second;
		}
	}
	printf("%d", maxcolor);
	return 0;
}