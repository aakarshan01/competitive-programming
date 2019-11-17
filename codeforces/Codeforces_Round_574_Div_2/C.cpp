#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
map <int,int>m;

int main() {
	// your code goes here
	
	register int i,j;
	long long int n,m,k;
	cin >> n;
	long long int arrayA[n];
	long long int arrayB[n];

	for(i=0;i<n;i++)
	{
		cin >> arrayA[i];
	}
	for(i=0;i<n;i++)
	{
		cin >> arrayB[i];
	}

	long long int ans[n][2];
	ans[0][0] = arrayA[0];
	ans[0][1] = arrayB[0];
	for(i=1;i<n;i++)
	{
		if(i==1)
		{
			ans[i][0] = ans[i-1][1] + arrayA[i];
			ans[i][1] = ans[i-1][0] + arrayB[i];
		}
		else
		{
			ans[i][0] = max(ans[i-1][1] + arrayA[i], max(ans[i-2][1] + arrayA[i], ans[i-2][0] + arrayA[i]));
			ans[i][1] = max(ans[i-1][0] + arrayB[i], max(ans[i-2][0] + arrayB[i], ans[i-2][1] + arrayB[i]));
		}
		//cout << "i = " << i << " " << ans[i][0] << " " << ans[i][1] << endl;
	}
	long long int answer = max(ans[n-1][0], ans[n-1][1]);

	cout << answer << endl;
	return 0;
}