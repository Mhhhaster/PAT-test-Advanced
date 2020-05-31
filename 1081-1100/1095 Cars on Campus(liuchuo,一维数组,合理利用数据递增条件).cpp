#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
using namespace std;
struct node {
    char id[10];
    int time, flag = 0;
};
bool cmp1(node a, node b) {
    if (strcmp(a.id, b.id) != 0)
        return strcmp(a.id, b.id) < 0;
    else
        return a.time < b.time;
}
bool cmp2(node a, node b) {
    return a.time < b.time;
}
int main() {
    int n, k, maxtime = -1, tempindex = 0;
    scanf("%d%d\n", &n, &k);
    vector<node> record(n), car;
    for (int i = 0; i < n; i++) {
        char temp[5];
        int h, m, s;
        scanf("%s %d:%d:%d %s\n", record[i].id, &h, &m, &s, temp);
        int temptime = h * 3600 + m * 60 + s;
        record[i].time = temptime;
        record[i].flag = strcmp(temp, "in") == 0 ? 1 : -1;
    }
    sort(record.begin(), record.end(), cmp1);//直接对每条出入信息排序，先按名字再按时间
    map<string, int> mapp;
    for (int i = 0; i < n - 1; i++) {
        if (strcmp(record[i].id, record[i + 1].id) == 0 && record[i].flag == 1 &&
            record[i + 1].flag == -1) {
            car.push_back(record[i]);
            car.push_back(record[i + 1]);//过滤留下合法数据
            mapp[record[i].id] += (record[i + 1].time - record[i].time);//每个名字对应着一个总时长
            if (maxtime < mapp[record[i].id]) {
                maxtime = mapp[record[i].id];//同时统计最大时长
            }
        }
    }
    sort(car.begin(), car.end(), cmp2);//这次按时间排序，存于car中
    vector<int> cnt(n);
    for (int i = 0; i < car.size(); i++) {
        if (i == 0)
            cnt[i] += car[i].flag;
        else
            cnt[i] = cnt[i - 1] + car[i].flag;
    }//cnt统计每个进出时间结点的车辆情况，(可应用回自己程序改进)
    for (int i = 0; i < k; i++) {
        int h, m, s;
        scanf("%d:%d:%d", &h, &m, &s);
        int temptime = h * 3600 + m * 60 + s;
        int j;
        for (j = tempindex; j < car.size(); j++) {
            if (car[j].time > temptime) {
                printf("%d\n", cnt[j - 1]);
                break;
            }
            else if (j == car.size() - 1) {//当进时，该车也算进去
                printf("%d\n", cnt[j]);
            }
        }
        tempindex = j;//重点理解：时间递增，所以也要将记录按递增排序，找到一个更大的就可以计算了
    }
    for (map<string, int>::iterator it = mapp.begin(); it != mapp.end(); it++) {
        if (it->second == maxtime)
            printf("%s ", it->first.c_str());
    }
    printf("%02d:%02d:%02d", maxtime / 3600, (maxtime % 3600) / 60, maxtime %60);
    return 0;
}