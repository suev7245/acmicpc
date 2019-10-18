//미세먼지 안녕
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

struct Point{
    int y,x;
};

int dy[]={0,-1,0,1};
int dx[]={1,0,-1,0};

int R,C,T;
int map[50][50];
int temp[50][50];
Point p1, p2, now, before;

void clean(){
    int i;
    for(i=p1.y-1;i>0;i--) map[i][0]=map[i-1][0];
    for(i=0;i<C-1;i++) map[0][i]=map[0][i+1];
    for(i=0;i<p1.y;i++) map[i][C-1]=map[i+1][C-1];
    for(i=C-1;i>1;i--) map[p1.y][i]=map[p1.y][i-1];
    map[p1.y][1]=0;
    for(i=p2.y+1;i<R-1;i++) map[i][0]=map[i+1][0];
    for(i=0;i<C-1;i++) map[R-1][i]=map[R-1][i+1];
    for(i=R-1;i>p2.y;i--) map[i][C-1]=map[i-1][C-1];
    for(i=C-1;i>1;i--) map[p2.y][i]=map[p2.y][i-1];
    map[p2.y][1]=0;
}

// int dir;
// void before1(){
//     while(true){
//         before.y=now.y+dy[dir];
//         before.x=now.x+dx[dir];
//         if(before.x<0||before.x>=C||before.y<0|| before.y>p1.y){
//             dir=(dir+3)%4;
//             before.y=now.y+dy[dir];
//             before.x=now.x+dx[dir];
//         }
//         if(map[now.y][now.x]!=-1)//청정기로 빨려들어가는거
//             map[now.y][now.x]=map[before.y][before.x];
//         if(map[before.y][before.x]==-1){//청정기에서 나오는거
//             map[now.y][now.x]=0;
//             break;
//         }
//         now=before;
//     }
// }
// void before2(){
//     while(true){
//         before.y=now.y+dy[dir];
//         before.x=now.x+dx[dir];
//         if(before.x<0||before.x>=C||before.y>=R|| before.y<p2.y){
//             dir=(dir+1)%4;
//             before.y=now.y+dy[dir];
//             before.x=now.x+dx[dir];
//         }
//         if(map[now.y][now.x]!=-1)//청정기로 빨려들어가는거
//             map[now.y][now.x]=map[before.y][before.x];
//         if(map[before.y][before.x]==-1){//청정기에서 나오는거
//             map[now.y][now.x]=0;
//             break;
//         }
//         now=before;
//     }
// }

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>R>>C>>T;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cin>>map[i][j];
            if(map[i][j]==-1){
                if(p1.y==0) {
                    p1.y=i; p1.x=j;
                }else{
                    p2.y=i; p2.x=j;
                }
            }
        }
    }

    while(T--){
        memset(temp, 0, sizeof(temp));
        int div, total, nx,ny;
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                if(map[i][j]){
                    div=map[i][j]/5;
                    total=0;

                    for(int ii=0;ii<4;ii++){
                        ny=i+dy[ii];
                        nx=j+dx[ii];
                        if(ny<0||ny>=R||nx<0||nx>=C|| map[ny][nx]==-1) continue;

                        temp[ny][nx]+=div;
                        total+=div;
                    }
                    temp[i][j]-=total;
                }
            }
        }
        //확산
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                map[i][j]+= temp[i][j];
            }
        }

        clean();
        // //이동
        // now.y=p1.y; now.x=p1.x; dir=2;
        // before1();
        // now.y=p2.y; now.x=p2.x; dir=2;
        // before2();
        // cout<<"\n\n";
        // for(int i=0;i<R;i++){
        //     for(int j=0;j<C;j++){
        //         cout<<map[i][j]<<" ";
        //     }cout<<"\n";
        // }

    }

    int dab=0;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            dab+= map[i][j];
        }
    }cout<<dab+2;
} 