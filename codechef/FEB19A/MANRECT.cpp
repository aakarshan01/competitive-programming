#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int mod = 1000000007;

bool comparator(const pair<int, int> &a, const pair<int, int> &b){
	return a.second<b.second;
}

int main() {
	// your code goes here
	long t, n = 1000000000,a, b, c, d, x1, y1, x2, y2, temp;
	string s;
	cin >> t ;
	int count = 0;

	while(t!=0){
		//if(count == 0){
		//	while(1){}
		//}
		cout << "Q 0 0" << endl;
		cin >> a;
		cout << "Q " << n << " 0" << endl;
		cin >> b;
		cout << "Q " << n << " " << n << endl;
		cin >> c;
		//cout << "Q 0 " << n << endl;
		//cin >> d;

		double centreXDouble = (a - b + n) / 2.0;
		double centreYDouble = (b - c + n) / 2.0;
		long centreX = centreXDouble;
		long centreY = centreYDouble;

		cout << "Q 0 " << centreY << endl;
		cin >> x1;

		cout << "Q " << centreX << " 0" << endl;
		cin >> y1;


		x2 = ( centreXDouble - x1 / 2.0 ) * 2;
		y2 = ( centreYDouble - y1 / 2.0 ) * 2;

		cout << "A " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
		cin >> temp;

		count++;
		t--;
	}
	return 0;
}
	