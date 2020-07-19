#include <iostream>
#include <string>
#include <vector>
using namespace std;
string num[10] = { "ling","yi", "er", "san", "si", "wu", "liu", "qi", "ba",
"jiu" };
string c[6] = { "Ge","Shi", "Bai", "Qian", "Yi", "Wan" };
int J[] = { 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000 };
vector<string> res;
int main() {
    int n;
    cin >> n;
    if (n == 0) {
        cout << "ling";
        return 0;
    }
    if (n < 0) {
        cout << "Fu ";
        n = -n;
    }
    /*统一为正数*/
    int part[3];
    part[0] = n / 100000000;
    part[1] = (n % 100000000) / 10000;
    part[2] = n % 10000;
    /*分为三部分单独处理*/
    bool zero = false; //是否在⾮零数字前输出合适的ling
    int printCnt = 0; //⽤于维护单词前没有空格，之后输⼊的单词都在前⾯加⼀个空格。
    for (int i = 0; i < 3; i++) {
        int temp = part[i]; //三个部分，每部分内部的命名规则都⼀样，都是X千X百X⼗X
        for (int j = 3; j >= 0; j--) {
            int curPos = 8 - i * 4 + j; //当前数字的位置
            if (curPos >= 9) continue; //最多九位数
            int cur = (temp / J[j]) % 10;//取出当前数字
            if (cur != 0) {
                if (zero) {
                    printCnt++ == 0 ? cout << "ling" : cout << " ling";
                    zero = false;
                }//该数字不为零但前面有零
                if (j == 0)//为个位
                    printCnt++ == 0 ? cout << num[cur] : cout << ' ' <<num[cur]; 
                else//在其他位，还要输出⼗百千
                    printCnt++ == 0 ? cout << num[cur] << ' ' << c[j] : cout << ' ' << num[cur] << ' ' << c[j]; 
            }
            else if (!zero && j != 0 && n / J[curPos] >= 10) //0在两部分之间
                zero = true; //注意100020这样的情况
        }
        if (i != 2 && part[i] > 0)//该部分不为零且是头两部分，带上亿或万 
            cout << ' ' << c[i + 4]; //处理完每部分之后，最后输出单位，Yi / Wan
    }
    return 0;
}