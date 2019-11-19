#include <iostream>
#include <map>
#include <vector>
#include <set> 
#include <iterator> 

using namespace std;

int main() {
	// your code goes here
	int ans=0, x,y,z,n;
	register int a,b,c;
	cin >> x >> y >> z >> n;

	for(a=0;a<=3000;a++){
		if(a*x>n)
			break;
		for(b=0;b<=3000;b++){
			if(a*x + b*y > n)
				break;
			int temp = n - a*x - b*y;
			if(temp%z == 0)
				ans++;
		}
	}

	cout << ans << endl;
		
	return 0;
}