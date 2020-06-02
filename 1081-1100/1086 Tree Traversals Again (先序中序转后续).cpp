#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;
vector<int>pre;
vector<int>in;
vector<int>post;
void getpost(int preleft, int inleft, int postleft, int length)
{
	if (length <= 0)
		return;
	if (length == 1)
	{
		post[postleft] = pre[preleft];
		return;
	}
	int position = inleft;
	for (int i = inleft; i < inleft + length; i++)
		if (in[i] == pre[preleft])
			position = i;
	post[postleft + length - 1] = pre[preleft];
	int leftlength = position - inleft;
	getpost(preleft + 1, inleft, postleft, leftlength);
	getpost(preleft + leftlength + 1, inleft + 1 + leftlength, postleft + leftlength, length - leftlength - 1);
}
int main()
{
	int N;
	scanf("%d", &N);
	pre.resize(N);
	in.resize(N);
	post.resize(N);
	stack<int>S;
	string input;
	int temp,prec=0,inc=0;
	while(inc<N)
	{
		cin >> input;
		if (input[1] == 'u')
		{
			cin >> temp;
			S.push(temp);
			pre[prec++] = temp;
		}
		else
		{
			temp = S.top();
			S.pop();
			in[inc++] = temp;
		}
	}
	getpost(0, 0, 0, N);
	printf("%d", post[0]);
	for (int i = 1; i < N; i++)
		printf(" %d", post[i]);
	return 0;
}
/*6
Push 1
Push 2
Push 3
Pop
Pop
Push 4
Pop
Pop
Push 5
Push 6
Pop
Pop*/