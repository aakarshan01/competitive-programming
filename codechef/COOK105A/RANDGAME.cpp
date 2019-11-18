#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;
int mod = 1000000007;

bool comparator(const pair<int, int> &a, const pair<int, int> &b){
	return a.second<b.second;
}


long long int calc(long long int num){

	long long int ans = 0;

	while(num%2 == 0){
		if(num==0)
			break;
		ans++;
		//cout << "yo " << endl;
		num = num / 2;
	}
	return ans;
}
int main() {
	// your code goes here
	int t, m, k,q, i = 0, u,j, v, ctr;
	long long int sub, add;
	cin >> t;
	string s;
	long long int n,x=0;
	while(t!=0){
		x=0;
		cin >> n;
		int end = 0;
		x = calc(n);
		if(x%2 == 1){
			cout << "Lose" << endl;
			cin >> s;
		}
		else{
			cout << "Win" << endl;

			while(end!=-1){
				//cout << " n = " << n << endl;
				if(n%2 == 0){
					cout << "/2" << endl;
					n = n/2;
				}
				else{
					sub = n - 1;
					add = n + 1;

					if(n==1){
						n = n - 1;
						cout << "-1" << endl;
					}
					else if(calc(sub)%2 == 1){
						cout << "-1" << endl;
						n = n-1;
					}
					else{
						cout << "+1" << endl;
						n =n+1;
					}
				}
				cout << " n = " << n << endl;
				cin >> s;
				if(s[0] == '/'){
					n = n/2;
				}
				else if(s[1] == '-'){
					n = n-1;
				}
				else if(s[1] == '+'){
					n = n+1;
				}
				else{
					end = -1;
					break;
				}
				cout << " n = " << n << endl;
			}

		}



		t--;
	}



	return 0;
}
	