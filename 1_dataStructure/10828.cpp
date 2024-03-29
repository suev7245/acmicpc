//std::stack에서 pop은 리턴을 안함.
//top도 empty 체크를 안함 (empty일때 -1리턴같은거 없음 - 바로 오류남

#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, num;
    string op;
    stack<int> st;

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
            if(st.empty())
                cout<<"-1"<<"\n";
            else
                cout<<st.top()<<'\n';
        }
    }
    return 0;
}
