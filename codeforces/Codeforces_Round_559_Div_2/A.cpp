#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

//map <vector<int>, int> m;

int main() {
	// your code goes here
	int l,j,i,minAns=100000000,r,x,ans=0;
	
	int n;
	string s;
	cin >> n;
	cin >> s;
	

	for(i=0;i<n;i++){
		if(s[i]=='+'){
			ans++;
		}
		else{
			ans--;
			if(ans<0)
				ans=0;
		}
	}
	cout << ans << endl;

	return 0;
}
