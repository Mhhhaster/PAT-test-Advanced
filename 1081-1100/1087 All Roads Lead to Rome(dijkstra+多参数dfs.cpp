#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<string>
using namespace std;
vector<int>hap;
int G[201][201];
vector<bool>visit;
vector<int>dis;
const int Inf = 99999999;
vector<int>path[201];//ָʾ·��
unordered_map<string, int>M;
unordered_map<int, string>RM;
string start;
float resavehappy = 0;
int pathsum = 0, reshappy = 0;
vector<int>respath, temppath;
void dfs(int index, int happysum, int passsum)
{
	temppath.push_back(index);
	if (index == 1) {//˵�����ݵ������
		pathsum++;
		if (happysum > reshappy || (happysum == reshappy && happysum * 1.0 / passsum > resavehappy)) {
			reshappy = happysum;
			resavehappy = happysum * 1.0 / passsum;
			respath = temppath;
		}
	}
	else
		for (int i = 0; i < path[index].size(); i++)
			dfs(path[index][i], happysum + hap[index], passsum + 1);
	temppath.pop_back();
}
int main()
{

	fill(G[0], G[0] + 201 * 201, Inf);
	int citynum, pathnum, happy, length;
	string temp, temp2;
	cin >> citynum >> pathnum >> start;
	M[start] = 1; RM[1] = start;
	visit.resize(citynum + 1, false);
	dis.resize(citynum + 1, Inf);
	hap.resize(citynum + 1);
	for (int i = 1; i < citynum; i++) {
		cin >> temp >> happy;
		M[temp] = i + 1;
		RM[i + 1] = temp;
		hap[M[temp]] = happy;
	}
	for (int i = 0; i < pathnum; i++) {
		cin >> temp >> temp2 >> length;
		G[M[temp]][M[temp2]] = G[M[temp2]][M[temp]] = length;
	}
	//dijkstra�㷨�õ����·��
	dis[M[start]] = 0;
	while (1) {
		int min = Inf, minindex = -1;
		for (int i = 1; i <= citynum; i++) {
			if (dis[i] < min && visit[i] == false) {
				minindex = i;
				min = dis[i];
			}
		}
		if (minindex == -1 || minindex == M["ROM"])
			break;
		visit[minindex] = true;
		for (int i = 1; i <= citynum; i++) {
			if (G[minindex][i] + dis[minindex] < dis[i]) {
				dis[i] = G[minindex][i] + dis[minindex];
				path[i].clear();
				path[i].push_back(minindex);//��i��·�Ͼ���minindex
			}
			else if (G[minindex][i] + dis[minindex] == dis[i]) {
				path[i].push_back(minindex);
			}
		}
	}
	/*dijktra�㷨����*/
	dfs(M["ROM"], 0, 0);
	printf("%d %d %d %d\n", pathsum, dis[M["ROM"]], reshappy, int(resavehappy));
	printf("%s", RM[respath[respath.size() - 1]].c_str());
	for (int i = respath.size() - 2; i >= 0; i--)
		printf("->%s", RM[respath[i]].c_str());
	return 0;
}
/*
�ܷ�����pathsum��dis[ROM]�����˳��Ū���˿��˺ܾ�
����ע��ĵ㣺
����dijkstra�õ���̵�·������dfs����
dfs����ֻ��index��Ҳ���Դ��ϸ������
happyֵ����ͨ��index��������ʵ��һ����Ը��������
dijkstra�и�С������ֻ��ʼ��dis[start]=0�����ڽӵ�ĳ�ʼ���ڵ�һ��ѭ���Լ���
�ܳ����һ��dijkstra�㷨��
*/