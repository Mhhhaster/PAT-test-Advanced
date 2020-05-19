#include<iostream>
#include<vector>
#include<set>
using namespace std;
//维护一个集合，集合中元素按序排列，每次输入一个元素，在集合中找到这个元素，删除它并更新，找不到就新建
struct Node {
	int name;//item名称
	int fre;//出现频次
	//注意：当set中放入的为结构体时，需要重载运算符，告知比较规则
	bool operator <(const Node& a)const {
		return (fre != a.fre) ? fre > a.fre:name < a.name;
	}
};
int main()
{
	int N, K;
	scanf("%d%d", &N, &K);
	set<Node>S;
	vector<int>freq(N+1);
	int temp;
	scanf("%d", &temp);
	freq[temp]++;
	S.insert(Node{ temp,1 });//插入一个name为temp，fre为1的Node节点
	for (int i = 1; i < N; i++)//循环N-1次
	{
		scanf("%d", &temp);
		printf("%d:", temp);
		int cnt = 0;
		for (auto it = S.begin(); it != S.end()&&cnt!=K; it++)//找到当前集合中最前面的K个元素,不足则跳过
		{
			printf(" %d", it->name);
			cnt++;
		}
		printf("\n");
		
		auto it = S.find(Node{ temp,freq[temp] });//迭代器，find返回set类型，可以像指针一样用->访问结构体内部变量
		if (it != S.end())//找不到返回集合最末尾
			S.erase(it);//找得到就擦除
		freq[temp]++;//先输出最后再更新
		S.insert(Node{ temp,freq[temp] });//添加 
	}
	return 0;
}
/*这题可以马上想到用优先队列，但是由于priority不能更新出现的次数而陷入瓶颈，
实际上这个操作可以通过set的find、erase和insert来完成
逻辑上不难，需要注意的是重载运算符的写法*/