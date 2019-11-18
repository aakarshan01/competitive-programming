#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string.h>
using namespace std;

int mod = 1000000007;
int array[100005];
int arraySize = 0;

int main() {
	// your code goes here
	int t, n, k, i, z,index = 0, j, size, x, xIndex, repeat,l ,r, f, cf, ans = 0;
	cin >> t;
	while(t!=0)
	{
		cin >> n >> z;
		vector<int> coc(n);
		for(i=0;i<n;i++)
			cin >> coc[i];
		sort(coc.begin(), coc.end());

		int start = 0, end = n - 1;
		long long int ans = 0,ctr=0,temp = 0;
		while(1>0)
		{
			if(ctr==z)
			{
				break;
			}
			//cout << "(coc[start]-temp) =  " << (coc[start]-temp) << " (end-start+1) = " << (end-start+1) << " (coc[end]-temp) = " << (coc[end]-temp) << endl;
			if((coc[start]-temp) * (end-start+1) <= (coc[end]-temp))
			{
				ctr++;
				ans+=(coc[start]-temp)*(end-start+1);
				temp=coc[start];
				start++;
			}
			else
			{
				ans+=(coc[end]-temp);
				end--;
				ctr++;
			}
			//cout << " ans = " << ans << endl;
		}
		cout << ans << endl;
		t--;
	}
}
	