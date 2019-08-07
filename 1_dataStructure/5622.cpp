#include <iostream>
#include <string>
using namespace std;

int main(){
    string a;
    int sum = 0;
    cin >> a;
    for(int i=0; i<a.size() ;i++){
        if(a[i]=='S' || a[i]=='V' || a[i]=='Y' || a[i]=='Z')
            sum--;
        sum+=(a[i]-65)/3 + 3;
    }
    cout<<sum;
}
