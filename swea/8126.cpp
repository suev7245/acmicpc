#include <iostream>
#include <vector>
using namespace std;
void count();

int main(int argc, char** argv)
{
	int test_case, T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int temp, number;
        cout<< "#" << test_case << " ";
        cin>>n;
        for(int i=0; i<n; i++){
            cin >> temp;
            number += temp;
            count(n, number);
        }
	}
	return 0;
}

void count(int n, int number){
    for(int i=10; i<done; i++){
        cin >> idx;
        arr[idx]++;
    }
    for(int i=1; i<=total; i++){
        if(!arr[i])
            cout << i << " ";
    }cout << endl;
}