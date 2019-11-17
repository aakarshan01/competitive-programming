#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
	// your code goes here
	int n,k, goLeft = 0,i,ans = 1;
	cin >> n;
	string s;
	int l = s.length();
	cin >>s;
	string t = s;

	if(s[0] == ')' || s[l-1] == ')' || s.length() %2 == 1){
		ans = -1;
		cout << ":(" << endl;
		return;
	}

	




	if(ans == -1){
		cout << -1 << endl;
	}
	else{
		cout << endl;
	}

	return 0;
}