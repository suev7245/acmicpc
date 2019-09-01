/*달팽이*/

#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int a,b,v;
    cin>>a>>b>>v;

    int dif =a-b;
    int result = (v-a)/dif +1;
    if((v-a)%dif) result++;

    cout<<result;

    return 0;
}