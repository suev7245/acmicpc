/*
미로탐색 - 최단거리
*/

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

string map[100];
int visited[100][100];

int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};

queue<pair<int,int> > q;
int n,m;

void bfs(){
    while(!q.empty()){
        int cury = q.front().first;
        int curx = q.front().second;
        q.pop();

        if(cury==n && curx==m)
            break;
        
        for(int i=0; i<4; i++){
            int ny = cury+dy[i];
            int nx = curx+dx[i];
            if(nx<0||nx>m||ny<0||ny>n) 
                continue;

            if(map[ny][nx]=='1' && visited[ny][nx]==0){
                q.push(make_pair(ny,nx));
                visited[ny][nx]=visited[cury][curx]+1;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin>>n>>m;
    n--;m--; // 1,1에서 n,m인데 0,0에서로 받기 위해 n-1,m-1

    for(int i=0;i<=n;i++) 
        cin>>map[i];

    q.push(make_pair(0,0));
    visited[0][0]=1;
    bfs();
    cout<<visited[n][m];

    return 0;
}