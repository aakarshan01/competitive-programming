#include <iostream>
#include <map>
#include <vector>
#include <set> 
#include <algorithm> 

using namespace std;

int main() {
	// your code goes here
	int cnt=0,t,i,j,n,m,a,b,x,y1,y2=-1,y=-1;
	int zero=0,one=0,two=0;
	cin >> t;

	while(t!=0){
		cin >> n;
		vector<int> array(n);
		zero=0;one=0;two=0;
		int ans = 0;
		for(i=0;i<n;i++){
			cin >> array[i];
			if(array[i]%3==0){
				ans++;
			}
			else if(array[i]%3==1){
				one++;
			}
			else if(array[i]%3==2){
				two++;
			}
		}
		if(one<two){
			ans = ans + one;
			two = two - one;
			ans = ans + two / 3;
		}
		else{
			ans = ans + two;
			one = one - two;
			ans = ans + one / 3;
		}
		cout << ans << endl;
		t--;
	}

	return 0;
}