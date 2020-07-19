#include<iostream>
#include<string>
using namespace std;
int main()
{
    int N, a, b;
    string test; 
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        cin >> test;
        a = stoi(test.substr(0, test.length() / 2));
        b = stoi(test.substr(test.length() / 2));
        a *= b;
        if (a&&stoi(test) %a )
            printf("No\n");
        else
            printf("Yes\n");

    }
}
/*送分？*/