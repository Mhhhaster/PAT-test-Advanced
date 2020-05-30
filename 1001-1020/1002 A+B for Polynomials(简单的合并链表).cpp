#include<iostream>
#include<vector>
using namespace std;
struct Node
{
    int expon;
    float coef;
};
int main()
{
    vector<Node>A;
    vector<Node>B;
    int Anum, Bnum;
    cin >> Anum;
    int expon;
    float coef;
    for (int i = 0; i < Anum; i++)
    {
        cin >> expon >> coef;
        A.push_back({ expon,coef });
    }
    cin >> Bnum;
    for (int i = 0; i < Bnum; i++)
    {
        cin >> expon >> coef;
        B.push_back({ expon,coef });
    }
    vector<Node>sum;
    int ptrA = 0, ptrB = 0;
    while (ptrA < A.size() && ptrB < B.size())//prtA、B分别指示位置
    {
        if (A[ptrA].expon > B[ptrB].expon)//a的指数更大，复制a的内容
        {
            sum.push_back(A[ptrA]);
            ptrA++;
        }
        else if (A[ptrA].expon < B[ptrB].expon)
        {
            sum.push_back(B[ptrB]);
            ptrB++;
        }
        else
        {
            float add = A[ptrA].coef + B[ptrB].coef;
            if (add)
            {
                sum.push_back({ B[ptrB].expon,add });
            }
            ptrA++;
            ptrB++;
        }
    }
    while (ptrA < A.size())sum.push_back(A[ptrA++]);
    while (ptrB < B.size())sum.push_back(B[ptrB++]);
    cout << sum.size();
    for (int i = 0; i < sum.size(); i++)
    {
        printf(" %d %.1f", sum[i].expon, sum[i].coef);
    }
    return 0;
}
