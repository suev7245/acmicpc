#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;
int main(){
    string line;
    getline(cin, line);

    vector <string> tokens; 
    stringstream ss(line); 
      
    string intermediate; 
    while(getline(ss, intermediate, ' ')){ 
        if(intermediate.size())
            tokens.push_back(intermediate); 
    }
    cout<<tokens.size();
}
