/*최대 힙*/

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, n;
    priority_queue<int,vector<int>,less<int> > maxheap;
    bool hmade=false;

    cin>>N;
    while(N--){
        cin>>n;
        if(n!=0) maxheap.push(n);
        else if(!maxheap.empty()){ cout<<maxheap.top()<<"\n"; maxheap.pop(); }
        else cout<<"0\n";
    }
    return 0;
}