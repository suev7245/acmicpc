#include <iostream>
#include <string>
using namespace std;

int main(){
    int testcase;
    cin>>testcase;

    string text;
    char before, now;
    bool arr[26]={false,};
    int result=0;

    string::iterator it;
    while(testcase--){
        cin>>text;
        before = text.front(); 
        arr[before-97]=true;
        for(it=text.begin()+1;it<text.end();it++){
            if(*it != before){
                if(arr[*it-97]) 
                    break;
                before = *it;
                arr[*it-97]=true;
            }
        }
        if(it==text.end())
            result++;
        for(int i=0;i<26;i++)
            arr[i]=false;
        
    }
    cout<<result;
}
