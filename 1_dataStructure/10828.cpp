//std::stack에서 pop은 리턴을 안함.

#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

class stack{
private:
    
public:
    stack(){}
    void push(int x){}
    void pop(){}
    void size(){}
    void empty(){}
    void top(){}
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, num;
    string op;

    cin>> N;
    while(N--){
        cin>> op;
        if(op == "push"){
            cin>>num;
            st.push(num);
        }else if(op == "pop"){
            if(st.empty()){
                cout<<"-1"<<'\n';
            }else{
                cout<<st.top()<<'\n';
                st.pop();
            }
        }else if(op == "size"){
            cout<<st.size()<<'\n';
        }else if(op == "empty"){
            cout<<st.empty()<<'\n';
        }else if(op == "top"){
            cout<<st.top()<<'\n';
        }
    }
}
