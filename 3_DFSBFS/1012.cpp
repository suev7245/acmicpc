/*
유기농 배추 component 개수 구하기
*/

#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

bool map[50][50];
bool visited[50][50];

int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};

int m,n;

void init(){
    for(int i=0; i<50; i++){
        for(int j=0; j<50; j++){
            map[i][j]=false;
            visited[i][j]=false;
        }
    }
}

void dfs(int x, int y){
    visited[x][y]=true;
    for(int i=0;i<4;i++){
        if(x+dx[i]<0||x+dx[i]>=m || y+dy[i]<0||y+dy[i]>=n) 
            continue;
        if(!visited[x+dx[i]][y+dy[i]] && map[x+dx[i]][y+dy[i]]) 
            dfs(x+dx[i], y+dy[i]);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int T,k,x,y,cnt;
    cin>>T;

    while(T--){
        init();
        cin>>m>>n>>k;
        while(k--){
            cin>>x>>y;
            map[x][y]=true;
        }
        cnt = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!visited[i][j] && map[i][j]) {
                    cnt++;
                    dfs(i,j);
                }
            }
        }
        cout<<cnt<<"\n";
    }
    return 0;
}