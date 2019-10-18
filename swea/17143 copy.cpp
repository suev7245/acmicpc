//낚시왕
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <cstring>
using namespace std;

struct Shark{
    int y,x,s,d,z;
    Shark(int ty, int tx, int ts, int td, int tz){
        y=ty, x=tx, s=ts, d=td, z=tz;
    }
};

bool comp(const Shark &a, const Shark &b){
    if(a.x<b.x) return true;
    if(a.x==b.x){
        if(a.y<b.y) return true;
        if(a.y==b.y) return a.s>b.s;
    } 
    return false;
}

int R,C,M;
int cnt[100][100];
vector<Shark> v;
int dy[]={-1,1,0,0};
int dx[]={0,0,1,-1};

void rearrange(){
    int much,temp,dir;
    for(int i=0;i<v.size();i++){
        if(v[i].x==200) continue;
        
        if(v[i].d<2){//상하
            temp=v[i].y;
            much=v[i].s;
            dir=v[i].d;
            much%=2*R;
            while(much--){
                temp += dy[dir];
                if(temp==0||temp==R-1) dir= (dir+1)%2;
            }
            v[i].y=temp;
            v[i].d=dir;
        }else{//좌우
            temp=v[i].x;
            much=v[i].s;
            dir=v[i].d;
            much%=2*C;
            while(much--){
                temp += dx[dir];
                if(temp==0||temp==C-1) dir= (dir+1)%2+2;
            }
            v[i].x=temp;
            v[i].d=dir;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>R>>C>>M;
    int a,b,c,d,e;
    for(int i=0;i<M;i++){
        cin>>a>>b>>c>>d>>e;
        v.push_back(Shark(a-1,b-1,c,d-1,e));
    }

    int result=0, tempy, tempx;
    for(int i=0;i<C;i++){
        sort(v.begin(), v.end(),comp);
        for(int ii=0;ii<v.size() && v[ii].x<=i;ii++){
            if(v[ii].x==i){
                result+=v[ii].z;
                v[ii].x=200;
                tempy=v[ii].y;
                tempx=v[ii].x;
                ii++;
                while(v[ii].x==tempx && v[ii].y==tempy){
                    v[ii].x=200;
                    ii++;
                }
                break;
            }
        }
        rearrange();
    }
    cout<<result;
} 