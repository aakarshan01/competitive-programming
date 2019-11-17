#include <iostream>
#include <map>
#include <vector>
#include <stack>

using namespace std;

map <vector<int>, int> m;

int main() {
	// your code goes here
	int t,n,m,i,j;
	cin >> t;

	while(t!=0)
	{
		cin >> n >> m;
		char matrix[n][m];
		int row[n];
		int col[m];
		
		for(i=0;i<n;i++)
		{
			int temp = 0;
			for(j=0;j<m;j++)
			{
				cin >> matrix[i][j];
				if(matrix[i][j]=='*')
				{
					temp++;
				}
			}
			row[i] = temp;
		}
		for(j=0;j<m;j++)
		{
			int temp = 0;
			for(i=0;i<n;i++)
			{
				if(matrix[i][j] == '*')
				{
					temp++;
				}
			}
			col[j] = temp;
		}

		int ans = n + m - 1;
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				int temp;
				if(matrix[i][j]=='*')
				{
					temp = n + m - 1 - (row[i] + col[j]) + 1;
				}
				else
				{
					temp = n + m -1 - (row[i] + col[j]);
				}
				if(temp<ans)
				{
					ans = temp;
				}
			}
		}
		cout << ans << endl;

		t--;
	}

	return 0;
}