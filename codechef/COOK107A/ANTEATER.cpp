#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;
int mod = 1000000007;

bool comparator(const pair<int, int> &a, const pair<int, int> &b){
	return a.second<b.second;
}

int main() {
	// your code goes here
	int t, m, k,q, i = 0, u,j, v, ctr;
	cin >> t;
	while(t!=0)
	{
		int r,c;
		cin >> r >> c;
		char grid[r][c];
		int ans[r][c][50];
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				cin >> grid[i][j];
				for(k=0;k<50;k++)
					ans[i][j][k] = 0;
			}
		}

		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				if(grid[i][j]=='R')
				{
					int temp = j, timer = 0;
					while(temp < c)
					{
						if(grid[i][temp]=='#')
							break;
						ans[i][temp][timer]++;
						temp++;
						timer++;
					}
				}
				else if(grid[i][j]=='L')
				{
					int temp = j, timer = 0;
					while(temp>=0)
					{
						if(grid[i][temp]=='#')
							break;
						ans[i][temp][timer]++;
						temp--;
						timer++;
					}
				}
				else if(grid[i][j]=='D')
				{
					int temp = i, timer = 0;
					while(temp<r)
					{
						if(grid[temp][j]=='#')
							break;
						ans[temp][j][timer]++;
						temp++;
						timer++;
					}
				}
				else if(grid[i][j]=='U')
				{
					int temp = i, timer = 0;
					while(temp>=0)
					{
						if(grid[temp][j]=='#')
							break;
						ans[temp][j][timer]++;
						temp--;
						timer++;
					}
				}
			}
		}
		long long int answer = 0;
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				for(k=0;k<50;k++)
				{
					if(ans[i][j][k]>1)
					{
						long long int temp = ((ans[i][j][k])*(ans[i][j][k]-1))/2;
						answer = answer + temp;
					}
				}
			}
		}
		cout << answer << endl;
		t--;
	}


	return 0;
}
	