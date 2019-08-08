#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    stack<char> st;

    int N;
    cin>>N;

    bool check=false;
    string line;
    while (N--){
        cin>>line;
        for(int i=0; i<line.size(); i++){
            if (line[i]=='(')
                st.push(line[i]);
            else{
                if(st.empty()){
                    check = true;
                    break;
                }
                st.pop();
            }  
        }
        if(st.empty() && !check)
            cout<<"YES"<<"\n";
        else
            cout<<"NO"<<"\n";
        check = false;
        st=stack<char>();
    }
    return 0;
}