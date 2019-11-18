#include <iostream>
#include <algorithm>
#include <vector>

#include <set> 
#include <iterator> 
#include <cmath>
//using namespace __gnu_pbds;
using namespace std;
int mod = 1000000007;

bool comparator(const pair<int, int> &a, const pair<int, int> &b){
	return a.second<b.second;
}
  
int main() {
	// your code goes here
	int j,t,n,q,i;
	cin >> t;
	while(t!=0){
		
		string s;
		cin >> s;
		int l = s.length();

		string ans = "";
		int found = 0;
		if(l==1){
			ans = ans + s;
			found = 1;
		}
		else if(s[0] != '1'){
			char temp = s[0] - 1;
			ans = ans + temp;
			for(i=1;i<l;i++){
				if(s[i]!='9')
					found = 1;
				ans = ans + "9";
			}
			if(found==0)
				ans = s;
			found = 1;
		}
		else{
			ans = ans + "1";
			int nonZeroIndex = -1;
			for(i=1;i<l;i++){
				if(s[i]!='0'){
					nonZeroIndex = i;
					break;
				}
			}
			if(nonZeroIndex == -1){
				ans = "";
				for(i=1;i<l;i++){
					ans = ans + "9";
				}
			}
			else if (nonZeroIndex == (l-1)) {
				for(i=1;i<l;i++){
					ans = ans + s[i];
				}
			}
			else{
				for(i=1;i<nonZeroIndex;i++)
					ans = ans + s[i];
				char temp = s[i] - 1;
				ans = ans + temp;

				for(i=nonZeroIndex+1;i<l;i++){
					if(s[i]!='9')
						found = 1;
					ans = ans + "9";
				}
				if(found == 0)
					ans = s;
			}
		}
		cout << ans << endl;
		t--;
	}
	return 0;
}
	