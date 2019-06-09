#include <iostream>
#include <math.h>
using namespace std;

int result;
void calz(int sx, int sy, int x, int y, int n)
{
  if(n==1){
    if(sx==x && sy==y){
      cout<<result; 
      return;
    }else{
      result++; return;
    }
  }
    
  if(sx<=x && x<sx+n && sy<=y && y<sy+n){
    calz(sx,sy,x,y,n/2);
    calz(sx,sy+n/2,x,y,n/2);
    calz(sx+n/2,sy,x,y,n/2);
    calz(sx+n/2,sy+n/2,x,y,n/2);
  }else{
    result += n*n;
    return;
  }
}


int main(void)
{
	int n, x, y;
	cin >> n;
    cin >> x;
    cin >> y;
	calz(0, 0, x, y, pow(2,n));
}#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<vector<int>> tree;

void quadtree(int row, int col, int n)
{
	if (n == 1)	{
		cout << tree[row][col];
		return;
	}

	int color = tree[row][col];
	bool check = false;
	for (int i = 0; i < n && !check; i++)
		for (int j = 0; j < n && !check; j++)
			if (color != tree[row + i][col + j])
				check = true;

	if (!check)
		cout << color;
	else
	{
		cout << "(";
		quadtree(row, col, n / 2);
		quadtree(row, col + n / 2, n / 2);
		quadtree(row + n / 2, col, n / 2);
		quadtree(row + n / 2, col + n / 2, n / 2);
		cout << ")";
	}
}

int main(void)
{
	int n;
	cin >> n;
	vector<string> input(n);
	for (int i = 0; i < n; i++)
		cin >> input[i];

	for (int i = 0; i < n; i++){
		tree.push_back(vector<int>(n));
		for (int j = 0; j < n; j++)
			tree[i][j] = (int)(input[i][j] - '0');
	}
	quadtree(0, 0, n);
}
