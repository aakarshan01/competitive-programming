#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

map <vector<int>, int> m;

int main() {
	// your code goes here
	cout <<"val = " <<  YO << endl;
	long long int i,n,x,k,t;
	cin >> t;
	long long int steps = 0;
	while(t!=0){
		cin >> n;
		vector<int> array(n);
		for(i=0;i<n;i++)
		{
			cin >> array[i];
		}
		sort(array.begin(), array.end());
		int ans = n-2, found = 0;

		for(i=n-1;i>=0;i--)
		{
			if(i >= 1 && array[i]>ans && array[i-1] > ans)
			{
				found = 1;
				break;
			}
			else
			{
				ans--;
			}
		}
		cout << ans << endl;
		t--;
	}

	return 0;
}