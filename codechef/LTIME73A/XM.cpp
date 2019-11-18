#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int mod = 1000000007;

bool comparator(const pair<int, int> &a, const pair<int, int> &b){
	return a.second<b.second;
}

int main() {
	// your code goes here
	int t,n,q,temp,d,i,j,l,r;
	int rowNo=0, colNo = 0;
	long ans = 0;
	cin >> t ;
	
	int possible = 1;
	while(t!=0){
		cin  >> n >> q;
		vector <int> array(n);
		for(i=0;i<n;i++)
			cin >> array[i];

		for(i=0;i<q;i++){
			cin >> l >> r;
			l--;r--;
			long long int sum = 0;
			for(j=l;j<=r;j++){
				int temp = array[j]^(j-l);
				sum+=temp;
			}
			cout << sum << endl;
		}
		t--;
	}
	return 0;
}
	