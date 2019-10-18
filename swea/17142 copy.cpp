//연구소3
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

struct Point{
    int y,x;
    Point(int ty, int tx){
        y=ty, x=tx;
    }
};

int N,M, dab=-1;
int arr_ori[50][50];
int arr[50][50];
bool visited_ori[50][50];
bool visited[50][50];
vector<Point> virus;
vector<Point> selected;

int dy[]={-1,0,1,0};
int dx[]={0,1,0,-1};

int spread(){
    memcpy(arr, arr_ori, sizeof(arr));
    memcpy(visited, visited_ori, sizeof(visited));
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<arr[i][j]<<" ";
        }cout<<"\n";
    }


    queue<Point> q;
    for(int i=0;i<3;i++){
        q.push(selected[i]);
        arr[selected[i].y][selected[i].x]=0;
        visited[selected[i].y][selected[i].x]=true;
    }

    int x,y,nx,ny, result=0;
    while(!q.empty()){
        y=q.front().y; x=q.front().x; q.pop();
        if(result<arr[y][x]) result=arr[y][x];

        for(int i=0;i<4;i++){
            ny=y+dy[i]; nx=x+dx[i];
            if(ny<0||ny>=N||nx<0||nx>=N||visited[ny][nx]) continue;

            q.push(Point(ny,nx));
            arr[ny][nx]=arr[y][x]+1;
            visited[ny][nx]=true;
        }
    }

    if(result<5){
        cout<<"\n\n";
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cout<<arr[i][j]<<" ";
            }cout<<"\n";
        }
    }
    

    int i,j;
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            if(!visited[i][j]) return -1;
        }
    }cout<<result<<" ";
    return result-1;
}

void combi(int pos, int cnt){
    if(cnt==M){
        int sp =spread();
        if(dab==-1) dab=sp;
        else if(sp!=-1){
            if(dab>sp) dab=sp;
        }
        return;
    }
    for(int i=pos; i<virus.size();i++){
        selected.push_back(virus[i]);
        combi(i+1, cnt+1);
        selected.pop_back();
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>N>>M;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>arr_ori[i][j];
            if(arr_ori[i][j]==2) {
                arr_ori[i][j]=-1;
                virus.push_back(Point(i,j));
            }else if(arr_ori[i][j]==1) 
                visited_ori[i][j]=true;
        }
    }
    combi(0,0);
    cout<<dab;
} 