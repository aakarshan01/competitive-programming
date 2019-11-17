#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	// your code goes here
	
	int i,j,n,m;
	long long int ans=0;

	cin >> n;
	vector<int> array(n);
	for(i=0;i<n;i++){
		cin >> array[i];
		array[i] = abs(array[i]);
	}
	sort(array.begin(),array.end());
	for(i=0;i<n;i++){
		int temp = array[i];
		int low = lower_bound(array.begin(), array.end(), ceil(temp/2.0)) - array.begin();
		int high = upper_bound(array.begin(), array.end(), temp*2) - array.begin();
		ans = ans + high - low - 1;
		cout << "high = " << high << " low = " << low <<  " currentAns = " << ans<< endl;		
	}
	cout << ans/2 << endl;
	return 0;
}