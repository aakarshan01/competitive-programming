#include <iostream>
#include <map>
#include <vector>

using namespace std;

map <vector<int>, int> m;

int main() {
	// your code goes here
	int w1,h1,w2,h2;
	cin >> w1 >> h1 >> w2 >> h2 ;
	int ans = 2 * (w1 + h1 + h2) + 4;
	cout << ans << endl;
	return 0;
}
