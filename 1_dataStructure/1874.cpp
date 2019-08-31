#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(){
    stack<int> st;
    vector<char> v;
    int N;
    cin>>N;

    bool check=false;
    int max=0, now;

    cin>>now;
    for(int i=1; i<=now; i++) {st.push(i); v.push_back('+');}
    st.pop(); v.push_back('-'); 
    max=now;

    while (N--){
        cin>>now;

        // if(st.top()<now){
        //     for(int i=max+1; i<=now; i++){
        //         st.push(i); 
        //         v.push_back('+');
        //     }
        //     st.pop();
        //     v.push_back('-'); 
        // }else if(st.top()==now){
        //     st.pop();
        //     v.push_back('-'); 
        // }else{
        //     check=true;
        //     break;
        // }

        if(max<now){
            for(int i=max+1; i<=now; i++){
                v.push_back('+');
                st.push(i);
            }
            v.push_back('-');
            st.pop();
            
            max = now;
        }else{
            if(now != st.top()){
                check = true;
                break;
            }
            else{
                v.push_back('-');
                st.pop();
            }
        }
    }
    if(check)
        cout<<"NO";
    else
        for(vector<char>::iterator it=v.begin(); it<v.end(); it++)
            cout<<*it<<"\n";
    return 0;
}