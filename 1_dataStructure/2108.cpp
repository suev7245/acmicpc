#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
using namespace std;
/* 1.평균 2.중앙값 4.범위를 쉽게 구하기 위해 받은 수들을 vector에 넣고 정렬(sort함수 이용)하였다. 
    
    1. 평균은 vector이터레이터로 돌려 합을 구한 후 size로 나누었다.
    2. 중앙값은 size/2를 하여 해당 인덱스의 수를 구했다. - 홀수라 했으므로
    3. 최빈값은 값들이 정렬되어있음을 이용해 숫자가 바뀔때마다 Map<수,cnt>으로 넣어주었다.(수가 같을떄 cnt++) 
        그리고 map.size()가 1보다 크면 두번째수, 아니면 첫번째 수를 출력하도록 하였다.
    4. 범위는 맨앞의 수 front와 맨 뒤의 수 back의 차를 구했다.
*/

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, temp, sum=0;
    cin>>N;
    map<int, int> m;
    while(N--){
        cin >> temp;
        m.insert(make_pair(temp, 1));
        sum += temp; 
    }

    cout<<sum/m.size;
}

int arrw(){
    int testcase;
    cin>>testcase;
    vector<int> arr;
    int temp;
    for(int i=0; i<testcase; i++){
        cin >> temp;
        arr.push_back(temp);
    }
    sort(arr.begin(), arr.end());
  
    //Q1-산술평가 첫쨰자리에서 반올림-------------------------------------------------    
    int sum=0;
    vector<int>::iterator it;
    for (it=arr.begin(); it<arr.end(); it++) 
        sum += *it;
    cout<<round(sum/(float)arr.size())<<'\n'; 
    
    //Q2-중앙값-------------------------------------------------  
    cout<<arr.at(arr.size()/2)<<'\n';
    
    //Q3-최빈값. 여러개면 두번쨰로 작은 값-------------------------------------------------    
    int now=arr.front(), cnt=1;
    map<int, int> freq;
    for (it=arr.begin()+1; it<arr.end(); it++){
        if(now == *it){
            cnt++;
        }else{
            if(freq.empty()){
                freq.insert(make_pair(now,cnt));
            }else{
                if(cnt > freq.begin()->second){
                    freq.clear();
                    freq.insert(make_pair(now,cnt));
                }else if(cnt == freq.begin()->second)
                    freq.insert(make_pair(now,cnt));    
            }
            cnt=1;
            now = *it;
        }
    } 
    freq.insert(make_pair(now,cnt));

    map<int, int>::iterator it2=freq.begin();
    if(freq.size()==1)
        cout<<it2->first<<"\n";
    else
        cout<<(++it2)->first<<"\n";



    //Q4-범위------------------------------------------------    
    cout<<arr.back()-arr.front();
}
//100,000,000 == 1초