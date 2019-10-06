#include<iostream>
#include<string>
using namespace std;


int main(int argc, char** argv)
{
	int test_case, T, idx, cnt=0;
    char var[11]; 
    int check[10]={0,};

	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin >> var;
        for(int i=0; i<10; i++){
            if(var[i]=='\0') break;
            idx = (int)(var[i] - '0');
            if(!check[idx]){
                check[idx]++;
                cnt++;
            }
        }
        cout<< "#" << test_case << " " << cnt <<endl;
        cnt=0; 
        for(int j=0; j<10; j++) check[j]=0;
	}
	return 0;
}