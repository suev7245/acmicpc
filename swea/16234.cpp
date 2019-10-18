//인구이동 - visited 배열 초기화해주기. arr 배열 두개 두기. 
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

struct Point{
    int y,x;
    Point(int ty, int tx){
        y=ty, x=tx;
    }
};

int N,L,R, dab, cnt, total;
int arr[50][50];
int arrc[50][50];
bool visited[50][50];
bool can_do;
vector<Point> v;

int dy[]={-1,0,1,0};
int dx[]={0,1,0,-1};


void dfs(int y, int x){
    visited[y][x]=true;
    v.push_back(Point(y,x));
    cnt++; total+=arr[y][x];

    int ny, nx, temp;
    for(int dir=0; dir<4; dir++){
        ny= y+dy[dir];
        nx= x+dx[dir];
        
        if(ny<0||ny>=N||nx<0||nx>=N||visited[ny][nx]) continue;
        temp=abs(arr[y][x]-arr[ny][nx]);
        if(L<=temp && temp<=R){
            dfs(ny,nx);
        }
    }
}

void solve(){
    while(can_do){
        can_do=false;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(!visited[i][j]){
                    cnt=total=0;
                    v.clear();
                    dfs(i,j);
                    if(cnt>1){//인구이동 일어남
                        can_do=true;
                        int value = total/cnt;
                        for(int m=0; m<v.size(); m++){
                            arrc[v[m].y][v[m].x]=value;
                        }
                    }else{
                        arrc[i][j]=arr[i][j];
                    }
                }
            }
        }
        memcpy(arr, arrc, sizeof(arr));
        memset(arrc,0,sizeof(arrc));
        memset(visited,0,sizeof(visited));
        dab++;
        // for(int i=0;i<N;i++){
        //     for(int j=0;j<N;j++){
        //         cout<<arr[i][j]<<" ";
        //     }cout<<"\n";
        // }cout<<"\n";
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>N>>L>>R;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>arr[i][j];
        }
    }

    can_do=true;
    solve();

    cout<<dab-1;
} 