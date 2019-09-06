/*
토마토 - bfs 처음 input 받을때 모든 시작점 큐에 넣어주어야함 - 동시에 퍼질때 최단시간 구하기!.
*/

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int map[1000][1000];
int visited[1000][1000];

int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};

queue<pair<int,int> > q;
int n,m;

void bfs(){
    while(!q.empty()){
        int cury = q.front().first;
        int curx = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int ny = cury + dy[i];
            int nx = curx + dx[i];  

            if(nx<0||nx>=m||ny<0||ny>=n) 
                continue;               
            
            if(map[ny][nx]>=0 && visited[ny][nx]==0){
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
    
    //입력받기
    cin>>m>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            cin>>map[i][j];
            if(map[i][j]==1) {q.push(make_pair(i,j)); visited[i][j]=1;}
            if(map[i][j]==-1) visited[i][j]=-1;
        }
    bfs();

    //전체배열돌려가며 최대값 및 0있는지 확인(0있으면 전체 확산 불가)
    bool no=false;
    int largest=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(largest<visited[i][j])
                largest=visited[i][j];
            if(visited[i][j]==0){
                no=true;
                break;
            }
        }
    }
    if(no) cout<<"-1";
    else cout<<largest-1;

    return 0;
}