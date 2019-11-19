#include <iostream>
#include <map>
#include <vector>
#include <set> 
#include <iterator> 

using namespace std;

int main() {
	// your code goes here
	int d,x,i;
	long long int r;
	cin >> r >> d >> x;

	long long int ans = x;
	
	for(i=1;i<=10;i++){

		ans = r*ans - d;
		cout << ans << endl;
	}
	return 0;
}