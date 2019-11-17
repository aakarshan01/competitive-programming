#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	// your code goes here
	int n,k, goLeft = 0,i;

	cin >>n;
	long long int a,b;
	vector < pair < int, pair < int,  int > > > input (n);
	
	for(i=0;i<n;i++){
		cin >> a >> b;
		input[i].second = make_pair(a,b);
		input[i].first  = a - b;
	}
	sort(input.begin(), input.end());

	long long int ans = 0;
	for(i=0;i<n;i++){
		a = input[n-i-1].second.first;
		b = input[n-i-1].second.second;
		ans += a*i + b*(n-i-1);
	}
	cout << ans << endl;
	return 0;
}