#include <iostream>
#include <string>
using namespace std;

int main(){
    string a;
    int sum = 0;
    cin >> a;

    string::iterator it;
    for(it=a.begin(); it<a.end() ;it++){
        if(*it == 'c'){
            if(*(it+1)== '=' || *(it+1)== '-')
                it++;
        }else if(*it == 'd'){
            if(*(it+1)== '-')
                it++;
            else if(*(it+1)== 'z' && *(it+2)== '=')
                it+=2;
        }else if(*it == 's' || *it == 'z'){
            if(*(it+1)== '=')
                it++;
        }else if(*it == 'l' || *it == 'n'){
            if(*(it+1)== 'j')
                it++;
        }
        sum++;
    }
    cout<<sum;
}
