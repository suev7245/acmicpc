//연구소
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int N,M,NM,novirus,result=1e9;
int map[8][8];
vector< pair<int,int> > selected;
vector< pair<int,int> > virus;
bool visited[8][8];
queue< pair<int,int> > q;

int dy[]={-1,1,0,0};
int dx[]={0,0,-1,1};

int bfs(int i, int j){
    visited[i][j]=true;
    q.push(make_pair(i,j));
    int x,y,nx,ny, virusnum=0;

    while(!q.empty()){
        y = q.front().first;
        x = q.front().second;
        q.pop();
        for(int dir=0;dir<4;dir++){
            ny = y + dy[dir];
            nx = x + dx[dir];
            if(ny<0 || ny>=N || nx<0 || nx>=M) continue;

            if(!visited[ny][nx] && map[ny][nx]==0) {
                visited[ny][nx]=true;  
                virusnum++;
                q.push(make_pair(ny,nx));
            }
        }
    }

    return virusnum;
}

int calsafe(){
    int virusnum=0;
    for(int i=0;i<virus.size();i++){
       virusnum += bfs(virus[i].first,virus[i].second);
    }
    return virusnum;
}


void combi(int pos, int cnt){
    if(cnt==3){
        // for(int i=0;i<N;i++)
        //     for(int j=0;j<M;j++)
        //         visited[i][j]=false;
        memset(visited, false, sizeof(visited));

        for(int i=0;i<3;i++) map[selected[i].first][selected[i].second]=1;    
        result = min(result, calsafe());
        for(int i=0;i<3;i++) map[selected[i].first][selected[i].second]=0;
        
        return;
    }

    int i,j;
    for(int now=pos;now<NM;now++){
        i=now/M;
        j=now%M;
        if(map[i][j]==0){
            selected.push_back(make_pair(i,j));
            combi(now+1, cnt+1);
            selected.pop_back();
        }   
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>N>>M;
    NM=N*M;
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++){
            cin>>map[i][j];
            if(map[i][j]==2) virus.push_back(make_pair(i,j));
            if(map[i][j]==0) novirus++;
        }
    

    combi(0,0);
    cout<<novirus-result-3;
} 