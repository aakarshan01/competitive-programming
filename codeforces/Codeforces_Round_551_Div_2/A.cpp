#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

map <vector<int>, int> m;

int main() {
	// your code goes here
	int i,n,k,t;
	cin >> n >> t;
	int sArray[n];
	int dArray[n];
	
	vector<pair<int, int>> initial(n);
	for(i=0;i<n;i++){
		cin >> sArray[i];
		cin >> dArray[i];
		sArray[i] = sArray[i] - t;
	}
	for(i=0;i<n;i++){
		if(sArray[i]>=0){
			initial[i].first = sArray[i];
			initial[i].second = i;
		}
		else{
			float temp = ceil(-sArray[i] / (1.0*dArray[i]));
			//cout << sArray[i] << " temp = "  << temp;			
			initial[i].first = temp*dArray[i] + sArray[i];
			initial[i].second = i;
		}
		//cout << initial[i].first << endl;
	}
	sort(initial.begin(), initial.end());


	cout << initial[0].second + 1 << endl;
	
	return 0;
}
