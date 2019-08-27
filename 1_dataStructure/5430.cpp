/*
선영이는 주말에 할 일이 없어서 새로운 언어 AC를 만들었다. AC는 정수 배열에 연산을 하기 위해 만든 언어이다. 이 언어에는 두 가지 함수 R(뒤집기)과 D(버리기)가 있다.

함수 R은 배열에 있는 숫자의 순서를 뒤집는 함수이고, D는 첫 번째 숫자를 버리는 함수이다. 배열이 비어있는데 D를 사용한 경우에는 에러가 발생한다.

함수는 조합해서 한 번에 사용할 수 있다. 예를 들어, "AB"는 A를 수행한 다음에 바로 이어서 B를 수행하는 함수이다. 예를 들어, "RDD"는 배열을 뒤집은 다음 처음 두 숫자를 버리는 함수이다.

배열의 초기값과 수행할 함수가 주어졌을 때, 최종 결과를 구하는 프로그램을 작성하시오.
*/
#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int testcase; cin>>testcase;

    string op, arrstring; op.reserve(100000);
    int arrn, ch;
    deque<int> dq;

    while(testcase--){
      dq.clear(); ch=1;
      cin>>op>>arrn>>arrstring;

      stringstream ss(arrstring);
      ss.ignore();
      for(int i; ss>>i;){
        dq.push_back(i);    
        if (ss.peek() == ',' || ss.peek() == ']')
            ss.ignore();
      }
      
      // string num = ""; 
      // for (int i = 1; i < arrstring.size(); i++) { // deque로 만들기 
      //   if (arrstring[i] == ',' || arrstring[i] == ']'){ 
      //     if(arrstring[i-1]=='[') break;
      //     dq.push_back(stoi(num)); 
      //     num = ""; 
      //   }
      //   else
      //     num += arrstring[i];
      // } 

      int i, size=op.size();
      for(i=0; i<size; i++){
        if(op[i]=='R')
          ch*=-1;
        else{
          if(dq.empty()){ cout<<"error"<<'\n'; break; }

          if(ch==1) dq.pop_front();
          else dq.pop_back();
        }
      }

      //에러 아닐때 출력
      if(i==size){
        int deqsize = dq.size();
        cout<<"[";
        for(int j=0; j<deqsize; j++){
          if(ch==1){
            cout<<dq.front();
            dq.pop_front();
          }else{
            cout<<dq.back();
            dq.pop_back();
          }
          if(j<deqsize-1) cout<<",";
        }
        cout<<"]\n";
      }
    }

    return 0;
}