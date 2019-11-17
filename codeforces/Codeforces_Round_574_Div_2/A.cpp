#include <iostream>
#include <map>
#include <vector>
#include <set> 
#include <algorithm> 

using namespace std;

int main() {
	// your code goes here
	
	long long int n,k;
	cin >> n >> k;
	int i;
	int array[n];
	int freq[1001];
	for(i=0;i<1001;i++)
	{
		freq[i]=0;
	}
	for(i=0;i<n;i++)
	{
		cin >> array[i];
		freq[array[i]]++;
	}
	int drinks = ( n + 1 ) / 2;

	int ans = n,ctr=0,odd=0;
	for(i=1;i<=k;i++)
	{
		if(freq[i]%2==1)
		{
			odd++;
		}
	}
	ans = ans - odd / 2;
	cout << ans << endl;
	return 0;
}