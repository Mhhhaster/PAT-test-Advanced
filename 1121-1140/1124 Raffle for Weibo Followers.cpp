#include<string>
#include<vector>
#include<iostream>
using namespace std;
vector<bool>chosen;
vector<string>name;
int times = 0;//每次输出前自增一次
int Choose(int i)//选择name[i]为抽奖人，如果chosen[i]=false,说明被选过了，如果为true输出，并且把chosen中元素更新
{
	if (chosen[i] == false)
		return Choose(i + 1);
	else
	{
		times++;
		cout << name[i] << endl;
		for (int j = 0; j < name.size(); j++)
			if (name[i] == name[j])
				chosen[j] = false;
	}
	return i;
}
int main()
{
	int M, N, S;
	scanf("%d%d%d", &M, &N, &S);
	name.resize(M);
	chosen.resize(M, true);
	for (int i = 0; i < M; i++)
		cin >> name[i];
	for (int i = S - 1; i < M; i += N)
	{
		int j = Choose(i);
		if (j > i)
			i = j;
	}
	if (times == 0)
		printf("Keep going...\n");
	return 0;
}