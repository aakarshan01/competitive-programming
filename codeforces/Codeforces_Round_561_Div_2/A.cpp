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
	int freqTable[26];
	for(i=0;i<26;i++){
		freqTable[i]=0;
	}

	for(i=0;i<n;i++){
		cin >> s;
		freqTable[s[0]-'a']++;
	}
	for(i=0;i<26;i++){
		int temp1 = freqTable[i] / 2;
		int temp2 = freqTable[i] - temp1;
		ans=ans+(temp1*(temp1-1))/2 + (temp2*(temp2-1))/2;
	}	

	cout << ans << endl;

	return 0;
}
