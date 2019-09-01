/*
N번쨰 큰 수

N×N의 표에 수 N2개 채워져 있다. 채워진 수에는 한 가지 특징이 있는데, 모든 수는 자신의 한 칸 위에 있는 수보다 크다

N번째 큰 수를 찾는 프로그램
*/

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

void printheap(priority_queue<int, vector<int>, greater<int> > heap){
    while(!heap.empty()){
        cout<< heap.top()<<" ";
        heap.pop();
    }   
    cout<<"\n\n";
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, temp;
    priority_queue<int, vector<int>, greater<int> > minheap;

    cin>>n;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++){
            cin>>temp;
            minheap.push(temp);
            if(minheap.size()>n) minheap.pop();
        }
        cout<<minheap.top();
    return 0;
}