#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> arr;
int result[3]; //-1 0 1
 
void paperNum(int sx, int sy, int n)
{
  bool check = false;
  int num = arr[sx][sy];
  for(int i=sx; i<sx+n && !check; i++)
    for(int j=sy; j<sy+n && !check; j++)
      if(num != arr[i][j])
        check = true;
    
  if(!check || n==1){
    if(num == -1) result[0]++;
    if(num == 0) result[1]++;
    if(num == 1) result[2]++;
  }else{
    for(int i=0; i<3; i++){
      for(int j=0; j<3; j++){
        paperNum(sx+i*n/3, sy+j*n/3, n/3);
      }
    }
  }
}

int main(void)
{
	int n;
	cin >> n;
  for(int i=0;i<n;i++){
    arr.push_back(vector<int>(n));
    for(int j=0;j<n;j++){
      cin>>arr[i][j];
    }
  }
  paperNum(0, 0, n);
  cout<<result[0]<<endl<<result[1]<<endl<<result[2]<<endl;
}
