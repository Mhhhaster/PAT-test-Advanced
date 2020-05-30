/*3.2.1 10.16.27
Sample Output:
14.1.28*/
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string A, B;
	cin >> A >> B;
	int GA, SA, KA, GB, SB, KB;
	/*
	scanf("%lld.%lld.%lld %lld.%lld.%lld", &a, &b, &c, &d, &e, &f);
	这里可以通过输入scanf的格式来掠过
	注意long long 在scanf中对应%lld
	*/
	sscanf(A.c_str(), "%d", &GA);
	sscanf(B.c_str(), "%d", &GB);
	for (int i = 0; i < A.length(); i++)
	{
		if (A[i] == '.')
		{
			sscanf(A.c_str() + i + 1, "%d", &SA);
			for (int j = i + 1; j < A.length(); j++)
				if (A[j] == '.')
					sscanf(A.c_str() + j + 1, "%d", &KA);
			break;
		}
	}
	for (int i = 0; i < B.length(); i++)
	{
		if (B[i] == '.')
		{
			sscanf(B.c_str() + i + 1, "%d", &SB);
			for (int j = i + 1; j < B.length(); j++)
				if (B[j] == '.')
					sscanf(B.c_str() + j + 1, "%d", &KB);
			break;
		}
	}
	int sumK, sumS, sumG, temp = 0;
	sumK = (KA + KB) % 29;
	if (KA + KB >= 29)
		temp = 1;
	sumS = (SA + SB + temp) % 17;
	if (SA + SB + temp >= 17)
		temp = 1;
	else
		temp = 0;
	sumG = GA + GB + temp;
	printf("%d.%d.%d",sumG, sumS, sumK);
	return 0;
}
/*
字符串的处理
sscanf的应用
scanf的格式应用
*/