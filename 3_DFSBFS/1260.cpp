/*BFS DFS*/

#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

vector< vector<int> > g;
vector<bool> visited;
stack<int> s;
queue<int> q;

void dfs(int v){
    visited[v]=true;
    cout<<v<<' ';
    for(vector<int>::iterator it=g[v].begin(); it!=g[v].end(); it++)
        if(!visited[*it]) 
            dfs(*it);
}
void bfs(int v){
    visited[v]=true;
    q.push(v);
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        cout<<curr<<' ';
        for(vector<int>::iterator it=g[curr].begin(); it!=g[curr].end(); it++){
            if(!visited[*it]) {
                visited[*it]=true;  
                q.push(*it);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n,m,v, a,b;
    cin>>n>>m>>v;

    g.resize(n+1);
    visited.resize(n+1);

    while(m--){
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i=1; i<=n ;i++){
        sort(g[i].begin(), g[i].end());
    }

    fill(visited.begin(),visited.end(),false);
    dfs(v); cout<<"\n";
    fill(visited.begin(),visited.end(),false);
    bfs(v); cout<<"\n";

    return 0;
}