/*벌집*/

#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin>>n;

    int i, num=1;
    for(i=1;;i++){
        if(n<=num) break;
        num += i*6;
    }
    cout<<i;

    return 0;
}