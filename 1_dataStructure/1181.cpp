#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool mycompare(string a, string b){
    if(a.size()<b.size())
        return true;
    else if(a.size()>b.size())
        return false;
    else
        return a<b;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<string> v;
    int N;
    cin>>N;
    string temp;
    while(N--){
        cin >> temp;
        if(find(v.begin(),v.end(),temp) == v.end())
            v.push_back(temp);
    }
    sort(v.begin(),v.end(), mycompare);

    for(vector<string>::iterator it=v.begin(); it<v.end(); it++)
        cout<< *it <<"\n";
}
