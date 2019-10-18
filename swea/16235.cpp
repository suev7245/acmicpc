//나무 재테크
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N,M,K,dab;
int A[10][10];
int ground[10][10];
vector<int> trees[10][10];

int dy[]={-1,-1,-1,0,1,1,1,0};
int dx[]={-1,0,1,1,1,0,-1,-1};

void solve(){
    while(K--){
        int age;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(trees[i][j].size()==0)continue;
                sort(trees[i][j].begin(),trees[i][j].end());
                // for(int k=0;k<trees[i][j].size();k++){
                //     cout<<trees[i][j][k]<<" ";
                // }cout<<"\n";
            
                //어린나무부터 양분 먹이기
                int k, addtree=0;
                for(k=0;k<trees[i][j].size();k++){
                    age = trees[i][j][k];
                    if(ground[i][j]>=age){
                        ground[i][j]-=age;
                        trees[i][j][k]++;//age++;
                    }else{//k부터 양분 못 먹어서 죽어야 하는 나무 index- 여름 바로 처리
                        break;
                    }
                }
                if(k!=trees[i][j].size()){//여름처리
                    for(int t=trees[i][j].size()-1;t>=k;t--){
                        ground[i][j]+=trees[i][j][t]/2;
                        trees[i][j].pop_back();
                    }
                }
            }
        }
        
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(trees[i][j].size()==0)continue;
                int addtree=0;
                for(int k=0;k<trees[i][j].size();k++){
                    if(trees[i][j][k]%5==0){//가을
                        addtree++;
                    }
                }
                int ny, nx;
                for(int dir=0;dir<8 && addtree;dir++){//가을처리
                    ny= i+dy[dir];
                    nx= j+dx[dir];
                    if(ny<0||ny>=N||nx<0||nx>=N) continue;
                    for(int ii=0;ii<addtree;ii++)
                        trees[ny][nx].push_back(1);
                }
                ground[i][j]+=A[i][j];
            }
        }

        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cout<<trees[i][j].size()<<" ";
            }cout<<"\n";
        }
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                for(int k=0;k<trees[i][j].size();k++){
                    cout<<trees[i][j][k]<<",";
                }
            }
        }cout<<"\n";
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            dab+=trees[i][j].size();
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>N>>M>>K;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>A[i][j];
            ground[i][j]=5;
        }
    }

    int a,b,c;
    for(int i=0;i<M;i++){
        cin>>a>>b>>c;
        trees[a-1][b-1].push_back(c);
    }

    solve();

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<trees[i][j].size()<<" ";
        }cout<<"\n";
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            for(int k=0;k<trees[i][j].size();k++){
                cout<<trees[i][j][k]<<" ";
            }cout<<"\n";
        }cout<<"\n";
    }

    cout<<dab;
} 