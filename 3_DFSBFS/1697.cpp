/*
숨바꼭질 - (-1 +1 *2) 이렇게 움직일 수 있는 x가 y로 도착하는 가장 빠른 걸음
*/

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define MAX 100001

queue<int> q;
int visited[MAX];
int n,k;

void bfs(){
    while(!q.empty()){
        int cur =q.front(); q.pop();
        if(cur==k) break;

        int next;
        next = cur-1; 
        if(next>=0 && next<=MAX && !visited[next]) {
            q.push(next);
            visited[next] = visited[cur]+1;
        }

        next = cur+1;
        if(next>=0 && next<=MAX && !visited[next]) {
            q.push(next);
            visited[next] = visited[cur]+1;
        }

        next = cur*2;
        if(next>=0 && next<=MAX && !visited[next]) {
            q.push(next);
            visited[next] = visited[cur]+1;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin>>n>>k;

    q.push(n); visited[n]=1; 
    bfs(); 

    cout<<visited[k]-1;

    return 0;
}