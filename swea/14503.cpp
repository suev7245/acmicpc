/*로봇 청소기 - 1:07*/

#include <iostream>
#include <vector>
using namespace std;
int map[50][50];
int n,m,r,c,d,cnt;
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};

void clean(int y, int x, int d){
    if(map[y][x]==0){
        map[y][x]=2;
        cnt++;
    }

    int ny=y, nx=x, nd=d;
    for(int i=0;i<4;i++){
        nd=(nd+3)%4;
        ny=y+dy[nd];
        nx=x+dx[nd];
        if(ny<0||ny>=n||nx<0||nx>=m) continue;

        if(map[ny][nx]==0){
            clean(ny,nx,nd);
            break;
        }

        if(i==3){
            ny = y+dy[(d+2)%4];
            nx = x+dx[(d+2)%4];
            if(ny<0||ny>=n||nx<0||nx>=m) break;

            if(map[ny][nx]==1) break;
            clean(ny,nx,d);
        }
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    cin>>n>>m>>r>>c>>d;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin>> map[i][j];
    clean(r,c,d);
    cout<<cnt;
}