#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int testcase, num;
    string op;
    deque<int> dq;

    cin>>testcase;
    while(testcase--){
        cin>> op;
        if(op =="push_back"){
          cin>>num;
          dq.push_back(num);
        }if(op =="push_front"){
          cin>>num;
          dq.push_front(num);
        }if(op =="pop_front"){
          if(!dq.empty()){
            cout<<dq.front()<<"\n"; 
            dq.pop_front();
          }else{
            cout<<"-1"<<"\n";
          }
        }if(op =="pop_back"){
          if(!dq.empty()){
            cout<<dq.back()<<"\n"; 
            dq.pop_back();
          }else{
            cout<<"-1"<<"\n";
          }
        }if(op =="size"){
          cout<<dq.size()<<"\n";
        }if(op =="empty"){
          cout<<dq.empty()<<"\n";
        }if(op =="front"){
          if(!dq.empty()){
            cout<<dq.front()<<"\n";
          }else{
            cout<<"-1"<<"\n";
          }
        }if(op =="back"){
          if(!dq.empty()){
            cout<<dq.back()<<"\n";
          }else{
            cout<<"-1"<<"\n";
          }
        }
    }
    return 0;
}