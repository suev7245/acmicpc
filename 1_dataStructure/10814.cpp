#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool mycompare(pair<int, string> a, pair<int, string> b){
    if(a.first<b.first)
        return true;
    else 
        return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int age;
    string name;
    vector< pair<int, string> > p;

    int N;
    cin>>N;
    while(N--){
        cin >> age >> name;
        p.push_back(make_pair(age, name));
    }
    stable_sort(p.begin(),p.end(),mycompare);

    for(vector< pair<int, string> >::iterator it=p.begin(); it<p.end(); it++)
        cout<< it->first <<" "<< it->second << "\n";
}
