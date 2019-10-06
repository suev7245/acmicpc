/*경사로*/
#include <iostream>
#include <vector>
using namespace std;
int map[100][100];
int charr[100];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n,lope;
    cin>>n>>lope;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>map[i][j];
    
    int now, before, idx;
    int i, j, cnt=0;
    bool chnext=false;
    for(i=0;i<n;i++){
        idx=0;
        now=map[i][0];
        charr[idx]++;
        for(j=1;j<n;j++){
            before=now;
            now=map[i][j];
            if(chnext){
                while(before!=now && j<n){
                    now=map[i][++j];
                    charr[idx]++;
                }
                if(charr[idx]<lope) break;
                idx++; 
                charr[idx]++;
            }else if(before==now){
                charr[idx]++;
            }else if(before-now == 1){
                chnext=true;
                idx++;
                charr[idx]++;
            }else if(now-before == 1){
                if(charr[idx]<lope) break;
                idx++; 
                charr[idx]++;
            }else{
                break;
            }
        }
        if(j==n) {cnt++;cout<<i<<"\n";}
    }
    for(j=0;j<n;j++){
        idx=0;
        before= map[0][j];
        charr[idx]++;
        for(i=1;i<n;i++){
            now=map[i][j];
        }
    }
    cout<<cnt;

}