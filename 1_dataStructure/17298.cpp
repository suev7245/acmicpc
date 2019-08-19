#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> v;
    int N, now;
    cin>>N;

    while (N--){
        cin>>now;
        v.push_back(now);
    }
    for(vector<int>::iterator it=v.begin(), it2=v.begin(); it<v.end()-1; it++){
        it2 = it+1;
        while(*it>=*it2 && it2<v.end()){
            it2++;
        }
        if(it2 == v.end())
            cout<<"-1"<<" ";
        else
            cout<<*it2<<" ";

    }cout<<"-1";

    return 0;
}