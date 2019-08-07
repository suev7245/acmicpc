#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
int main(){

    // Vector of string to save tokens 
    vector <string> tokens; 
    // stringstream class check1 
    stringstream ss(line); 
      
    string intermediate; 
    // Tokenizing w.r.t. space ' ' 
    while(getline(ss, intermediate, ' ')) 
    { 
        tokens.push_back(intermediate); 
    } 
      
    // Printing the token vector 
    for(int i = 0; i < tokens.size(); i++) 
        cout << tokens[i] << '\n'; 
}