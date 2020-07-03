#include<iostream>
#include<queue>
#include<vector>
const int Inf = 99999999;
using namespace std;
int N, cap, K, Q;
vector<int>protime;//记录每个人需要消耗的时间
vector<int>endtime;//记录每个人的结束时间，若为-1说明没有被服务
vector<queue<int>>line;//记录每个窗口当前排队的人
vector<int>starttime;//记录每个窗口开始的时间
int ptrtowait;//指向下一个进黄线的人
bool Isempty();
int Pop();
int main()
{
	scanf("%d%d%d%d", &N, &cap, &K, &Q);
	protime.resize(K+1);
	line.resize(N+1);
	endtime.resize(K + 1,-1);
	starttime.resize(N+1,480);
	for (int i = 1; i <= K; i++)
		scanf("%d", &protime[i]);
	if (N * cap >= K) {//说明黄线可以全部容纳
		for (int i = 1; i <= K; i++)
			line[(i - 1) % N+1].push(i);
		ptrtowait = K+1;//指向队伍末尾
	}
	else {
		for (int i = 1; i <= N * cap; i++)
			line[(i - 1) % N+1].push(i);
		ptrtowait = N * cap + 1;
	}
	while (!Isempty()) {
		int earlyline=Pop();
		if (ptrtowait <= K) {
			line[earlyline].push(ptrtowait);
			ptrtowait++;
		}
	}
	int query;
	for (int i = 0; i < Q; i++) {
		scanf("%d", &query);
		int result = endtime[query];//序号全部转化为从1开始，故减1
		if (result == -1) printf("Sorry\n");
		else printf("%02d:%02d\n", result / 60, result % 60);
	}//从480min开始服务，到1020min停止接新服务
	return 0;
}
bool Isempty()//判断是否所有队列都空了
{
	for (int i = 1; i <= N; i++)
		if (!line[i].empty())
			return false;
	return true;
}
int Pop()//指示哪条队列先完事并返回,空队列的开始时间置为Inf
{
	int earliest = Inf, earlyline = 1;
	for (int i = 1; i <= N; i++) {
		if (!line[i].empty()) {
			int now = line[i].front();//指示当前窗口服务的人的序号
			if (earliest > protime[now] + starttime[i]) {
				earliest = protime[now] + starttime[i];
				earlyline = i;
			}
		}
	}
	if (line[earlyline].empty())
		starttime[earlyline] = Inf;
	else
		starttime[earlyline] += protime[line[earlyline].front()];
	if(earliest-protime[line[earlyline].front()]<1020)
		endtime[line[earlyline].front()] = earliest;
	line[earlyline].pop();
	return earlyline;
}
/*解题思路很重要，模拟手工运算的过程*/