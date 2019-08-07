#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
    string text;
    cin >> text;

    int arr[26]={0,};

    int len = text.size();
    for(int i=0; i<len; i++){
        if(text[i]>96)
            arr[text[i]-97]++;
        else
            arr[text[i]-65]++;
    }
    int max=0;
    bool check = false;
    for(int i=1; i<26; i++){
        if(arr[max]==arr[i])
            check = true;
        else if(arr[max]<arr[i]){
            max = i;
            check = false;
        }
    }
    
    if(check)
        cout<< "?";
    else
        cout<< (char)(max+65);
}