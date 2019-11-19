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
	cin >> a >> b;

	int ans;

	if(a>=13)
		ans = b;
	else if(a>=6)
		ans = b/2;
	else 
		ans=0;


	cout << ans << endl;
	
	return 0;
}
