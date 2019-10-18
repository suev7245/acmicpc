//아기상어
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

struct Shark{
    int y, x, z;
    Shark(){}
    Shark(int ty, int tx, int tz){
        y=ty, x=tx, z=tz;
    }
};
struct P{
    int y, x;
    P(int ty, int tx){
        y=ty, x=tx;
    }
};

int N, dab;
int arr[20][20];
Shark baby;

int visited[20][20];
int dy[]={-1,0,1,0};
int dx[]={0,1,0,-1};

int caldist(int i,int j){
    queue<P> q;
    int cnt=0, y, x, ny, nx;
    memset(visited, 0, sizeof(visited));

    q.push(P(i,j));
    visited[i][j]=1;//1부터 시작이니까 결과에서 -1해서 리턴해줘야함.

    while(!q.empty()){
        y=q.front().y; x=q.front().x; q.pop();
        // cout<<y<<","<<x<<" ";
        if(y==baby.y && x==baby.x) return visited[y][x]-1;

        for(int dir=0;dir<4;dir++){
            int ny= y+dy[dir];
            int nx= x+dx[dir];
            if(ny<0||ny>=N||nx<0||nx>=N||visited[ny][nx]) continue;
            // cout<<ny<<","<<nx<<" " ;
            if(arr[ny][nx]>baby.z) {
                visited[ny][nx]=1; //사이즈 크면 어떤 경우에도 어차피 못감.
                continue;
            }

            q.push(P(ny, nx));
            visited[ny][nx]=visited[y][x]+1;
        }
    }
    return 1e9;//못감
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>arr[i][j];
            if(arr[i][j]==9){
                baby.y=i; baby.x=j; baby.z=2;
                arr[i][j]=0;
            }
        }
    }

    bool nomore=true;
    int mini,miny,minx,temp,eat=0;
    while(nomore){
        nomore=false;
        mini=1e9;

        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(arr[i][j] && arr[i][j]<baby.z) {
                    temp = caldist(i,j);
                    // cout<<temp<<" ";
                    // for(int k=0;k<N;k++){
                    //     for(int kk=0;kk<N;kk++){
                    //         cout<<visited[k][kk]<<" ";
                    //     }cout<<"\n";
                    // }
                    if(mini>temp){
                        mini = temp;
                        miny=i;
                        minx=j;
                    }
                }
            }
        }
        //먹을게 있으면
        if(mini!=1e9) {
            nomore=true; 
            dab+=mini;
            eat++;
            baby.y=miny;
            baby.x=minx;
            arr[miny][minx]=0;

            if(eat==baby.z){
                baby.z++;
                eat=0;
            }
        }
    }

    cout<<dab;
    
    return 0;
}
