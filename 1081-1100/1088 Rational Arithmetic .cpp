#include<iostream>
using namespace std;
long long getmaxfactor(long long a, long long b)//除数和余数反复做除法运算，当余数为 0 时，取当前算式除数为最大公约数
{
	long long c, d;
	for (;;)
	{
		c = a / b;
		d = a % b;
		if (d == 0)
			break;
		a = b;
		b = d;
	}
	return b>0?b:-b;
}
void func(long long as,long long ap)//输入分子分母，格式化输出
{
	long long prea, upa, downa;//分别为带分数前的数字、分子和分母
	if (ap == 0)//分母为0
	{
		printf("Inf");
		return;
	}
	if (as == 0)//分子为0
	{
		printf("0");
		return;
	}
	else
	{
		long long maxfactor = getmaxfactor(as, ap);//计算出分子分母最大公约数
		as /= maxfactor;
		ap /= maxfactor;
		prea = as / ap;
		upa = as % ap;
		downa = ap;
		if (downa < 0)
		{
			upa = -upa; downa = -downa;
		}
	}//-2  -2 0/1；2/3   0 2/3；   -4/5  0 -4/5； -9/6   -1 -1/2；
	if (prea < 0||(prea==0&&upa<0))
		printf("(");
	if (prea != 0)
		printf("%d", prea);
	if (prea != 0 && upa != 0)
		printf(" ");
	if(upa!=0)
	{
		if (prea < 0)
			printf("%d", -upa);
		else
			printf("%d", upa);	
		printf("/%d", downa);
	}
	if (prea < 0||(prea==0&&upa<0))
		printf(")");
}
int main()
{
	long long as, ap, bs, bp;//担心长整型的运算会超范围，所以全部采用long long运算和存储
	scanf("%lld/%lld %lld/%lld", &as, &ap, &bs, &bp);//分别为a的分子、分母；b的分子，分母
	//接下来化简数字，分为可整除和不可整除，不可整除中分为真分数和带分数
	func(as, ap); printf(" + "); func(bs, bp); printf(" = "); func(as * bp + ap * bs, ap * bp); printf("\n");
	func(as, ap); printf(" - "); func(bs, bp); printf(" = "); func(as * bp - ap * bs, ap * bp); printf("\n");
	func(as, ap); printf(" * "); func(bs, bp); printf(" = "); func(as * bs, ap * bp);printf("\n");
	func(as, ap); printf(" / "); func(bs, bp); printf(" = "); func(as * bp, bs * ap);
	return 0;
}
/*
conclude：本题当选为折磨王，
要擅于提取函数，简化程序；
要在纸上把所有情况考虑演算清楚，才不至于写不动;
*/