#include<iostream>
#include<algorithm>
#include<string>
#include<unordered_map>
using namespace std;
const int Uplimit = 99999999;
int N, M, K, Ds;
int length[1015][1015];
unordered_map<string, int>Map;
int result_pos = -1;
double res_minlength=0, res_avelength;
void Getlength(int index)//获得index下标的加油站的最短距离和平均距离
{
	int dis[1015];
	fill(dis, dis + 1015, Uplimit);
	bool visit[1015] = { false };
	dis[N+index] = 0;
	while (1)
	{
		int minindex = -1, mindis = Uplimit;
		for (int i = 1; i <= N+M; i++)
			if (visit[i] == false && dis[i] < mindis)
			{
				minindex = i;
				mindis = dis[i];
			}
		if (minindex == -1)
			break;
		visit[minindex] = true;
		for (int i = 1; i <= N+M; i++)
			if (visit[i] == false && length[minindex][i] < Uplimit)
			{
				if (dis[i] > dis[minindex] + length[minindex][i])
				{
					dis[i] = dis[minindex] + length[minindex][i];
				}
			}
	}
//遍历1到N，是否有距离超限的，没有的话记录最短距离，算出平均距离
	int tempmin = Uplimit;
	double lengthsum = 0;
	for (int i = 1; i <= N; i++)
	{
		if (dis[i] > Ds)
			return;
		else
		{
			if (dis[i] < tempmin)
				tempmin = dis[i];
			lengthsum += dis[i];
		}
	}
	if (tempmin > res_minlength)
	{
		res_minlength = tempmin;
		result_pos = index;
		res_avelength = lengthsum / N;
	}
	else if (tempmin == res_minlength && lengthsum / N < res_avelength)
	{
		result_pos = index;
		res_avelength = lengthsum / N;
	}
}
int main()
{
	fill(length[0], length[0] + 1015 * 1015, Uplimit);
	scanf("%d%d%d%d", &N, &M, &K, &Ds);
	for (int i = 1; i <= M; i++)
	{
		string temp = "G";
		temp += to_string(i);
		Map[temp] = N + i;
	}//将加油站也算进图中
	for (int i = 0; i < K; i++)
	{
		string temp1, temp2;
		int road1,road2,dis;
		cin >> temp1 >> temp2 >> dis;
		if (temp1[0] == 'G')
			road1 = Map[temp1];
		else
			sscanf(temp1.c_str(), "%d", &road1);
		if (temp2[0] == 'G')
			road2 = Map[temp2];
		else
			sscanf(temp2.c_str(), "%d", &road2);
		length[road1][road2] =length[road2][road1]= dis;
	}//存储图信息
	for (int i = 1; i <= M; i++)
		Getlength(i);//从G1到GM
	if (result_pos != -1)
	{
		cout << "G" << result_pos << endl;
		printf("%.1f %.1f", res_minlength, res_avelength );
	}
	else
		cout << "No Solution";
	return 0; 
}
//注意，%.1f中精确到1位小数是会四舍五入的，而格式截断则不是，需要加上0.5