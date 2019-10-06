/*톱니바퀴

1. array<deque<char>, 4> deques; 자료구조의 배열 선언

2. 입력이 주어졌을 때 띄어쓰기 없는 것 유의 --> string으로 받아서 넣기
개고생: 입력편하게 받는다고 char덱 만들어놓고, 함수 내에서는 int랑 비교하고 앉음. 또 '1'대신 1이랑 비교하고 난리.
그냥 처음부터 x-48해서 int로 넣는게 나았겠다. ==>이 방식으로 고침.

3. 톱니바퀴 1-index로 주어지는데 내가 덱 배열 만들면서 0-index 썼으니 완전 유의;;
--> 하나로 아예 몰아버리는게 나을 것 같다. ==> 0-index로 바꿈.

4. 재귀 부를때 주의할 점 
- 여기서는 재귀가 완전 불린다기 보다는 그냥 재사용성 위해 쓰인것.
개고생: 함수 내에 왼쪽이랑 오른쪽 다 비교해서 함수 call 하고있었다. 근데 이 문제에서는 하나 돌리면 양쪽으로 퍼지면서 한번에 끝남. 하나 또 돌릴때마다 또 파생되는게 아님.
그래서 where변수 추가해줬다. 이건 어느쪽으로 갈건지(처음 불린거 말고 함수 call 불렸을 때 완쪽이면 왼쪽, 오른쪽이면 오른쪽으로 한쪽 방향으로만 가야하므로)

5. 조건 헷갈리지 않기.
dir은 -1과 1이었다. 근데 멋대로 0과 1로 착각해서 -dir가 아니라 (dir+1)%2 로 계산함.

*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <queue>
using namespace std;

array<deque<int>, 4> deques;

void func(int now, int dir, int where){//where:-1왼쪽탐색 1오른쪽탐색 0최초call
    if(now<0 || now>3) return;

    int left= deques[now][6];
    int right= deques[now][2];

    //얘 먼저 돌려
    if(dir==1){
        deques[now].push_front(deques[now].back());
        deques[now].pop_back();
    }else{
        deques[now].push_back(deques[now].front());
        deques[now].pop_front();
    }

    //최초call일때는 왼쪽 오른쪽 다 확인하고 보내줘야하므로 두 if문을 다 들어가줘야함. 따라서 조건을 정확한 값이 아닌 범위로 <=0와 같이 줬다.
    //아래의 now 조건은 함수 초기의 조건과 비슷해보이지만, 양 극단에 있을 때 경우를 삭제하기 위함이다. 왼쪽 검사를 할 때 이미 now가 제일 왼쪽(0)이라면 더이상 왼쪽을 검사할 수 없다.
    //왼쪽확인
    if(now>0 && where<=0){
        if(deques[now-1][2]!=left)
            func(now-1,-dir, -1);
    }
    //오른쪽확인
    if(now<3 && where>=0){
        if(right!=deques[now+1][6])
            func(now+1,-dir, 1);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string temp;
    for(int i=0;i<4;i++){
        cin>>temp;
        for(int j=0;j<8;j++){
            deques[i].push_back(temp[j]-48);
        }
    }

    int N, topni, dir;
    cin>>N;
    while(N--){
        cin>>topni>>dir;
        func(topni-1, dir, 0);//0-index로 만들기 위해
    }

    int total=0;
    if(deques[0].front()==1) total+=1;
    if(deques[1].front()==1) total+=2;
    if(deques[2].front()==1) total+=4;
    if(deques[3].front()==1) total+=8;

    cout<<total;
}