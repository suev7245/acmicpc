/*
단지번호붙이기
*/

#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

string map[25];
bool visited[25][25];
stack<int> s;

int n;
int cnt;
vector<int> cntarr;

int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};


void dfs(int x, int y){
    visited[x][y]=true;
    cnt++;
    for(int i=0;i<4;i++){
        if(x+dx[i]<0||x+dx[i]>=n || y+dy[i]<0||y+dy[i]>=n) 
            continue;
        if(!visited[x+dx[i]][y+dy[i]] && map[x+dx[i]][y+dy[i]]=='1') 
            dfs(x+dx[i], y+dy[i]);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>map[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if (!visited[i][j] && map[i][j]=='1'){
                cnt=0;
                dfs(i,j);
                cntarr.push_back(cnt);
            }
        }
    }

    cout<<cntarr.size()<<"\n";
    sort(cntarr.begin(),cntarr.end());
    for(int i=0;i<cntarr.size();i++)
        cout<<cntarr[i]<<"\n";

    return 0;
}