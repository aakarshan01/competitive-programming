#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

map <vector<int>, int> m;

int main() {
	// your code goes here
	int n,t,i,z,j,k;
	cin >> t;

	while(t!=0){
		cin >> n >> k;
		int array[n];

		for(i=0;i<n;i++){
			cin >> array[i];
		}
		vector<pair<int,int>> v;
		for(i=0;i<n-k;i++){
			long long int distance = array[i+k] - array[i];
			long long int x = (array[i+k]+array[i])/2;
			v.push_back(make_pair(distance,x));
		}
		sort(v.begin(), v.end());
		cout << v[0].second << endl;
		t--;
	}
	return 0;
}
