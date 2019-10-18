//연구소3
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <cstring>

using namespace std;

struct Point{
    int y, x;
    Point(int ty, int tx){
        y=ty, x=tx;
    }
};

int N,M,dab=1e9;
int arr[50][50];
int arr_ori[50][50];
int visited[50][50];
int visited_ori[50][50];
vector<Point> virus;
vector<Point> selected;

int dy[]={-1,0,1,0};
int dx[]={0,1,0,-1};

int bfs(){
    queue<Point> q;
    int maxi=0;
    memcpy(arr, arr_ori, sizeof(arr));
    memcpy(visited, visited_ori, sizeof(visited));
    for(int i=0;i<selected.size();i++){
        q.push(selected[i]);
        arr[selected[i].y][selected[i].x]=0;
        visited[selected[i].y][selected[i].x]=true;
    }

    int x,y,ny,nx;
    while(!q.empty()){
        y= q.front().y; 
        x= q.front().x; 
        q.pop();

        for(int i=0;i<4;i++){
            ny=y+dy[i];nx=x+dx[i];
            if(ny<0||ny>=N||nx<0||nx>=N|| visited[ny][nx]) continue;
            
            if(arr[ny][nx]==0)//빈칸으로 전염됐을떄만 maxi 갱신.
                maxi = arr[y][x]+1;

            arr[ny][nx]=arr[y][x]+1;
            visited[ny][nx]=true;
            q.push(Point(ny,nx));

        }

    }
    //없으면 
    //visited배열 전부 트루면
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(!visited[i][j]) return 1e9;
        }
    }
    //아니면
    // for(int i=0;i<N;i++){
    //     for(int j=0;j<N;j++){
    //         cout<<arr[i][j]<<" ";
    //     }cout<<"\n";
    // }cout<<"maxi: "<<maxi;
    return maxi;
}

void combi(int pos, int cnt){
    if(cnt==M){
        // cout<<"\n\ng";
        // for(int i=0;i<selected.size();i++)cout<<selected[i].y<<","<<selected[i].x<<"/ ";
        dab = min(dab, bfs());
        // cout<<"dab: "<<dab;
        return;
    }
    for(int i=pos; i<virus.size(); i++){
        selected.push_back(virus[i]);
        combi(i+1, cnt+1);
        selected.pop_back();
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin>>N>>M;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>arr_ori[i][j];
            if(arr_ori[i][j]==2) virus.push_back(Point(i,j));
            else if(arr_ori[i][j]==1) visited_ori[i][j]=true;
        }
    }
    // cout<<"f"<<virus.size();

    combi(0,0);

    if(dab!=1e9) cout<<dab;
    else cout<<-1;
}