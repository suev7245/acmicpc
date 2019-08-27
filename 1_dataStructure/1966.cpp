/* 
현재 Queue의 가장 앞에 있는 문서의 ‘중요도’를 확인한다.
나머지 문서들 중 현재 문서보다 중요도가 높은 문서가 하나라도 있다면, 이 문서를 인쇄하지 않고 Queue의 가장 뒤에 재배치 한다. 그렇지 않다면 바로 인쇄를 한다.
예를 들어 Queue에 4개의 문서(A B C D)가 있고, 중요도가 2 1 4 3 라면 C를 인쇄하고, 다음으로 D를 인쇄하고 A, B를 인쇄하게 된다.

여러분이 할 일은, 현재 Queue에 있는 문서의 수와 중요도가 주어졌을 때, 어떤 한 문서가 몇 번째로 인쇄되는지 알아내는 것이다. 예를 들어 위의 예에서 C문서는 1번째로, A문서는 3번째로 인쇄되게 된다.
*/
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(queue<pair<int, int> > qu){
    int now = qu.front().first; 
    qu.pop();
    while(qu.front().first<=now && !qu.empty()){
        qu.pop();
    }

    if(qu.empty()) 
        return false;
    else 
        return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int testcase, n,m;
    int temp, now, cnt;

    cin>>testcase;
    while(testcase--){
        cin>> n >> m;
        queue<pair<int,int> > qu;
        for(int i=0; i<n; i++){
            cin>>temp;
            qu.push(make_pair(temp, i));
        }
        cnt=0;
        while(!qu.empty()){
            if(cmp(qu)){ 
                qu.push(qu.front()); 
                qu.pop();
            }else{
                cnt++;
                if(qu.front().second==m)
                    break;
                qu.pop();
            }
        }
        cout<<cnt<<'\n';

    }
    return 0;
}
