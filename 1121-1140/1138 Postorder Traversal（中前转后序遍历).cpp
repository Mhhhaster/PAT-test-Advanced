/*7
1 2 3 4 5 6 7
2 3 1 5 4 7 6
Sample Output:
3*/
#include<iostream>
#include<vector>
using namespace std;
vector<int>pre;
vector<int>in;
vector<int>post;
int FindRoot(int Root,int inleft,int length)
{
	for (int i = inleft; i < inleft + length; i++)
		if (Root == in[i])
			return i;
	return -1;
}
void Getpost(int preleft, int inleft, int postleft, int length)
{
	if (length < 1)
		return;
	if (length == 1)
	{
		post[postleft] = pre[preleft]; 
		return;
	}
	int Root = pre[preleft];
	int position = FindRoot(Root,inleft,length);
	int leftlength = position - inleft;
	post[postleft + length - 1] = Root;
	Getpost(preleft + 1, inleft, postleft, leftlength);
	Getpost(preleft + 1 + leftlength, inleft + leftlength + 1, postleft + leftlength, length - leftlength - 1);
	return;
}//注意本题只需要输出后序遍历的第一个数，所以当post[0]被赋值了之后就可以退出了->任意一个递归彻底完成时一定post[0]被赋值
int main()
{
	int N;
	scanf("%d", &N);
	pre.resize(N);
	in.resize(N);
	post.resize(N);
	for (int i = 0; i < N; i++)
		scanf("%d", &pre[i]);
	for (int i = 0; i < N; i++)
		scanf("%d", &in[i]);
	Getpost(0,0,0,N);
	printf("%d", post[0]);
	return 0;
}