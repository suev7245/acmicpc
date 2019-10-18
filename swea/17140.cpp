//이차원 배열과 연산
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int ny=3,nx=3, r,c,k;
int arr[100][100];

bool comp(const pair<int, int> &a, const pair<int, int> &b){
    if(a.second<b.second) return true;
    if(a.second==b.second) return a.first<b.first;
    return false;
    
}

void funcR(){
    map<int, int> m;
    vector<pair<int, int> > temp;
    map<int, int>::iterator it;

    for(int i=0;i<100;i++){
        m.clear();
        temp.clear();
        for(int j=0;j<100;j++){
            if(arr[i][j])
                m[arr[i][j]]++;
        }
        for(it=m.begin();it!=m.end();it++){
            temp.push_back(make_pair(it->first,it->second));
        }
        sort(temp.begin(),temp.end(),comp);
        if(nx!=100 && nx<temp.size()*2) {
            nx=temp.size()*2;
            if(nx>100) nx=100;
        }

        int s;
        for(s=0;s<temp.size() && s<50;s++){
            arr[i][2*s]=temp[s].first;
            arr[i][2*s+1]=temp[s].second;
        }
        for(s*=2;s<100;s++){
            arr[i][s]=0;
        }
    }
}
void funcC(){
    map<int, int> m;
    vector<pair<int, int> > temp;
    map<int, int>::iterator it;

    for(int i=0;i<100;i++){
        m.clear();
        temp.clear();
        for(int j=0;j<100;j++){
            if(arr[j][i])
                m[arr[j][i]]++;
        }
        for(it=m.begin();it!=m.end();it++){
            temp.push_back(make_pair(it->first,it->second));
        }
        sort(temp.begin(),temp.end(),comp);
        if(ny!=100 && ny<temp.size()*2) {
            ny=temp.size()*2;
            if(ny>100) ny=100;
        }

        int s;
        for(s=0;s<temp.size() && s<50;s++){
            arr[2*s][i]=temp[s].first;
            arr[2*s+1][i]=temp[s].second;
        }
        for(s*=2;s<100;s++){
            arr[s][i]=0;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>r>>c>>k;
    r--;c--;
    for(int i=0;i<3;i++){
        cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
    }

    int s;
    for(s=0;s<=100;s++){
        if(arr[r][c]==k) break;

        if(ny>=nx) funcR();
        else funcC();

        // for(int i=0;i<ny;i++){
        //     for(int j=0;j<nx;j++){
        //         cout<<arr[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
        // cout<<"\n";
    }
    if(s>100) cout<<-1;
    else cout<<s;
} 