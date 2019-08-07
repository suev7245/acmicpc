#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int testcase;
    cin>>testcase;
    vector<int> arr;
    int temp;

    for(int i=0; i<testcase; i++){
        cin >> temp;
        arr.push_back(temp);
    }
    sort(arr.begin(), arr.end());
    for(int i=0; i<testcase; i++){
        cout << arr[i]<<'\n';
    }
}