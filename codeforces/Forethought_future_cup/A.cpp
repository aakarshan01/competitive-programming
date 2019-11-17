#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

//map <vector<int>, int> m;

int main() {
	// your code goes here
	int l,i,j,minAns=100000000;
	string s;
	cin >> s;
	int ctr = 0;
	for(i=0;i<s.length();i++){
		
		if(s[i] == 'a')
			ctr++;
	}

	int ans = 0;
	if(s.length()<2*ctr)
		ans = s.length();
	else
		ans = 2*ctr-1;
	//int sArray[n];
	//int dArray[n];
	
	//vector<pair<int, int>> initial(n);
	
	//sort(initial.begin(), initial.end());


	cout << ans << endl;
	
	return 0;
}
