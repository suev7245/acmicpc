/*
바이러스
1번 컴퓨터가 웜 바이러스에 걸렸을 때, 1번 컴퓨터를 통해 웜 바이러스에 걸리게 되는 컴퓨터의 수를 첫째 줄에 출력한다.
*/

#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

vector< vector<int> > g;
vector<bool> visited;
stack<int> s;
int cnt;

void dfs(int v){
    visited[v]=true;
    cnt++;
    for(vector<int>::iterator it=g[v].begin(); it!=g[v].end(); it++)
        if(!visited[*it]) dfs(*it);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n,m,a,b;
    cin>>n>>m;

    g.resize(n+1);
    visited.resize(n+1);
    fill(visited.begin(), visited.end(),false);

    while(m--){
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(1);
    cout<<cnt-1;

    return 0;
}