#include <iostream>
#include <algorithm>
#include<string.h>
#include <vector>
using namespace std;
#define MAXTOTAL	10001
#define MAXAMOUNT	101

int f[MAXTOTAL][MAXAMOUNT];			//f[n][m]表示 前n个数中 得出的 最接近m 的值
bool has[MAXTOTAL][MAXAMOUNT];		//has[n][m]表示在前n个数中得出最接近m的值时 是否用到c[n]
int c[MAXTOTAL] = { 0 };
int calcClosestSum(int n, int m)
{
	memset(f, 0, sizeof(f) );
	memset(has, false, sizeof(has) );
	int i, j;
	int sec;//用来考虑更新f[i][j]的临时变量
	for (i = 1; i <= n ; i++){//先枚举加入的硬币
		for (j = 1; j <= m; j++){//枚举给出的载重
			if (j - c[i] < 0)
				sec = 0;
			else 
				sec = f[i - 1][j - c[i]] + c[i];//sec的取值
			if (f[i - 1][j] > sec)
				f[i][j] = f[i - 1][j];
			else{
				f[i][j] = sec;
				has[i][j] = true;		//用到c[i]了 设has[i][j]为true
			}
		}
	}
	return f[n][m];
}
bool cmp(int A, int B)
{
	return A > B;
}
int main()
{
	int n, m;
	cin >> n >> m;
	int i;
	for (i = 0; i < n; i++)
		cin >> c[i +1];

	sort(c+1, c+n+1, cmp);		//从大到小排序
	int res = calcClosestSum(n, m);
	if (res == m) {
		vector<int> v;
		while (m)
		{
			while (!has[n][m])
				n--;
			v.push_back(c[n]);
			m = m - c[n];
			n--;
		}
		for (i = 0; i < v.size() - 1; i++)
			cout << v[i] << ' ';
		cout << v[i] << endl;
	}
	else						//无解
		cout << "No Solution" << endl;
	return 0;
}
/*
被DP问题折磨了
待填坑*/