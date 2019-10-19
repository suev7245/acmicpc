//나무 재테크
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;
struct Tree{
    int y, x, z;
    Tree(){}
    Tree(int ty, int tx, int tz){
        y=ty, x=tx, z=tz;
    }
};

int N,M,K, dab;
int A[10][10];
int ground[10][10];

int dy[]={-1,-1,-1,0,1,1,1,0};
int dx[]={-1,0,1,1,1,0,-1,-1};

queue<Tree> trees[2];
queue<Tree> addtrees;
queue<Tree> dead;
int cur=0, nex=1;

bool comp(const Tree &a, const Tree &b){
    return a.z<b.z;
}

void solve(){
    //봄 - 번식한 애들은 나이 1이니까 얘네 먼저 처리 후, 있던 애들 처리.
    Tree now;
    while(!addtrees.empty()){
        now = addtrees.front(); 
        addtrees.pop();
        // cout<<ground[now.y][now.x]<<","<<now.z<<" ";
        if(ground[now.y][now.x]<now.z){
            dead.push(now);//죽어
        }else{
            ground[now.y][now.x] -= now.z;//양분 먹고
            now.z++;//나이 +1
            trees[nex].push(now);
        }
    }
    while(!trees[cur].empty()){
        now= trees[cur].front();
        trees[cur].pop();
        // cout<<ground[now.y][now.x]<<","<<now.z<<" ";
        if(ground[now.y][now.x]<now.z){
            dead.push(now);//죽어
        }else{
            ground[now.y][now.x] -= now.z;//양분 먹고
            now.z++;//나이 +1
            trees[nex].push(now);
        }
    }

    //여름
    while(!dead.empty()){
        ground[dead.front().y][dead.front().x]+=dead.front().z/2;
        dead.pop();
    }

    //가을
    int ny, nx;
    while(!trees[nex].empty()){
        now= trees[nex].front(); trees[nex].pop();
        trees[cur].push(now);
        if(now.z % 5 != 0) continue;

        for(int dir=0;dir<8;dir++){
            ny= now.y + dy[dir];
            nx= now.x + dx[dir];

            if(ny<0||ny>=N||nx<0||nx>=N) continue;
            addtrees.push(Tree(ny,nx,1));
        }
    }

    //겨울
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            ground[i][j]+=A[i][j];
        }
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>N>>M>>K;
    //A배열 받기
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>A[i][j];
        }
    }
    //나무 받기 - 처음 정렬한 후에는 무조건 +1과 최소 나이인 1 나무만 추가 되므로 순서가 망가지지 않음. 따라서 정렬은 한번만 해도 됨.
    int x,y,z;
    vector<Tree> temp;
    for(int i=0;i<M;i++){
        cin>>x>>y>>z;
        temp.push_back(Tree(x-1,y-1,z));
    }
    sort(temp.begin(),temp.end(),comp);
    for(int i=0;i<M;i++){
        trees[0].push(temp[i]);
    }

    //ground 배열 5로 초기화
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            ground[i][j]=5;

    while(K--){
        solve();
        // cout<<"cur:"<<trees[cur].size()<<" ";
        // cout<<"nex:"<<trees[nex].size()<<" ";
    }
    cout<<trees[cur].size()+addtrees.size();
} 