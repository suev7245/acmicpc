/*최대 힙*/

#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdlib>
using namespace std;

struct Comp{
    bool operator()(int a, int b){
        if(abs(a)==abs(b)) return a>b;
        
        return abs(a)>abs(b);
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, n;
    priority_queue<int,vector<int>,Comp> minheap;

    cin>>N;
    while(N--){
        cin>>n;
        if(n!=0) minheap.push(n);
        else if(!minheap.empty()){ cout<<minheap.top()<<"\n"; minheap.pop(); }
        else cout<<"0\n";
    }
    return 0;
}