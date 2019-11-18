#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string.h>
#include <iomanip> 
#include <map>
using namespace std;

#define MOD 1000000007
map<string, long long int> m;
	
int main() {
	// your code goes here
	
	int t,i;
	long long int n,k;
	cin>>t;

	while(t!=0){
		cin >> n >> k;
		
		long long int ans = 0;

		long long int start = k-1;
		long long int x = start / (n-1);

		long long int temp = 0;

		/*if(x%2==0){
			temp = (((x/2)%MOD)*((x+1)%MOD))%MOD; 
		}
		else
			temp = ((x%MOD)*(((x+1)/2)%MOD))%MOD;	

		cout << "temp = " << temp << endl;
		ans = ((((x+1)%MOD)*(start%MOD))%MOD - (temp*((n-1)%MOD))%MOD)%MOD;*/

		temp = (2*start-(n-1)*(x));
		if(temp%2==0){
			temp = temp /2;
			ans = (((x+1)%MOD) * ((temp)%MOD))%MOD;
		}
		else{
			long long int temp1 = ((x+1)/2)%MOD;
			ans = (temp1 * (temp%MOD)) % MOD;
		}
		 
		cout << ans << endl;
		t--;
	}


	return 0;
}
	