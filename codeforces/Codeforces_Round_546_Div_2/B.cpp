#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
	// your code goes here
	int n,k, ans, goLeft = 0;
	cin >> n >> k;

	if(k-1 <= n-k)
		goLeft = 1;

	if(k==1 || k==n)
		ans = 3*n;
	else{
		if(goLeft==1){
			ans = 6 + k - 1 + 3*(n-2);
		}
		else{
			ans = 6 + n - k + 3*(n-2);
		}
	}
	cout << ans << endl;

	return 0;
}