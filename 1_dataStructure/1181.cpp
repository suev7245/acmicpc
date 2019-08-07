#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, x, y;
    cin>>N;

    vector< pair<int, int> > dot;
    while(N--){
        cin>> x>>y;
        dot.push_back(make_pair(y,x));
    }
    sort(dot.begin(), dot.end());

    for(vector< pair<int, int> >::iterator it=dot.begin(); it<dot.end(); it++){
        cout<< it->second <<" "<< it->first<<"\n";
    }
}
