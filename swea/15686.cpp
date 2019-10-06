/*치킨 배달 - 1:55

1. vector<int> perchicken[13]; 
array<> 대신 []로 보기 편하게!

2. dfs로 m개 조합 뽑기.
void combi(int idx, int cnt){
    if(cnt==m){
        //처리하기.
        return;
    }
    for(int i=idx; i<chinum; i++){ //selected에 선택된 애들 추가
        selected.push_back(i);
        comb(i + 1, cnt + 1);
        selected.pop_back();
    }
}
combi(0,0);

3. #include <cmath> --> abs()

4. n,m와 같은 경우 전역변수로 둘 경우 지역변수와 섞지 않도록 변수명을 확실히 하자!

5. selected와 같은 경우 컴파일 에러 발생! 예약어 사용하지 않도록 하자.

. 나는 전부 계산한 배열(전처리)을 가지고 계산했지만.
사실, 이 문제의 경우 map을 다 받을 필요 없이 그냥 house좌표 chicken좌표 가지고 있고 뽑은 chicken 조합 마다 각 house와의 차이를 계산해서 total내면 된다.

*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n,m, chinum, housenum, result;
int map[50][50]; //0-index
vector< pair<int,int> > wherechicken;
vector< pair<int,int> > wherehouse;
vector<int> perchicken[13]; // i번째 치킨집과 j번째 집과의 치킨거리.
vector<int> selected; //조합으로 뽑은 치킨집들 - 매번 combi에서 갱신됨.


int calpart(){
    //각 집의 해당 치킨집들 중에서 최소값 찾아서 mini, --> 모든 집의 mini들의 합인 total 계산
    int mini, total;
    total=0;
    for(int i=0; i<housenum; i++){
        mini = n<<2;
        for(int j=0;j<selected.size(); j++){
            mini = min(mini, perchicken[selected[j]][i]);
        }
        total += mini;
    }
    return total;
}

//m개 뽑기
void combi(int idx, int cnt){
    if(cnt==m){
        result = min(result, calpart());
        return;
    }
    for(int i=idx; i<chinum; i++){
        selected.push_back(i);
        combi(i+1, cnt+1);
        selected.pop_back();
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>map[i][j];
            if(map[i][j]==1){
                wherehouse.push_back(make_pair(i,j));
                housenum++;
            }else if(map[i][j]==2) {
                wherechicken.push_back(make_pair(i,j));
                chinum++;
            }
        }
    }

    //치킨집 하나 당 각 집과의 치킨거리를 계산한다.
    for(int i=0; i<wherechicken.size(); i++){
        for(int j=0; j<wherehouse.size(); j++){
            perchicken[i].push_back(abs(wherechicken[i].first - wherehouse[j].first) + abs(wherechicken[i].second - wherehouse[j].second));
        }
    }
    // cout<<"\n";
    // for(int i=0; i<chinum; i++){
    //     for(int j=0; j<perchicken[i].size(); j++){
    //         cout<<perchicken[i][j]<<", ";
    //     }cout<<"\n";
    // }

    //빼는 치킨집 구하기 (m개 뽑기)
    result = 1e9;
    combi(0,0);
    cout<<result;
}