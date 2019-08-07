#include <iostream>
#include <string>
using namespace std;
int main(){
    int n, sum=0;
    string line; 
    cin >> n >> line;

    for(int i=0; i<n; i++){
        sum += line[i] - '0';
    }
    cout<<sum;
}