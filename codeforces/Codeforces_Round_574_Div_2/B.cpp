#include <iostream>
#include <map>
#include <vector>
#include <set> 
#include <algorithm> 
#include <cmath>
using namespace std;

int main() {
	// your code goes here
	

	long long int n,k;
	cin >> n >> k;

	long long int num = -3+sqrt(9+8*(n+k));
	long long int ans = num / 2;
	cout << n - ans << endl;
	return 0;
}