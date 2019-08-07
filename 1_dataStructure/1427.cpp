#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool revcompare(int i, int j){ return i>j; }

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    vector<int> v;
    cin>>str; 
    for(int i=0; i<str.size(); i++){
        v.push_back(str[i]-'0');
    }
    sort(v.begin(),v.end(), revcompare);
    for(vector<int>::iterator it=v.begin(); it<v.end(); it++)
        cout<<*it;
}
