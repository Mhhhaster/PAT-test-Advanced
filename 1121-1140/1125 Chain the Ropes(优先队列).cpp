#include<iostream>
#include<queue>
using namespace std;
int main()
{
    int N;
    scanf("%d",&N);
    priority_queue<int,vector<int>,greater<int>>Q;
    int temp=0;
    while(N--)
    {
        scanf("%d",&temp);
        Q.push(temp);
    }
    int length=Q.top();
    Q.pop();
    while(!Q.empty())
    {
        temp=Q.top();
        Q.pop();
        length=(length+temp)/2;
    }
    printf("%d",length);
    return 0;
}
/*水得就离谱，会用优先队列就行
BTW，优先队列中的cmp与sort不同，为结构体形式
struct cmp{
	bool operator()  (Node a,Node b){
		if(a.i==b.i)
			return a.j>b.j;//大于号为前>后，所以表明降序，sort中同理
		else
			return a.i>a.i;
}
}
*/