#include <iostream>
#include <string>
using namespace std;
int main(){
    int testcase;
    cin >> testcase;
    while(testcase--){
        int n;
        string text;
        cin >> n;
        cin >> text;

        int len = text.length();
        for(int i=0; i<len; i++)
            for(int j=0; j<n; j++)
                cout << text[i];
        cout<<endl;
    }
}