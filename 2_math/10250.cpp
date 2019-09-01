/*acm호텔*/

#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int T,h,w,n;
    cin>>T;

    while(T--){
        cin>>h>>w>>n;

        if(n%h==0){
            cout<<h;
            if(n/h<10)cout<<0;
            cout<<n/h;
        }else{
            cout<<n%h;
            if(n/h<9)cout<<0;
            cout<<n/h+1;
        }
        cout<<"\n";
    }

    return 0;
}