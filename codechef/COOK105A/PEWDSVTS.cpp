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

int main() {
	// your code goes here
	int t, n, m, k,q, i = 0, u,j, v, ctr;
	double a,b,x,y,z,sum,ans;
	cin >> t;

	while(t!=0){
		cin >> n >> a >> b >> x >> y >> z;

		sum = 0;
		priority_queue <int> contribution;
		for(i=0;i<n;i++){
			cin >> q; 
			contribution.push(q);
			sum+= q;
		}
		ans = 0;
		int days = ceil((z - b) / y) - 1;
		double piedPiper = a + x * days;
		double needed = z - piedPiper;
		//cout << endl << "days = " << days << endl;
		//if(/*2*sum<needed || */days == 0){
		//	ans = -1;
		//}
		//else 
		if(needed <=0){
			ans = 0;
		}  
		else{
			while(needed > 0){
				int current = contribution.top();
				contribution.pop();

				if(current == 0){
					ans = -1;
					break;
				}
				needed -= current;
				ans++;
				//cout << "current = " << current << " needed = " << needed << endl;
				contribution.push(current / 2);
			}	
		}
		if(ans == -1){
			cout << "RIP" << endl;
		}
		else{
			cout << ans << endl;
		}

		t--;
	}



	return 0;
}
	