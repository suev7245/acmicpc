/*손익분기점*/

#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int a,b,c;
    cin>>a>>b>>c;
    if(b<c){
        cout<<a/(c-b)+1;
    }else{
        cout<<"-1";
    }
    

    return 0;
}