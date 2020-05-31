//采用vector存储车辆出入信息，最后再使用sort排序,时间上会快些
#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>//用于对每个车牌建立一个数字下标
#include<algorithm>
using namespace std;
struct TimeNode {
	int time;
	bool status;//进为1，出为0
};
vector<vector<TimeNode>>V;
int turntosec(string time)
{
	return (time[0] - '0') * 36000 + (time[1] - '0') * 3600 + (time[3] - '0') * 600 + (time[4] - '0') * 60 + (time[6] - '0') * 10 + time[7] - '0';
}//06:30:50
bool cmp(TimeNode a,TimeNode b)
{
	return a.time < b.time;
}
int main()
{
	int N, K;
	scanf("%d%d", &N, &K);
	string carplate, time, status;
	/*获得每辆车的进出信息*/
	unordered_map<string, int>M;//车牌-下标,同时可以对车牌排序
	unordered_map<int, string>RM;//下标-车牌
	int cnt = 1;//注意，车牌对应的下标从1开始，所以需要对vector循下标时记住要-1
	for (int i = 0; i < N; i++)
	{
		cin >> carplate >> time >> status;
		if (M[carplate] == 0)//这个车牌之前没有出现过
		{
			M[carplate] = cnt++;//为车牌赋值
			RM[cnt - 1] = carplate;
			vector<TimeNode>t;
			V.push_back(t);//V尺寸加一
		}
		bool temp = false;
		if (status[0] == 'i')
			temp = true;
		V[M[carplate] - 1].push_back({ turntosec(time), temp });//找到对应的集合，插入出入信息
	}
	/*得到每辆车的停留总时间，及每个时间点的车数量*/
	vector<int>Cartime(V.size(), 0);//用来指示每辆车的停留时间
	vector<int>Carnum(turntosec("24:00:00"), 0);//每秒车的数量
	for (int i = 0; i < V.size(); i++)//遍历每辆车
	{
		sort(V[i].begin(), V[i].end(), cmp);
		for (auto it = V[i].begin(); it != V[i].end(); it++)//遍历每辆车的出入信息
		{
			auto ti = it;
			ti++;
			if (ti != V[i].end() && it->status == true && ti->status == false)
			{
				Cartime[i] += ti->time - it->time;
				for (int j = it->time; j < ti->time; j++)
					Carnum[j]++;
			}
		}
	}//集合全部遍历一遍
	/*测试每个时间点有多少车，计算每秒钟的车数，保存*/
	for (int i = 0; i < K; i++)
	{//把时间插入集合，如果左为进右为出说明车在校园内
		string temp;
		cin >> temp;
		int temptime = turntosec(temp);
		printf("%d\n", Carnum[temptime]);
	}
	/*输出*/
	int max = 0;
	for (int i = 0; i < V.size(); i++)
		if (Cartime[i] > max)
		{
			max = Cartime[i];
		}
	for (int i = 0; i < V.size(); i++)
		if (Cartime[i] == max)
			cout << RM[i + 1] << " ";
	printf("%02d:%02d:%02d", max / 3600, (max % 3600) / 60, max % 60);
}
/*conclude:
收获很大：
1.学会用map来将字符串或者大数映射成小数
2.复习了set中用重载<来排序的方法
3.再次验证set中不能有重复元素，(map键值对不存在重复的概念)
4.迭代器不允许it+i，只能it++或者it--；
5.当set中有{-1，-2}时，你甚至不能插入{-1，-232}
6.注意测试数据的特点，K最大值为8000，所以需要将每次测试的过程尽量简化。
7.如果不是要求任何时候都有序，没必要用set和map，用vector+sort即可
8.超时没啥好说的，毕竟用了这么多cin和string，如果全改成char[]和scanf、printf应该可以全ac
*/