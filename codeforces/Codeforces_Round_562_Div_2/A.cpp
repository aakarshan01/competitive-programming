#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

//map <vector<int>, int> m;

int main() {
	// your code goes here
	int n,a,b,x,y;
	cin >> n >> a >> x >> b >> y;

	a--;x--;b--;y--;
	int currentA = a;
	int currentB = b;
	int ans = 0;
	while(currentA != x && currentB!= y){
		if(currentA != x)
			currentA = (currentA + 1 + n) % n;
		if(currentB != y)
			currentB = (currentB - 1 + n) % n;
		//cout << currentA << " " << currentB << endl;
		if(currentA == currentB){
			//cout << "station = "<< currentA + 1 << endl;
			ans = 1;
			break;
		}

	}
	if(ans == 1)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	return 0;
}
