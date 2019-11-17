#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

map <vector<int>, int> m;

int main() {
	// your code goes here
	int n,i,z;
	string initialString, firstStringResult, secondStringResult, thirdStringResult;
	cin >> n >> z;
	vector<int> array(n);
	int matched[n];
	for(i=0;i<n;i++){
		cin >> array[i];
		matched[i]=0;
	}
	sort(array.begin(), array.end());

	int l=0,r=-1;
	for(i=1;i<n;i++){
		if(array[i]-array[l] >= z){
			r=i;
			break;
		}
	}
	if(r==-1){
		cout << 0 << endl;
		return 0;
	}
	int ans = 0;
	while(l<n && r<n){
		cout << "l = " << l << " r = " << r << endl;
		if(n/2 == ans){
			break;
		}
		if(array[r]-array[l]>=z){
			cout << "matched" << endl;
			matched[l]=1;
			matched[r]=1;
			while(l<n && matched[l]==1){
				l++;
			}
			while(r==l || matched[r]==1){
				if(r>=n)
				   break;
				r++;
			}
			ans++;
			
		}
		else{
			matched[l]=1;
			while(l<n && matched[l]==1){
				l++;
			}
			if(l==r){
				while(r==l || matched[r]==1){
					if(r>=n)
						break;
					r++;
				}		
			}
		}
	}
	cout << ans << endl;
	return 0;
}
