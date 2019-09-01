/*부녀회장이 될테야*/

#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

int arr[15][15];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int T,k,n;

    for(int j=1;j<=14;j++) arr[0][j]=j;
    for(int i=1; i<=14; i++){
        arr[i][1]=1;
        for(int j=2; j<=14; j++){
            arr[i][j]=arr[i-1][j]+arr[i][j-1];
        }
    }

    cin>>T;
    while(T--){
        cin>>k>>n;
        cout<<arr[k][n]<<"\n";
    }
    return 0;
}