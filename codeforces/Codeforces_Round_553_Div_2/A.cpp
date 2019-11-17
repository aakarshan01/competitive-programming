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
	cin >> l;
	string s;
	cin >> s;

	string genome = "ACTG";
	for(i=0;i<=l-4;i++){
		int temp = 0;
		for(j=0;j<4;j++){
			int sub = (s[i+j] - genome[j] + 26)%26;
			//cout << sub << endl;
			temp = temp + min(sub, 26-sub);

		}
		minAns = min(temp, minAns);
	}
	//int sArray[n];
	//int dArray[n];
	
	//vector<pair<int, int>> initial(n);
	
	//sort(initial.begin(), initial.end());


	cout << minAns << endl;
	
	return 0;
}
