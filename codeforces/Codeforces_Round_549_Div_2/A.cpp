#include <iostream>
#include <map>
#include <vector>

using namespace std;

map <vector<int>, int> m;

int main() {
	// your code goes here
	int i,n,k;
	cin >> n;
	int array[n];

	int last1=0, last0 = 0;
	for(i=0;i<n;i++){
		cin >> array[i];
		if(array[i] == 0)
			last0 = i;
		else
			last1 = i;
	}
	int ans;
	if(last0 > last1)
		ans = last1 + 1;
	else
		ans = last0 + 1; 
	cout << ans << endl;
	
	return 0;
}
