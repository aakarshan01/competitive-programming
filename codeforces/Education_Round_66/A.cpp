#include <iostream>
#include <map>
#include <vector>

using namespace std;

map <vector<int>, int> m;

int main() {
	// your code goes here
	long long int n,k,t;
	cin >> t;
	long long int steps = 0;
	while(t!=0){
		cin >> n >> k;
		steps = 0;

		while(n!=0){
			if(n%k==0){
				n = n / k;
				steps++;
			}
			else{
				long long int temp = n / k;
				long long int temp1 = temp * k;
				
				steps+= n - temp1;
				n = temp1;
			}
			//cout << steps << " n = " << n << endl;
		}

		cout << steps << endl;
		t--;
	}

	return 0;
}