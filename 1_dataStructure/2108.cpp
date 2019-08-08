#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
/* 1.평균 2.중앙값 4.범위를 쉽게 구하기 위해 받은 수들을 vector에 넣고 정렬(sort함수 이용)하였다. 
    
    1. 평균은 vector이터레이터로 돌려 합을 구한 후 size로 나누었다.
    2. 중앙값은 size/2를 하여 해당 인덱스의 수를 구했다. - 홀수라 했으므로
    3. 최빈값은 값들이 정렬되어있음을 이용해 숫자가 바뀔때마다 vector pair<수,cnt>으로 넣어주었다.
        그리고 이를 mycompare 함수를 정의하여 sort.(cnt 큰 순, cnt같으면 숫자 작은 순 )
    4. 범위는 맨앞의 수 front와 맨 뒤의 수 back의 차를 구했다.
*/
bool mycompare(pair<int, int> a, pair<int, int> b){
    if(a.second > b.second)
        return true;
    else if(a.second == b.second){
        if(a.first<b.first)
            return true;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

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
    int before=arr.front(), cnt=1;
    vector< pair<int, int> > freq;
    for (it=arr.begin()+1; it<arr.end(); it++){
        if(before == *it){
            cnt++;
        }else{
            freq.push_back(make_pair(before, cnt));
            before = *it;
            cnt=1;
        }
    }freq.push_back(make_pair(before, cnt));
    
    sort(freq.begin(),freq.end(),mycompare);

    vector< pair<int, int> >::iterator freqit=freq.begin(); freqit++;
    if(freq.front().second == freqit->second)
        cout<<freqit->first<<'\n';
    else
        cout<<freq.front().first<<'\n';

    //Q4-범위------------------------------------------------    
    cout<<arr.back()-arr.front();
}
//100,000,000 == 1초