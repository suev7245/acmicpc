#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    stack<char> st;
    bool check=false;
    string line;
    while (getline(cin, line)){
        if(line==".")
            break;
        for(int i=0; i<line.size(); i++){
            if (line[i]=='(' || line[i]=='[')
                st.push(line[i]);
            else if(line[i]==')'){
                if(st.empty() || st.top()!='('){
                    check = true;
                    break;
                }
                st.pop();
            }  
            else if(line[i]==']'){
                if(st.empty() || st.top()!='['){
                    check = true;
                    break;
                }
                st.pop();
            }  
        }
        if(st.empty() && !check)
            cout<<"yes"<<"\n";
        else
            cout<<"no"<<"\n";
        check = false;
        st=stack<char>();
    }
    return 0;
}