#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

//map <vector<int>, int> m;

int main() {
	// your code goes here
	int a,b,t,l,i,j,minAns=100000000;
	cin >> a >> b >> t;

	int ans = (t/a)*b;


	cout << ans << endl;
	
	return 0;
}
