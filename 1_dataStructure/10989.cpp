#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int testcase;
    cin>>testcase;

    int temp;
    int arr[10001]={0,};
    for(int i=0; i<testcase; i++){
        cin >> temp;
        arr[temp]++;
    }
    for(int i=0; i<10001; i++){
        while(arr[i]--)
            cout<<i<<'\n';
    }
}