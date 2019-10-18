//낚시왕
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Shark{
    int s,d,z;
    Shark(){}
    Shark(int ts,int td, int tz){
        s=ts, d=td, z=tz;
    }
};

void up(int i, int j, Shark now);
void down(int i, int j, Shark now);
void left(int i, int j, Shark now);
void right(int i, int j, Shark now);


int R,C,M, dab;
int cur=0, nex=1;//0,1
Shark arr[2][100][100];

int dy[]={-1,0,1,0};
int dx[]={0,1,0,-1};

void up(int ty, int j, Shark now){
    if(ty<0){
        ty *= -1;
        now.d=2;
        down(ty,j,now);
    }else{
        if(arr[nex][ty][j].z<now.z){
            arr[nex][ty][j]=now;
        }
    }
}
void down(int ty, int j, Shark now){
    ty %= 2*(R-1);
    if(ty>=(R-1)){
        now.d=1;
        ty -= (R-1);
        ty = R-1 - ty;
    }
    if(arr[nex][ty][j].z<now.z){
        arr[nex][ty][j]=now;
    }
}
void left(int i, int tx, Shark now){
    if(tx<0){
        tx *= -1;
        now.d=3;
        right(i,tx,now);
    }else{
        if(arr[nex][i][tx].z<now.z){
            arr[nex][i][tx]=now;
        }
    }
}
void right(int i, int tx, Shark now){
    tx %= 2*(C-1);
    if(tx>=(C-1)){
        now.d=4;
        tx -= (C-1);
        tx = C-1 - tx;
    }
    if(arr[nex][i][tx].z<now.z){
        arr[nex][i][tx]=now;
    }
}

void move(){
    //nex배열 초기화
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            arr[nex][i][j].z=0;
        }
    }

    //move
    Shark now;
    int ty, tx;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(arr[cur][i][j].z){
                now = arr[cur][i][j];
                //위쪽 방향
                switch (now.d){
                    case 1:
                        up(i-now.s,j,now);
                        break;
                    case 2:
                        down(i+now.s,j,now);
                        break;
                    case 3:
                        right(i,j+now.s,now);
                        break;
                    case 4:
                        left(i,j-now.s,now);
                        break;
                }
            }
        }
    }

    nex = cur;
    cur = (cur+1)%2;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>R>>C>>M;
    int r,c,s,d,z;
    for(int i=0;i<M;i++){
        cin>>r>>c>>s>>d>>z;
        arr[0][r-1][c-1]=Shark(s,d,z);
    }

    for(int j=0;j<C;j++){
        // for(int i=0;i<R;i++){
        //     for(int j=0;j<C;j++){
        //         cout<<arr[cur][i][j].z<<" ";
        //     }cout<<"\n";
        // }cout<<"\n";

        //상어먹음
        for(int i=0;i<R;i++){
            if(arr[cur][i][j].z){
                dab+=arr[cur][i][j].z;
                arr[cur][i][j].z=0;
                break;//땅이랑 가까운 하나만 먹을 수 있음.
            }
        }
        //상어이동
        move();
    }

    cout<<dab;

    return 0;
}