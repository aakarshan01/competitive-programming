#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

//map <vector<int>, int> m;

int main() {
	// your code goes here
	int l,i,j,minAns=100000000,r,x;
	
	int n,h,m;
	cin >> n >> h >> m;
	int array[n];
	for(i=0;i<n;i++){
		array[i] = h;
	}
	for(i=0;i<m;i++){
		cin >> l >> r >> x;
		l--;r--;
		for(j=l;j<=r;j++){
			array[j] = min(array[j], x);
		}
	}

	int sum = 0;
	for(i=0;i<n;i++){
		sum = sum + array[i]*array[i];
	}
	cout << sum << endl;
	
	return 0;
}
