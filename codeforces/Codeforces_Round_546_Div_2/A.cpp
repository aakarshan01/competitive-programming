#include <iostream>
#include <map>
#include <vector>

using namespace std;

map <vector<int>, int> m;

int main() {
	// your code goes here
	int i,n,k;
	cin >> n;
	int array[n][2];

	int ans=n;
	for(i=0;i<n;i++){
		cin >> array[i][0] >> array[i][1];
	}
	cin >> k;

	for(i=0;i<n;i++){
		if(array[i][1] >= k){
			break;
		}
		ans--;
	}
	cout << ans << endl;
	
	return 0;
}
