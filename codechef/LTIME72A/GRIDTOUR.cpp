#include <iostream>
#include <algorithm>
#include <vector>

#include <set> 
#include <iterator> 
#include <cmath>
//using namespace __gnu_pbds;
using namespace std;
int mod = 1000000007;

bool comparator(const pair<int, int> &a, const pair<int, int> &b){
	return a.second<b.second;
}
 
int gcd(int a, int b) 
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b);  
      
} 

int main() {
	// your code goes here
	int t,k;
	long long int n,m;
	cin >> t;
	while(t!=0){
		long long int ans = 0;
		cin >> n >> m >> k;

		if(n==1){
			if(gcd(m,k) > 1)
				ans = -1;
			else
				ans = n*m;

		}
		else if(m==1){
			if(gcd(n,k) > 1)
				ans = -1;
			else
				ans = n*m;

		}
		else{
			if((gcd(n,k) > 1) || (gcd(m,k) > 1)){
				ans = -1;
			}
			else
				ans = n*m;
		
		}
		cout << ans << endl;
		t--;
	}
	return 0;
}
	