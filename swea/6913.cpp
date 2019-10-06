#include <iostream>
#include <vector>
using namespace std;
void countOne(int n, int m);

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int turn, n, m;
	cin >> turn;
	for(int i=1; i<=turn; i++){
		cin >> n >> m;
		cout << "#" << i << " ";
        countOne(n,m);
	}
	
    return 0;
}

void countOne(int n, int m){
    int numOfFirst=0, cntOfSolve=0;
    int tempCntSolve, now; 
    
	for (int i = 1; i <= n; i++){
        tempCntSolve = 0;
		for (int j = 1; j <= m; j++){
            cin >> now;
            if(now) tempCntSolve++;
        }
        if (tempCntSolve > cntOfSolve){
            numOfFirst = 1; 
            cntOfSolve = tempCntSolve;
        }
        else if(tempCntSolve == cntOfSolve){
            numOfFirst++;
        }
	}
    cout << numOfFirst << " "<< cntOfSolve << endl;
}