#include <iostream>
#include <vector>
using namespace std;
void countOther();

int main(int argc, char** argv)
{
	int test_case, T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        cout<< "#" << test_case << " ";
        countOther();
	}
	return 0;
}

void countOther(){
    int arr[101]={0,};

    int total, done, idx;
    cin >> total >> done;

    for(int i=0; i<done; i++){
        cin >> idx;
        arr[idx]++;
    }
    for(int i=1; i<=total; i++){
        if(!arr[i])
            cout << i << " ";
    }cout << endl;
}