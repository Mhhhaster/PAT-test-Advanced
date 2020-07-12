#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
unordered_map<int, vector<int>>M;
bool exist[100001] = { false };
void Judge()
{
	int k;
	scanf("%d", &k);
	vector<int>input(k);
	for (int j = 0; j < k; j++)
		scanf("%d", &input[j]);
	for (int j = 0; j < k - 1; j++)
		for (int p = j + 1; p < k; p++) {
			if(exist[input[j]]==true)
				for(int m=0;m<M[input[j]].size();m++)
					if (M[input[j]][m]==input[p]) {//找到了危险
						printf("No\n");
						return;
			}
		}
	printf("Yes\n");
	return;
}
int main()
{
	int pairnum, testnum, stuff1, stuff2;
	scanf("%d%d", &pairnum, &testnum);
	for (int i = 0; i < pairnum; i++) {
		scanf("%d%d", &stuff1, &stuff2);
		exist[stuff1] = exist[stuff2] = true;
		M[stuff1].push_back(stuff2);
		M[stuff2].push_back(stuff1);
	}
	for (int i = 0; i < testnum; i++) 
		Judge();
	return 0;
}
/*本题体现两种思路
对于问题：对一大堆结点，检测是不是有邻接点
我的思路：每两个结点抓来问一下，看看A的邻接点里有没有B
liuchuo：给所有人带上帽子，然后对每一个人，看看他是不是有邻接点此时戴了帽子(数组实现)
检测两两关系的新思路
本题最重要的还是map<int,vector<int>>的使用，使一个编号对应一个数组，简化了编程与理解
此外，使用exist数组的目的是，发现尽管没有给M[p]赋值，但是只要使用了这个式子，这个键值对就存在了
所以用exist数组保存之前有值的键，碰到没有值的键就直接跳过
*/