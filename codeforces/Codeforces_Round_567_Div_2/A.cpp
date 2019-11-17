#include <iostream>
#include <map>
#include <vector>
#include <set> 
#include <algorithm> 

using namespace std;

int main() {
	// your code goes here
	
	long long int x,y,z;
	cin >> x >> y >> z;

	long long int r1 = x%z;
	long long int r2 = y%z;
	long long int ans = 0;
	if(r1+r2<z){
		ans = x/z + y/z;
		cout << ans << " 0" << endl;
	}
	else{
		ans = x/z + y/z + 1;
		if(r1<r2){
			cout << ans << " " << z-r2 << endl;
		}
		else{
			cout << ans << " " << z-r1 << endl;
		}
	}
	return 0;
}