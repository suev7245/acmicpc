/*
벽 부수고 이동하기 
: 최대 하나의 벽만 부수고 이동가능 
0(이동가능)1(벽)의 map에서 
좌상에서 우하로 가는 최단거리.

- 처음엔 그냥 bfs로 벽부술수 있는변수 하나 더 두고 풀려고 했으나 이런 경우, 최단거리로 어떤 곳을 방문해 visited가 true 되어 다른 경우에는 방문하지 못하는데, 얘가 나아가서 더이상 목적지까지 가지 못할때 이때는 돌아서라도 가는방법이 있다면 그것을 답으로 푸는게 맞으므로 
- 한 곳에 방문할 때, 벽을 뚫고 온경우와 벽을 뚫지 않고 온 경우 두가지 모두 받아들일 수 있게 한다. 즉 한 곳에 방문을 최대 2번 할 수 있다는 말.
*/

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

string map[1000]; //0-index
int visited[1000][1000][2];
int n,m;
struct Wall
{
    int y,x,c;//c는 벽 뚫은 유무 체크 변수 - visited마지막 인덱스로 쓸 것. 0(안뚫음) 1(뚫음)
    Wall(int y, int x, int c): y(y), x(x), c(c){};
};

int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};


int bfs(){
    queue<Wall> q;
    q.push(Wall(0,0,0));
    visited[0][0][0]=1; //[i][j][0]은 벽 안뚫고 (i,j)까지 최단거리 저장 // [i][j][1]은 뚫고 (i,j)까지 최단거리 저장.
    while(!q.empty()){
        int cury= q.front().y;
        int curx= q.front().x;
        int curc= q.front().c;
        q.pop();
        if(cury==n-1 && curx==m-1) return visited[cury][curx][curc];

        for(int i=0;i<4;i++){
            int ny = cury + dy[i];
            int nx = curx + dx[i];
            
            if( ny<0 || ny>=n || nx<0 || nx>=m || visited[ny][nx][curc])
                continue;
            
            if(map[ny][nx]=='0'){//이동가능
                q.push(Wall(ny,nx,curc));
                visited[ny][nx][curc]=visited[cury][curx][curc]+1;
            }else if(curc==0){//벽을 만났는데 안뚫은 상태 
                q.push(Wall(ny,nx,1));
                visited[ny][nx][1]=visited[cury][curx][curc]+1;
            }
        }
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>map[i];
    cout<<bfs();

    return 0;
}