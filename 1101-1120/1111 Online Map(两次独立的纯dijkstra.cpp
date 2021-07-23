#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int length[500][500];
int Time[500][500];
const int Inf = 999999999;
void Print(int des, vector<int>P);
int main()
{
	int ori, des, Nv, Ne;
	fill(length[0], length[0] + 500 * 500, Inf);
	fill(Time[0], Time[0] + 500 * 500, Inf);
	scanf("%d%d", &Nv, &Ne);
	int v1, v2, status, len, times;
	for (int i = 0; i < Ne; i++) {
		scanf("%d%d%d%d%d", &v1, &v2, &status, &len, &times);
		length[v1][v2] = len;
		Time[v1][v2] = times;
		if (!status) {
			length[v2][v1] = len;
			Time[v2][v1] = times;
		}
	}
	scanf("%d%d", &ori, &des);
	vector<bool>disvisit(Nv);
	vector<int>dis(Nv, Inf);
	vector<int>distime(Nv, Inf);
	vector<int>dispath(Nv, -1);
	dis[ori] = 0; distime[ori] = 0;
	while (1) {
		int index = -1, min = Inf;
		for (int i = 0; i < Nv; i++) {
			if (disvisit[i] == false && dis[i] < min) {
				min = dis[i];
				index = i;
			}
		}
		if (index == des || index == -1)
			break;
		disvisit[index] = true;
		for (int i = 0; i < Nv; i++) {
			if (dis[i] > dis[index] + length[index][i]) {
				dis[i] = dis[index] + length[index][i];
				dispath[i] = index;
				distime[i] = distime[index] + Time[index][i];
			}
			else if (dis[i] == dis[index] + length[index][i] && distime[i] > distime[index] + Time[index][i]) {
				dispath[i] = index;
				distime[i] = distime[index] + Time[index][i];
			}
		}
	}
	/*dijkstra -l½áÊø,dijkstra-t¿ªÊ¼*/
	vector<bool>hourvisit(Nv);
	vector<int>hour(Nv, Inf);
	vector<int>hourtrans(Nv, Inf);
	vector<int>hourpath(Nv, -1);
	hour[ori] = 0; hourtrans[ori] = 0;
	while (1) {
		int index = -1, min = Inf;
		for (int i = 0; i < Nv; i++) {
			if (hourvisit[i] == false && hour[i] < min) {
				min = hour[i];
				index = i;
			}
		}
		if (index == des || index == -1)
			break;
		hourvisit[index] = true;
		for (int i = 0; i < Nv; i++) {
			if (hour[i] > hour[index] + Time[index][i]) {
				hour[i] = hour[index] + Time[index][i];
				hourpath[i] = index;
				hourtrans[i] = hourtrans[index] + 1;
			}
			else if (hour[i] == hour[index] + Time[index][i] && hourtrans[i] > hourtrans[index] + 1) {
				hourpath[i] = index;
				hourtrans[i] = hourtrans[index] + 1;
			}
		}
	}
	if (hourpath == dispath) {
		printf("Distance = %d; Time = %d: ", dis[des], hour[des]);
		Print(des, dispath);
	}
	else {
		printf("Distance = %d: ", dis[des]);
		Print(des, dispath); printf("\n");
		printf("Time = %d: ", hour[des]);
		Print(des, hourpath);
	}
}
void Print(int des, vector<int>P)
{
	if (P[des] != -1) {
		Print(P[des], P);
		printf(" -> %d", des);
	}
	else
		printf("%d", des);
}