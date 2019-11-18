#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string.h>
#include <iomanip> 
#include <map>
using namespace std;

map<string, long long int> m;
	
int main() {
	// your code goes here
	
	int t,n,i;
	long long int x,y;
	cin>>t;

	while(t!=0){
		cin >> n;
		vector<long long int> c1(n); // y-x
		vector<long long int> c2(n); // y+x

		for(i=0;i<n;i++){
			cin >> x >> y;

			c1[i] = y-x;
			c2[i] = y+x;
		}
		sort(c1.begin(), c1.end());
		sort(c2.begin(), c2.end());

		long long int min = c1[1] - c1[0];
		int slope = 1;
		long long int r1 = c1[1];
		long long int r2 = c1[0];

		for(i=1;i<n;i++){
			if(c1[i]-c1[i-1]<min){
				min = c1[i]-c1[i-1];
				r1 = c1[i];
				r2 = c1[i-1];
				slope = 1;
			}
			if(c2[i]-c2[i-1]<min){
				min = c2[i]-c2[i-1];
				r1 = c2[i];
				r2 = c2[i-1];
				slope = -1;
			}
		}
		cout << setprecision(6) << abs((float)min/2.0) << endl;

		t--;
	}


	return 0;
}
	