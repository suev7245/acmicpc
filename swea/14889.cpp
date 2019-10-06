/*스타트와링크*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int map[20][20];
int n;
vector<int> start;
vector<int> link;

int cal(){
    int cal_st=0; int cal_li=0;
    for(int i=0;i<start.size()-1;i++){
        for(int j=i+1;j<start.size();j++){
            cal_st += map[start[i]][start[j]] + map[start[j]][start[i]];
        }
    }
    for(int i=0;i<link.size()-1;i++){
        for(int j=i+1;j<link.size();j++){
            cal_li += map[link[i]][link[j]] + map[link[j]][link[i]];
        }
    }

    if(cal_st-cal_li>=0)
        return cal_st-cal_li;
    else 
        return cal_li-cal_st;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>map[i][j];
        
    vector<int> num;
    for(int i=0; i<n/2; i++){
		num.push_back(1);
        num.push_back(0);
	}sort(num.begin(), num.end());

    int mini=2000000000, dif;
    do{
        start.clear();
        link.clear();

		for(int i=0; i<n; i++){
            if(num[i] == 1){ 
                start.push_back(i);
			}else{ 
                link.push_back(i);
			}
		}
        dif = cal();
        mini = min(mini, dif);
	}while(next_permutation(num.begin(),num.end()));

	cout << mini;
}