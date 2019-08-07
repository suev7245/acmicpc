#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;
void diff(int ai, int bi);
void printreverse(string text);

string a,b;

int main(){
    cin >> a >> b;
    diff(2,2);
}

void diff(int ai, int bi){
    if(a[ai]>b[bi])
        printreverse(a);
    else if(a[ai]<b[bi])
        printreverse(b);
    else
        diff(--ai, --bi);
}

void printreverse(string text){
    cout<<text[2]<<text[1]<<text[0];
}
