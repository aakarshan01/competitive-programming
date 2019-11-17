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
	cin >> n >> m >> k;
	long long int specialItems[m+1];
	for(i = 1;i<m+1;i++)
		cin >> specialItems[i];

	long long int start = 1;
	long long int end = k;
	long long int ans = 0;
	int currentPos = 1;
	long long int prev = 1;

	while(1>0)
	{
		if(currentPos == m+1)
			break;

		long long int diff = specialItems[currentPos] - start;
		long long int groupNo = diff / k;
		start = start + k * groupNo;
		end = end + k * groupNo;
		//cout << " start = " << start << " end = " << end << endl;
		int temp = 0;
		
		while (currentPos <= end && specialItems[currentPos]<=end && specialItems[currentPos]>=start)
		{
			temp++;
			currentPos++;
		}

		if(temp>0)
		{
			ans++;
			start = start + temp;
			end = end + temp;
			if(start > n)
				break;
			if(end > n)
				end = n;
			continue;
		}
		else
		{

			start = start + k;
			end = end + k;
		}
	}

	/*
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			cout << matrix[i][j].first << "" ;
		}
		cout << endl;
	}*/
	cout << ans << endl;
	return 0;
}