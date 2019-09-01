/*부녀회장이 될테야*/

#include <iostream>
#include <algorithm>
using namespace std;

int arr[15][15];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int x,y,w,h;
    cin>>x>>y>>w>>h;
    int result = min(min(x,w-x), min(y,h-y));
    cout<<result;
    return 0;
}