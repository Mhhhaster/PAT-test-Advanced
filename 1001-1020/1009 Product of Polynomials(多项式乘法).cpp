#include<iostream>
#include<vector>
using namespace std;
struct Node
{
	int expon;
	float coef;
};
int main()
{
	int anum, bnum,expon;
	float coef;
	scanf("%d", &anum);
	vector<Node>A;
	for (int i = 0; i < anum; i++)
	{
		scanf("%d%f", &expon, &coef);
		A.push_back({ expon,coef });
	}
	scanf("%d", &bnum);
	vector<Node>B;
	for (int i = 0; i < bnum; i++)
	{
		scanf("%d%f", &expon, &coef);
		B.push_back({ expon,coef });
	}
	vector<Node>poly;
	int i = 0,j = 0;
	int polyexpon;
	float polycoef;
	for (j = 0; j < B.size(); j++)
	{
		polyexpon = A[0].expon + B[j].expon;
		polycoef = A[0].coef * B[j].coef;
		if (polycoef)
			poly.push_back({ polyexpon,polycoef });
	}
	for(i=1;i<A.size();i++)
		for (j = 0; j < B.size(); j++)
		{
			polyexpon = A[i].expon + B[j].expon;
			polycoef = A[i].coef * B[j].coef;
			if (polycoef)
			{
				int k = poly.size()-1;
				for (; k >= 0 && poly[k].expon < polyexpon; k--);//从后开始比,跳出循环说明当前k>=polyexpon
				if (poly[k].expon == polyexpon)
				{
					poly[k].coef+= polycoef;
					if (poly[k].coef == 0)
						poly.erase(poly.begin()+k);
				}
				else//说明需要插入到k的后面一个
				{
					poly.push_back({ 0,0 });
					for (int t = poly.size()-1; t>k+1; t--)
						poly[t] = poly[t-1];//全部后移一个
					poly[k+1].coef = polycoef;
					poly[k+1].expon = polyexpon;
				}
			}
		}
	printf("%d", poly.size());
	for (int i = 0; i < poly.size(); i++)
		printf(" %d %.1f", poly[i].expon, poly[i].coef);
	return 0;
}