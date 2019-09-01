/*설탕 배달 */

#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin>>n;

    int three = n/3;
    int i,num=0;
    for(i=0;i<=three;i++){
        if((n-num)%5==0) break;
        num+=3;
    }
    if(i>three) cout<<"-1";
    else cout<<(n-num)/5+i;

    return 0;
}