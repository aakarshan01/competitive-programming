#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
long mod = 1000000007;

bool comparator(const pair<int, int> &a, const pair<int, int> &b){
	return a.second<b.second;
}

long long power(long long base, long exponent, int mod){
	long long ans = 1;
	while(exponent > 0){
		//cout << "ans = " << ans << " base = " << base << endl;
		
		if(exponent % 2 == 1){
			ans = (ans * base) % mod;
			exponent--;
		}

		exponent = exponent / 2; 
		base = (base * base) % mod;
	}
	return (ans) % mod;
}

long long gcd(int a, int b){
	if(b == 0)
		return a;
	return gcd (b, a % b);
}

int main() {
	// your code goes here
	int t, n, k, m;
	long long ans = 0;
	//cout << power(2, 11, 7) << endl 
	//cout << power(56, mod - 2, mod) << endl;
	cin >> t ;
	
	while(t!=0){
		cin >> n >> k >> m;
		ans = 0;

		if(m % 2 == 1){
			int exponent = (m + 1) / 2;
			long long numerator = power(n-1, exponent, mod);
			long long denominator = power(n, exponent, mod);
			long long denominatorModularInverse = power(denominator, mod - 2, mod);
			long long product = (numerator * denominatorModularInverse) % mod;
			ans = (1 - product + mod) % mod;

			//cout << "numerator = " << numerator << " denominator = " << denominator << " denominatorModularInverse = " << denominatorModularInverse << " product = " << product << " ans = " << ans <<endl;
		}
		else{
			int exponent = (m) / 2;
			long long numerator = power(n-1, exponent, mod);
			long long denominator = power(n, exponent, mod);
			long long denominatorModularInverse = power(denominator, mod - 2, mod);
			long long product = (numerator * denominatorModularInverse) % mod;
			ans = (1 - product + mod) % mod;

			//cout << "numerator = " << numerator << " denominator = " << denominator << " denominatorModularInverse = " << denominatorModularInverse << " product = " << product << " ans = " << ans <<endl;
			long long tempNumerator = power(n - 1, exponent, mod);
			long long tempDenominator = (power(n, exponent, mod) * (n + k)) % mod;
			//long long tempGCD = gcd(tempNumerator, tempDenominator);
			//tempNumerator = tempNumerator / tempGCD;
			//tempDenominator = tempDenominator / tempGCD;
			long long tempDenominatorModularInverse = power(tempDenominator, mod - 2, mod);
			long long tempProduct = (tempNumerator * tempDenominatorModularInverse) % mod;

			//cout << " tempGC = " << tempGCD << " tempDenominatorModularInverse = " << tempDenominatorModularInverse << " tempProduct = " << tempProduct << endl;
			ans = (ans + tempProduct) % mod;	
		}

		cout << ans << endl;
		t--;
	}
	return 0;
}
	