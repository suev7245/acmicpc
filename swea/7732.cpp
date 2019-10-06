#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
void countTime();
void split(string& str, vector<int> time);

int main(int argc, char** argv)
{
	int test_case, T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        cout<< "#" << test_case << " ";
        countTime();
	}
	return 0;
}

void countTime(){
    string str;
    vector <int> time;

    cin >> str;
    split(str, time);
    
    cout << endl << time[0]+time[1]+time[2] << endl;
}

void split(string& str, vector<int> time){
    stringstream ss(str);
    string token;
    int num;
    while(getline(ss, token, ':')) {
        cout << token << '\n';
        num = stoi(token);
        time.push_back(num);
    }
}