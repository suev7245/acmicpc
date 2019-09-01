/*가운데 말해요*/

#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
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

    set<int> s;
    s.insert(40);
    s.insert(20);
    s.insert(30);
    s.insert(25);
    s.insert(70);
    s.insert(60);
    s.insert(80);
    s.insert(10);
    s.insert(42);
    s.insert(23);

    for(set<int>::iterator it=s.begin(); it!=s.end(); it++)
        cout<<*it<<" ";
    cout<<"\n";

    cout<<s[4];
    
    // int N, n;
    // priority_queue<int,vector<int>,Comp> minheap;

    // cin>>N;
    // while(N--){
    //     cin>>n;
    //     if(n!=0) minheap.push(n);
    //     else if(!minheap.empty()){ cout<<minheap.top()<<"\n"; minheap.pop(); }
    //     else cout<<"0\n";
    // }
    return 0;
}