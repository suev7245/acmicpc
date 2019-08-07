#include <iostream>
#include <string>
using namespace std;
int main(){
    string al;
    int arr[26];
    cin >> al;
    for(int i=0; i<26; i++)
        arr[i]=-1;

    int len = al.length();
    int x;
    for(int i=0; i<len; i++){
        x = al[i]-97;
        if(arr[x] == -1)
            arr[x] = i;
    }
    for(int i=0; i<26; i++)
        cout<<arr[i]<<" ";
}