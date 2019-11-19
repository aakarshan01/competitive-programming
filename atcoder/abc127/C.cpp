#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
	// your code goes here
	int i,n,m,l,r;
	cin >> n >> m;
	int leftPtr = 1, rightPtr = n;

	for(i=0;i<m;i++){
		cin >> l >> r;
		leftPtr = max(leftPtr, l);
		rightPtr = min(rightPtr, r);
	}

	int ans = rightPtr - leftPtr + 1;
	if(ans<0)
		ans = 0;
	cout << ans << endl;


	return 0;
}